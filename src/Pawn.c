#include "Pawn.h"

#include <stdlib.h> /* NULL */

#include "Chessboard_Pawn.h"
#include "Piece_Protected.h"
#include "Queen_Protected.h"


/******************************************************************************/
/** Private methods declaration **/
/******************************************************************************/
/* Assume that it is a pawn capture movement. */
static bool Is_En_Passant(
    const Pawn* Me,
    T_Position pawn_position,
    T_Position final_position );


/******************************************************************************/
/** Public methods implementation **/
/******************************************************************************/



/******************************************************************************/
/** Inherited methods implementation **/
/******************************************************************************/
static bool Is_Pawn_Movement_Valid(
    const Pawn* Me,
    T_Movement_Data* movement );
static bool Can_Pawn_Capture_At_Position(
    const Pawn* Me,
    T_Position pawn_position,
    T_Position capture_position);
static void Move_Pawn( Pawn* Me, T_Movement_Data* movement );
static void Undo_Promoted_Pawn_Move( Pawn* Me, T_Movement_Data* movement);
static char Get_Pawn_Identifier(const Pawn* Me);

/*----------------------------------------------------------------------------*/
Piece_Meth Pawn_Meth = {
    ( bool (*) ( const Piece*, T_Movement_Data* ) ) Is_Pawn_Movement_Valid,
    ( bool (*) ( const Piece*, T_Position, T_Position ) )
        Can_Pawn_Capture_At_Position,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Move_Pawn,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Undo_Piece_Move_Default,
    ( char (*) ( const Piece* ) ) Get_Pawn_Identifier
};
/*----------------------------------------------------------------------------*/
Piece_Meth Promoted_Pawn_Meth = {
    ( bool (*) ( const Piece*, T_Movement_Data* ) ) Is_Queen_Movement_Valid,
    ( bool (*) ( const Piece*, T_Position, T_Position ) )
        Can_Queen_Capture_At_Position,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Move_Piece_Default,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Undo_Promoted_Pawn_Move,
    ( char (*) ( const Piece* ) ) Get_Queen_Identifier
};
/*----------------------------------------------------------------------------*/
static bool Is_Pawn_Movement_Valid(
    const Pawn* Me,
    T_Movement_Data* movement )
{
    bool result = false;

    movement->move_type = NORMAL;

    T_Color pawn_color = Get_Color((Piece*)Me);
    T_Position initial_pos = movement->initial_position;
    T_Position final_pos = movement->final_position;

    /* Treat capture */
    Piece* captured_piece = Get_Piece_By_Position(final_pos);
    if( Can_Pawn_Capture_At_Position(Me, initial_pos, final_pos) )
    {
        /* "Normal" capture */
        /* Verify that there is a piece at final_position. */
        if( NULL!=captured_piece )
        {
            /* Verify that the piece is an opponent. */
            if( Get_Color(captured_piece)!=pawn_color )
            {
                result = true;
                movement->move_type = NORMAL;
            }
        }
        /* En passant */
        else if( true==Is_En_Passant(Me, initial_pos, final_pos ) )
        {
            result = true;
            movement->move_type = EN_PASSANT;
        }
    }

    /* Treat movement */
    T_Rank final_rank = Get_Rank(final_pos);
    if( false==result && NULL==captured_piece)
    {
        /* No capture */
        movement->move_type = NORMAL;
        T_File final_file = Get_File(initial_pos);
        if( Get_File(final_pos) == final_file )
        {

            T_Rank initial_rank = Get_Rank(initial_pos);
            switch( pawn_color )
            {
                case WHITE:
                    if( initial_rank==RANK_2 && final_rank==RANK_4 )
                    {
                        Piece* front_piece = Get_Piece_By_Rank_And_File(
                            RANK_3,
                            final_file);
                        if( NULL==front_piece )
                        {
                            movement->move_type = TWO_SQUARES;
                            result = true;
                        }
                    }
                    else if( (final_rank-initial_rank)==1 )
                    {
                        result = true;
                    }
                    break;
                case BLACK:
                    if( initial_rank==RANK_7 && final_rank==RANK_5 )
                    {
                        Piece* front_piece = Get_Piece_By_Rank_And_File(
                            RANK_6,
                            final_file);
                        if( NULL==front_piece )
                        {
                            movement->move_type = TWO_SQUARES;
                            result = true;
                        }
                    }
                    else if( (initial_rank-final_rank)==1 )
                    {
                        result = true;
                    }
                    break;
            }
        }
    }

    /* Verify Promotion */
    if( (WHITE==pawn_color && RANK_8==final_rank)
       || (BLACK==pawn_color && RANK_1==final_rank) )
    {
        movement->move_type = PROMOTION;
    }

    return result;
}
/*----------------------------------------------------------------------------*/
static bool Can_Pawn_Capture_At_Position(
    const Pawn* Me,
    T_Position pawn_position,
    T_Position capture_position )
{
    T_Color pawn_color = Get_Color((Piece*)Me);
    T_Rank capture_rank = Get_Rank(capture_position);
    T_File capture_file = Get_File(capture_position);
    T_Rank pawn_rank = Get_Rank(pawn_position);
    T_File pawn_file = Get_File(pawn_position);

    if(   ( capture_file==pawn_file+1 || capture_file==pawn_file-1 )
       && (
            ( (pawn_rank+1)==capture_rank && pawn_color==WHITE )
            ||
            ( (pawn_rank-1)==capture_rank && pawn_color==BLACK )
          )
      )
    {
        return true;
    }
    else
    {
        return false;
    }
}
/*----------------------------------------------------------------------------*/
static void Move_Pawn( Pawn* Me, T_Movement_Data* movement )
{
    if( PROMOTION==movement->move_type )
    {
        Me->Super.Virtual_Methods = &Promoted_Pawn_Meth;
    }
}
/*----------------------------------------------------------------------------*/
static void Undo_Promoted_Pawn_Move( Pawn* Me, T_Movement_Data* movement)
{
    if( PROMOTION==movement->move_type )
    {
        Me->Super.Virtual_Methods = &Pawn_Meth;
    }
}
/*----------------------------------------------------------------------------*/
static char Get_Pawn_Identifier(const Pawn* Me)
{
    (void)Me; /* unused parameter */
    return('P');
}


/******************************************************************************/
/** Private methods implementation **/
/******************************************************************************/
static bool Is_En_Passant(
    const Pawn* Me,
    T_Position initial_position,
    T_Position final_position )
{
    T_Color pawn_color = Get_Color((Piece*)Me);
    T_Rank opponent_rank;

    /* Verify initial position and set the theoretical rank of the
    opponent pawn. */
    T_Rank initial_rank = Get_Rank(initial_position);
    if( WHITE==pawn_color && RANK_5==initial_rank )
    {
        opponent_rank = RANK_5;
    }
    else if( BLACK==pawn_color && RANK_4==initial_rank )
    {
        opponent_rank = RANK_4;
    }
    else
    {
        return false;
    }

    /* Verify that there is a piece at en passant capture position. */
    T_File final_file =  Get_File(final_position);
    Piece* captured_piece;
    captured_piece = Get_Piece_By_Rank_And_File( opponent_rank, final_file );
    if( NULL!=captured_piece )
    {
        /* Verify that the piece is capturable. */
        T_Movement_Data* last_move = Get_Last_Move();
        if( NULL!=last_move )
        {
            if( last_move->moved_piece==captured_piece
                && last_move->move_type==TWO_SQUARES )
            {
                return true;
            }
        }
    }
    return false;
}
