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
    T_Position position);

static char Get_Bishop_Identifier(const Bishop* Me);

static void Get_Possible_Bishop_Positions(
    const Bishop* Me,
    T_Position* pos,
    int8_t* nb_pos );

static int8_t Get_Bishop_Score( const Bishop* Me );

/*----------------------------------------------------------------------------*/
Piece_Meth Bishop_Meth = {
    ( bool (*) ( const Piece*, T_Movement_Data* ) ) Is_Bishop_Movement_Valid,
    ( bool (*) ( const Piece*, T_Position ) ) Can_Bishop_Capture_At_Position,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Move_Piece_Default,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Undo_Piece_Move_Default,
    ( char (*) ( const Piece* ) ) Get_Bishop_Identifier,
    ( void (*) ( const Piece*, T_Position*, int8_t* ) )
        Get_Possible_Bishop_Positions,
    ( int8_t (*) ( const Piece* ) ) Get_Bishop_Score
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
    T_Position position)
{
    T_Position possible_pos[13];
    int8_t nb_pos;
    Get_Possible_Diagonal_Positions( (Piece*)Me, possible_pos, &nb_pos );
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
static char Get_Bishop_Identifier( const Bishop* Me )
{
    (void)Me; /* unused parameter */
    return('B');
}
/*----------------------------------------------------------------------------*/
static void Get_Possible_Bishop_Positions(
    const Bishop* Me,
    T_Position* pos,
    int8_t* nb_pos )
{
    Get_Possible_Diagonal_Positions( (Piece*) Me, pos, nb_pos );
}
/*----------------------------------------------------------------------------*/
static int8_t Get_Bishop_Score( const Bishop* Me )
{
    (void)Me; /* unused parameter */
    return 3;
}
