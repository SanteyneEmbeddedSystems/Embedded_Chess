#include "Bishop.h"


#include "Piece_Protected.h" /* inheritance */
#include "Chessboard_Piece.h" /* association to Chessboard */


/******************************************************************************/
/** Inherited methods implementation **/
/******************************************************************************/
static bool Is_Bishop_Movement_Valid(
    const Bishop* Me,
    T_Movement_Data* movement );

static bool Can_Bishop_Capture_At_Position(
    const Bishop* Me,
    T_Position bishop_position,
    T_Position capture_position);

static char Get_Bishop_Identifier(const Bishop* Me);

/*----------------------------------------------------------------------------*/
Piece_Meth Bishop_Meth = {
    ( bool (*) ( const Piece*, T_Movement_Data* ) ) Is_Bishop_Movement_Valid,
    ( bool (*) ( const Piece*, T_Position, T_Position ) )
        Can_Bishop_Capture_At_Position,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Move_Piece_Default,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Undo_Piece_Move_Default,
    ( char (*) ( const Piece* ) ) Get_Bishop_Identifier
};
/*----------------------------------------------------------------------------*/
static bool Is_Bishop_Movement_Valid(
    const Bishop* Me,
    T_Movement_Data* movement )
{
    return Is_Piece_Movement_Valid(
        (Piece*)Me,
        movement,
        (T_Can_Capture_Func)Can_Bishop_Capture_At_Position );
}
/*----------------------------------------------------------------------------*/
static bool Can_Bishop_Capture_At_Position(
    const Bishop* Me,
    T_Position bishop_position,
    T_Position capture_position)
{
    (void)Me; /* unused parameter */
    T_Rank bishop_rank = Get_Rank(bishop_position);
    T_File bishop_file = Get_File(bishop_position);
    T_Rank capture_rank = Get_Rank(capture_position);
    T_File capture_file = Get_File(capture_position);
    return Can_Capture_Diagonal(
        bishop_rank,bishop_file,capture_rank,capture_file);
}
/*----------------------------------------------------------------------------*/
static char Get_Bishop_Identifier( const Bishop* Me )
{
    (void)Me; /* unused parameter */
    return('B');
}
