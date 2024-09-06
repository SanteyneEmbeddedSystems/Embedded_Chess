#include "King.h"

#include <stdlib.h> /* NULL */

#include "Piece_Protected.h" /* inheritance */
#include "Chessboard_King.h" /* association to Chessboard */

/******************************************************************************/
/** Private methods definition **/
/******************************************************************************/
typedef uint8_t E_CASTLING_ALLOWED;
#define NOT_ALLOWED 0
#define KING_SIDE_ALLOWED 1
#define QUEEN_SIDE_ALLOWED 2
#define BOTH_SIDE_ALLOWED 3
static E_CASTLING_ALLOWED Is_Castling_Allowed( const King* Me );


/******************************************************************************/
/** Public methods implementation **/
/******************************************************************************/
void Get_Possible_King_Positions_In_Check(
    const King* Me,
    T_Position* pos,
    int8_t* nb_pos )
{
    T_Position my_pos = Get_Position( (Piece*)Me );
    T_Rank current_rank = Get_Rank(my_pos);
    T_File current_file = Get_File(my_pos);
    *nb_pos = -1;
    if( current_file > FILE_A )
    {
        if( current_rank < RANK_8 )
        {
            Add_Position_If_Free(
                (Piece*)Me, nb_pos, pos, current_rank+1, current_file-1 );
        }
        Add_Position_If_Free(
            (Piece*)Me, nb_pos, pos, current_rank, current_file-1 );
        if( current_rank > RANK_1 )
        {
            Add_Position_If_Free(
                (Piece*)Me, nb_pos, pos, current_rank-1, current_file-1 );
        }
    }
    if( current_file < FILE_H )
    {
        if( current_rank < RANK_8 )
        {
            Add_Position_If_Free(
                (Piece*)Me, nb_pos, pos, current_rank+1, current_file+1 );
        }
        Add_Position_If_Free(
            (Piece*)Me, nb_pos, pos, current_rank, current_file+1 );
        if( current_rank > RANK_1 )
        {
            Add_Position_If_Free(
                (Piece*)Me, nb_pos, pos, current_rank-1, current_file+1 );
        }
    }
    if( current_rank < RANK_8 )
    {
        Add_Position_If_Free(
            (Piece*)Me, nb_pos, pos, current_rank+1, current_file );
    }
    if( current_rank > RANK_1 )
    {
        Add_Position_If_Free(
            (Piece*)Me, nb_pos, pos, current_rank-1, current_file );
    }
}


/******************************************************************************/
/** Inherited methods implementation **/
/******************************************************************************/
static bool Is_King_Movement_Valid(
    const King* Me,
    T_Movement_Data* movement );

static bool Can_King_Capture_At_Position( const King* Me, T_Position position );

static void Move_King( King* Me, T_Movement_Data* movement );

static void Undo_King_Move( King* Me, T_Movement_Data* movement);

static char Get_King_Identifier(const King* Me);

static void Get_Possible_King_Positions(
    const King* Me,
    T_Position* pos,
    int8_t* nb_pos );

static int8_t Get_King_Score( const King* Me );

/*----------------------------------------------------------------------------*/
Piece_Meth King_Meth = {
    ( bool (*) ( const Piece*, T_Movement_Data* ) ) Is_King_Movement_Valid,
    ( bool (*) ( const Piece*, T_Position ) ) Can_King_Capture_At_Position,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Move_King,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Undo_King_Move,
    ( char (*) ( const Piece* ) ) Get_King_Identifier,
    ( void (*) ( const Piece*, T_Position*, int8_t* ) )
        Get_Possible_King_Positions,
    ( int8_t (*) ( const Piece* ) ) Get_King_Score
};
/*----------------------------------------------------------------------------*/
static bool Is_King_Movement_Valid(
    const King* Me,
    T_Movement_Data* movement )
{
    bool result = false;

    T_Position initial_pos = movement->initial_position;
    T_Position final_pos = movement->final_position;

    result = Can_King_Capture_At_Position( Me, final_pos );
    if(true==result)
    {
        movement->move_type = NORMAL;
        return result;
    }

    /* Treat castling. */
    T_Color king_color = Get_Color((Piece*)Me);
    T_Rank required_king_rank = RANK_1;
    if( BLACK==king_color )
    {
        required_king_rank = RANK_8;
    }
    if( Get_Rank(initial_pos)==required_king_rank
       && Get_Rank(final_pos)==required_king_rank )
    {
        if( Get_File(initial_pos)==FILE_E )
        {
            bool king_side_requested = false;
            bool queen_side_requested = false;
            if( Get_File(final_pos)==FILE_G )
            {
                king_side_requested = true;
            }
            if( Get_File(initial_pos)==FILE_E && Get_File(final_pos)==FILE_C )
            {
                queen_side_requested = true;
            }
            if( true==king_side_requested || true==queen_side_requested )
            {
                E_CASTLING_ALLOWED castling_allowed = Is_Castling_Allowed(Me);
                if( true==king_side_requested &&
                    ( castling_allowed==KING_SIDE_ALLOWED
                        || castling_allowed==BOTH_SIDE_ALLOWED ) )
                {
                    result = true;
                    movement->move_type = H_ROOK_CASTLING;
                }
                else if( castling_allowed==QUEEN_SIDE_ALLOWED
                            || castling_allowed==BOTH_SIDE_ALLOWED )
                {
                    result = true;
                        movement->move_type = A_ROOK_CASTLING;
                }
            }
        }
    }
    return result;
}
/*----------------------------------------------------------------------------*/
static bool Can_King_Capture_At_Position( const King* Me, T_Position position )
{
    T_Position my_pos = Get_Position((Piece*)Me);
    /* Get file variation */
    uint8_t diff_file= 0;
    T_File king_file = Get_File(my_pos);
    T_File capture_file = Get_File(position);
    if( king_file > capture_file )
    {
        diff_file = king_file - capture_file;
    }
    else
    {
        diff_file = capture_file - king_file;
    }

    /* Get rank variation */
    uint8_t diff_rank = 0;
    T_Rank king_rank = Get_Rank(my_pos);
    T_Rank capture_rank = Get_Rank(position);
    if( king_rank > capture_rank )
    {
        diff_rank = king_rank - capture_rank;
    }
    else
    {
        diff_rank = capture_rank - king_rank;
    }

    /* Check if rank or file has varied from at most 1 */
    /* ( assume that king position != capture_position ) */
    if( diff_file<=1 && diff_rank<=1 )
    {
        return true;
    }
    else
    {
        return false;
    }
}
/*----------------------------------------------------------------------------*/
static void Move_King( King* Me, T_Movement_Data* movement )
{
    Move_Piece_Default( (Piece*)Me, movement );
    if( Me->First_Move_Index==NB_RECORDABLE_MOVEMENTS )
    {
        Me->First_Move_Index = movement->move_index;
    }
}
/*----------------------------------------------------------------------------*/
static void Undo_King_Move( King* Me, T_Movement_Data* movement )
{
    Undo_Piece_Move_Default( (Piece*)Me, movement );
    if( Me->First_Move_Index==movement->move_index )
    {
        Me->First_Move_Index=NB_RECORDABLE_MOVEMENTS;
    }
}
/*----------------------------------------------------------------------------*/
static char Get_King_Identifier(const King* Me)
{
    (void)Me; /* unused parameter */
    return('K');
}
/*----------------------------------------------------------------------------*/
static void Get_Possible_King_Positions(
    const King* Me,
    T_Position* pos,
    int8_t* nb_pos )
{
    Get_Possible_King_Positions_In_Check( Me, pos, nb_pos );

    T_Rank my_rank = RANK_1;
    if( BLACK==Get_Color((Piece*)Me) )
    {
        my_rank = RANK_8;
    }
    switch( Is_Castling_Allowed(Me) )
    {
        case NOT_ALLOWED:
            break;
        case KING_SIDE_ALLOWED:
            Add_Position( nb_pos, pos, my_rank, FILE_G );
            break;
        case QUEEN_SIDE_ALLOWED:
            Add_Position( nb_pos, pos, my_rank, FILE_C );
            break;
        case BOTH_SIDE_ALLOWED:
            Add_Position( nb_pos, pos, my_rank, FILE_G );
            Add_Position( nb_pos, pos, my_rank, FILE_C );
            break;
    }
}
/*----------------------------------------------------------------------------*/
static int8_t Get_King_Score( const King* Me )
{
    (void)Me; /* unused parameter */
    return 0;
}


/******************************************************************************/
/** Private methods implementation**/
/******************************************************************************/
static E_CASTLING_ALLOWED Is_Castling_Allowed( const King* Me )
{
    E_CASTLING_ALLOWED result = NOT_ALLOWED;

    T_Color king_color = Get_Color((Piece*)Me);
    /* Verify that king is not check and has not already moved. */
    /* Verify final rank */
    T_Board_State chessboard_state = Get_State();
    if( NB_RECORDABLE_MOVEMENTS==Me->First_Move_Index
       && ( ( king_color==WHITE && chessboard_state!=WHITE_CHECK )
           || ( king_color==BLACK && chessboard_state!=BLACK_CHECK ) )
      )
    {
        T_Rank king_rank = RANK_1;
        T_Color opponent_color = BLACK;
        T_Position final_pos;
        if( BLACK==king_color )
        {
            king_rank = RANK_8;
            opponent_color = WHITE;
        }
        T_Position pass_through_position;

        /* Test castling with H rook (King side). */
        /* Verify that H rook has not moved. */
        if ( false==Has_Rook_Already_Moved( king_color, FILE_H ) )
        {
            /* Check there are no piece between the king and the rook.*/
            if( Get_Piece( king_rank, FILE_F )==NULL &&
                Get_Piece( king_rank, FILE_G )==NULL )
            {
                /* Verify the king does not pass through or finish on a
                square attacked by an enemy piece */
                pass_through_position = Create_Position(king_rank,FILE_F);
                final_pos = Create_Position(king_rank,FILE_G);
                if( Is_Position_Capturable(
                        pass_through_position, opponent_color)==false
                   && Is_Position_Capturable(
                        final_pos, opponent_color)==false )
                {
                    result = KING_SIDE_ALLOWED;
                }
            }
        }

        /* Castling with A rook (Queen side). */
        if ( false==Has_Rook_Already_Moved( king_color, FILE_A ) )
        {
            /* Check there are no piece between the king and the rook.*/
            if( Get_Piece( king_rank, FILE_D )==NULL &&
                Get_Piece( king_rank, FILE_C )==NULL )
            {
                /* Verify the king does not pass through or finish on a
                square attacked by an enemy piece */
                pass_through_position = Create_Position(king_rank,FILE_D);
                final_pos = Create_Position(king_rank,FILE_C);
                if( Is_Position_Capturable(
                        pass_through_position, opponent_color)==false
                   && Is_Position_Capturable(
                        final_pos, opponent_color)==false )
                {
                    if( result==KING_SIDE_ALLOWED )
                    {
                        result = BOTH_SIDE_ALLOWED;
                    }
                    else
                    {
                        result = QUEEN_SIDE_ALLOWED;
                    }
                }
            }
        }
    }
    return result;
}
