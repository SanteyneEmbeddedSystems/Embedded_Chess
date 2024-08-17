#include "Queen.h"
#include "Queen_Protected.h"


#include "Piece_Protected.h" /* inheritance */
#include "Chessboard_Piece.h" /* association to Chessboard */


/******************************************************************************/
/** Inherited methods implementation **/
/******************************************************************************/
Piece_Meth Queen_Meth = {
    ( bool (*) ( const Piece*, T_Movement_Data* ) ) Is_Queen_Movement_Valid,
    ( bool (*) ( const Piece*, T_Position, T_Position ) )
        Can_Queen_Capture_At_Position,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Move_Piece_Default,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Undo_Piece_Move_Default,
    ( char (*) ( const Piece* ) ) Get_Queen_Identifier
};
/*----------------------------------------------------------------------------*/
bool Is_Queen_Movement_Valid(
    const Queen* Me,
    T_Movement_Data* movement )
{
    return Is_Piece_Movement_Valid(
        (Piece*)Me,
        movement,
        (T_Can_Capture_Func)Can_Queen_Capture_At_Position );
}
/*----------------------------------------------------------------------------*/
bool Can_Queen_Capture_At_Position(
    const Queen* Me,
    T_Position queen_position,
    T_Position capture_position)
{
    (void)Me; /* unused parameter */
    T_Rank queen_rank = Get_Rank(queen_position);
    T_File queen_file = Get_File(queen_position);
    T_Rank capture_rank = Get_Rank(capture_position);
    T_File capture_file = Get_File(capture_position);

    if( true==Can_Capture_Straight(
                queen_rank, queen_file, capture_rank, capture_file )
       || true==Can_Capture_Diagonal(
                    queen_rank, queen_file, capture_rank, capture_file ) )
    {
        return true;
    }
    else
    {
        return false;
    }

}
/*----------------------------------------------------------------------------*/
char Get_Queen_Identifier( const Queen* Me )
{
    (void)Me; /* unused parameter */
    return('Q');
}

