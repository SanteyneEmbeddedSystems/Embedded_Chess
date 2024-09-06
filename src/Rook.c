#include "Rook.h"


#include "Piece_Protected.h" /* inheritance */

#include "Chessboard_Piece.h" /* association to Chessboard */


/******************************************************************************/
/** Public methods **/
/******************************************************************************/
bool Has_Rook_Moved( const Rook* Me )
{
    if( Get_First_Move_Index( (Castled*)Me )==NB_RECORDABLE_MOVEMENTS )
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

static bool Can_Rook_Capture_At_Position( const Rook* Me, T_Position position );

static char Get_Rook_Identifier(const Rook* Me);

static void Get_Possible_Rook_Positions(
    const Rook* Me,
    T_Position* pos,
    int8_t* nb_pos );

static int8_t Get_Rook_Score( const Rook* Me );

/*----------------------------------------------------------------------------*/
Piece_Meth Rook_Meth = {
    ( bool (*) ( const Piece*, T_Movement_Data* ) ) Is_Rook_Movement_Valid,
    ( bool (*) ( const Piece*, T_Position ) ) Can_Rook_Capture_At_Position,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Move_Castled,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Undo_Castled_Move,
    ( char (*) ( const Piece* ) )Get_Rook_Identifier,
    ( void (*) ( const Piece*, T_Position*, int8_t* ) )
        Get_Possible_Rook_Positions,
    ( int8_t (*) ( const Piece* ) ) Get_Rook_Score
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
static bool Can_Rook_Capture_At_Position( const Rook* Me, T_Position position )
{
    T_Position possible_pos[14];
    int8_t nb_pos;
    Get_Possible_Straight_Positions( (Piece*)Me, possible_pos, &nb_pos );
    for( int8_t pos_idx = 0 ; pos_idx<=nb_pos ; pos_idx++ )
    {
        if( true==Are_Positions_Equal( position, possible_pos[pos_idx] ) )
       {
           return true;
       }
    }
    return false;
}
/*----------------------------------------------------------------------------*/
static char Get_Rook_Identifier( const Rook* Me )
{
    (void)Me; /* unused parameter */
    return('R');
}
/*----------------------------------------------------------------------------*/
static void Get_Possible_Rook_Positions(
    const Rook* Me,
    T_Position* pos,
    int8_t* nb_pos )
{
    Get_Possible_Straight_Positions( (Piece*)Me, pos, nb_pos );
}
/*----------------------------------------------------------------------------*/
static int8_t Get_Rook_Score( const Rook* Me )
{
    (void)Me; /* unused parameter */
    return 5;
}
