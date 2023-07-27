#include "Knight.h"

#include <stdlib.h> /* NULL */

#include "Chessboard_Piece.h"
#include "Piece_Protected.h"


/******************************************************************************/
/** Inherited methods implementation **/
/******************************************************************************/
static bool Is_Knight_Movement_Valid(
    const Knight* Me,
    T_Movement_Data* movement );

static bool Can_Knight_Capture_At_Position(
    const Knight* Me,
    T_Position knight_position,
    T_Position capture_position);

static char Get_Knight_Identifier(const Knight* Me);

/*----------------------------------------------------------------------------*/
Piece_Meth Knight_Meth = {
    ( bool (*) ( const Piece*, T_Movement_Data* ) )Is_Knight_Movement_Valid,
    ( bool (*) (const Piece*, T_Position, T_Position ) )
        Can_Knight_Capture_At_Position,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Move_Piece_Default,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Undo_Piece_Move_Default,
    ( char (*) ( const Piece* ) ) Get_Knight_Identifier
};
/*----------------------------------------------------------------------------*/
static bool Is_Knight_Movement_Valid(
    const Knight* Me,
    T_Movement_Data* movement )
{
    return Is_Piece_Movement_Valid(
        (Piece*)Me,
        movement,
        (T_Can_Capture_Func)Can_Knight_Capture_At_Position );
}
/*----------------------------------------------------------------------------*/
static bool Can_Knight_Capture_At_Position(
    const Knight* Me,
    T_Position knight_position,
    T_Position capture_position)
{
    (void)Me; /* unused parameter */

    T_Rank knight_rank = Get_Rank(knight_position);
    T_File knight_file = Get_File(knight_position);

    T_Rank capture_rank = Get_Rank(capture_position);
    T_File capture_file = Get_File(capture_position);

    int8_t diff_rank = (int8_t)knight_rank-(int8_t)capture_rank;
    int8_t diff_file = (int8_t)knight_file-(int8_t)capture_file;

    if( ((2==diff_rank || -2==diff_rank ) && (1==diff_file || -1==diff_file))
       || ((2==diff_file || -2==diff_file ) && (1==diff_rank || -1==diff_rank))
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
static char Get_Knight_Identifier( const Knight* Me )
{
    (void)Me; /* unused parameter */
    return('N');
}
