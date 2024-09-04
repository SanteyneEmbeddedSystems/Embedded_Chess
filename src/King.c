#include "King.h"

#include <stdlib.h> /* NULL */

#include "Piece_Protected.h" /* inheritance */
#include "Chessboard_King.h" /* association to Chessboard */


/******************************************************************************/
/** Public methods implementation**/
/******************************************************************************/



/******************************************************************************/
/** Inherited methods implementation **/
/******************************************************************************/
static bool Is_King_Movement_Valid(
    const King* Me,
    T_Movement_Data* movement );

static bool Can_King_Capture_At_Position(
    const King* Me,
    T_Position king_position,
    T_Position capture_position);

static void Move_King( King* Me, T_Movement_Data* movement );

static void Undo_King_Move( King* Me, T_Movement_Data* movement);

static char Get_King_Identifier(const King* Me);

static void Get_Possible_King_Positions(
    const King* Me,
    T_Position* pos,
    int8_t* nb_pos );

/*----------------------------------------------------------------------------*/
Piece_Meth King_Meth = {
    ( bool (*) ( const Piece*, T_Movement_Data* ) ) Is_King_Movement_Valid,
    ( bool (*) ( const Piece*, T_Position, T_Position ) )
        Can_King_Capture_At_Position,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Move_King,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Undo_King_Move,
    ( char (*) ( const Piece* ) ) Get_King_Identifier,
    ( void (*) ( const Piece*, T_Position*, int8_t* ) )
        Get_Possible_King_Positions
};
/*----------------------------------------------------------------------------*/
static bool Is_King_Movement_Valid(
    const King* Me,
    T_Movement_Data* movement )
{
    bool result = false;

    T_Position initial_pos = movement->initial_position;
    T_Position final_pos = movement->final_position;

    result = Can_King_Capture_At_Position( Me, initial_pos, final_pos );
    if(true==result)
    {
        movement->move_type = NORMAL;
        return result;
    }

    /* Treat castling. */
    T_Color king_color = Get_Color((Piece*)Me);
    /* Verify that king is not check and has not already moved. */
    /* Verify final rank */
    T_Board_State chessboard_state = Get_State();
    T_Rank final_rank = Get_Rank(final_pos);
    if( NB_RECORDABLE_MOVEMENTS==Me->First_Move_Index
       && ( ( king_color==WHITE && chessboard_state!=WHITE_CHECK )
           || ( king_color==BLACK && chessboard_state!=BLACK_CHECK ) )
       && ( ( king_color==WHITE && final_rank==RANK_1 )
           || ( king_color==BLACK && final_rank==RANK_8 ) )
      )
    { /* King is on e file. */
        T_Rank king_rank = RANK_1;
        T_Color opponent_color = BLACK;
        if( BLACK==king_color )
        {
            king_rank = RANK_8;
            opponent_color = WHITE;
        }
        T_Position pass_through_position;
        T_File final_file = Get_File(final_pos);
        if( FILE_G==final_file )
        { /* Castling with H rook. */
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
                    if( Is_Position_Capturable(
                            pass_through_position, opponent_color)==false
                       && Is_Position_Capturable(
                            final_pos, opponent_color)==false )
                    {
                        result = true;
                        movement->move_type = H_ROOK_CASTLING;
                    }
                }
            }
        }
        else if( FILE_C==final_file )
        { /* Castling with A rook. */
            if ( false==Has_Rook_Already_Moved( king_color, FILE_A ) )
            {
                /* Check there are no piece between the king and the rook.*/
                if( Get_Piece( king_rank, FILE_D )==NULL &&
                    Get_Piece( king_rank, FILE_C )==NULL )
                {
                    /* Verify the king does not pass through or finish on a
                    square attacked by an enemy piece */
                    pass_through_position = Create_Position(king_rank,FILE_D);
                    if( Is_Position_Capturable(
                            pass_through_position, opponent_color)==false
                       && Is_Position_Capturable(
                            final_pos, opponent_color)==false )
                    {
                        result = true;
                        movement->move_type = A_ROOK_CASTLING;
                    }
                }
            }
        }
    }

    return result;
}
/*----------------------------------------------------------------------------*/
static bool Can_King_Capture_At_Position(
    const King* Me,
    T_Position king_position,
    T_Position capture_position )
{
    (void)Me; /* unused parameter */

    /* Get file variation */
    uint8_t diff_file= 0;
    T_File king_file = Get_File(king_position);
    T_File capture_file = Get_File(capture_position);
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
    T_Rank king_rank = Get_Rank(king_position);
    T_Rank capture_rank = Get_Rank(capture_position);
    if( king_rank > capture_rank )
    {
        diff_rank = king_rank - capture_rank;
    }
    else
    {
        diff_rank = capture_rank - king_rank;
    }

    /* Check if rank or file has varied from at most 1 */
    /* ( assume that king_position != capture_position ) */
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
    if( Me->First_Move_Index==NB_RECORDABLE_MOVEMENTS )
    {
        Me->First_Move_Index = movement->move_index;
    }
    Me->Super.Position = movement->final_position;
}
/*----------------------------------------------------------------------------*/
static void Undo_King_Move( King* Me, T_Movement_Data* movement )
{
    if( Me->First_Move_Index==movement->move_index )
    {
        Me->First_Move_Index=NB_RECORDABLE_MOVEMENTS;
    }
    Me->Super.Position = movement->initial_position;
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
    T_Rank current_rank = Me->Super.Position.rank;
    T_File current_file = Me->Super.Position.file;
    *nb_pos = -1;
    if( current_file > FILE_A )
    {
        if( current_rank < RANK_8 )
        {
            (*nb_pos)++;
            pos[*nb_pos] = Create_Position(current_rank+1,current_file-1);
        }
        (*nb_pos)++;
        pos[*nb_pos] = Create_Position(current_rank,current_file-1);
        if( current_rank > RANK_1 )
        {
            (*nb_pos)++;
            pos[*nb_pos] = Create_Position(current_rank-1,current_file-1);
        }
    }
    if( current_file < FILE_H )
    {
        if( current_rank < RANK_8 )
        {
            (*nb_pos)++;
            pos[*nb_pos] = Create_Position(current_rank+1,current_file+1);
        }
        (*nb_pos)++;
        pos[*nb_pos] = Create_Position(current_rank,current_file+1);
        if( current_rank > RANK_1 )
        {
            (*nb_pos)++;
            pos[*nb_pos] = Create_Position(current_rank-1,current_file+1);
        }
    }
    if( current_rank < RANK_8 )
    {
        (*nb_pos)++;
        pos[*nb_pos] = Create_Position(current_rank+1,current_file);
    }
    if( current_rank > RANK_1 )
    {
        (*nb_pos)++;
        pos[*nb_pos] = Create_Position(current_rank-1,current_file);
    }
}
