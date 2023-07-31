#include "Rook.h"


#include "Piece_Protected.h" /* inheritance */
#include "Chessboard_Piece.h" /* association to Chessboard */


/******************************************************************************/
/** Public methods **/
/******************************************************************************/
bool Has_Rook_Moved( const Rook* Me )
{
    if( Me->First_Move_Index==NB_RECORDABLE_MOVEMENTS )
    {
        return false;
    }
    else
    {
        return true;
    }
}


/******************************************************************************/
/** Inherited methods implementation **/
/******************************************************************************/
static bool Is_Rook_Movement_Valid(
    const Rook* Me,
    T_Movement_Data* movement );

static bool Can_Rook_Capture_At_Position(
    const Rook* Me,
    T_Position rook_position,
    T_Position capture_position);

static void Move_Rook( Rook* Me, T_Movement_Data* movement );
static void Undo_Rook_Move( Rook* Me, T_Movement_Data* movement );

static char Get_Rook_Identifier(const Rook* Me);

/*----------------------------------------------------------------------------*/
Piece_Meth Rook_Meth = {
    ( bool (*) ( const Piece*, T_Movement_Data* ) ) Is_Rook_Movement_Valid,
    ( bool (*) ( const Piece*, T_Position, T_Position ) )
        Can_Rook_Capture_At_Position,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Move_Rook,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Undo_Rook_Move,
    ( char (*) ( const Piece* ) )Get_Rook_Identifier
};
/*----------------------------------------------------------------------------*/
static bool Is_Rook_Movement_Valid(
    const Rook* Me,
    T_Movement_Data* movement )
{
    return Is_Piece_Movement_Valid(
        (Piece*)Me,
        movement,
        (T_Can_Capture_Func)Can_Rook_Capture_At_Position );
}
/*----------------------------------------------------------------------------*/
static bool Can_Rook_Capture_At_Position(
    const Rook* Me,
    T_Position rook_position,
    T_Position capture_position)
{
    (void)Me; /* unused parameter */
    T_Rank rook_rank = Get_Rank(rook_position);
    T_File rook_file = Get_File(rook_position);
    T_Rank capture_rank = Get_Rank(capture_position);
    T_File capture_file = Get_File(capture_position);
    return Can_Capture_Straight(rook_rank,rook_file,capture_rank,capture_file);
}
/*----------------------------------------------------------------------------*/
static void Move_Rook( Rook* Me, T_Movement_Data* movement )
{
    if( Me->First_Move_Index==NB_RECORDABLE_MOVEMENTS )
    {
        Me->First_Move_Index = movement->move_index;
    }
}
/*----------------------------------------------------------------------------*/
static void Undo_Rook_Move( Rook* Me, T_Movement_Data* movement )
{
    if( Me->First_Move_Index==movement->move_index )
    {
        Me->First_Move_Index = NB_RECORDABLE_MOVEMENTS;
    }
}
/*----------------------------------------------------------------------------*/
static char Get_Rook_Identifier( const Rook* Me )
{
    (void)Me; /* unused parameter */
    return('R');
}
