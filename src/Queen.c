#include "Queen.h"
#include "Queen_Protected.h"


#include "Piece_Protected.h" /* inheritance */
#include "Chessboard_Piece.h" /* association to Chessboard */


/******************************************************************************/
/** Inherited methods implementation **/
/******************************************************************************/
Piece_Meth Queen_Meth = {
    ( bool (*) ( const Piece*, T_Movement_Data* ) ) Is_Queen_Movement_Valid,
    ( bool (*) ( const Piece*, T_Position ) ) Can_Queen_Capture_At_Position,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Move_Piece_Default,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Undo_Piece_Move_Default,
    ( char (*) ( const Piece* ) ) Get_Queen_Identifier,
    ( void (*) ( const Piece*, T_Position*, int8_t* ) )
        Get_Possible_Queen_Positions,
    ( int8_t (*) ( const Piece* ) ) Get_Queen_Score
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
bool Can_Queen_Capture_At_Position( const Queen* Me, T_Position position )
{
    T_Position possible_pos[27];
    int8_t nb_pos;
    Get_Possible_Queen_Positions( Me, possible_pos, &nb_pos );
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
char Get_Queen_Identifier( const Queen* Me )
{
    (void)Me; /* unused parameter */
    return('Q');
}
/*----------------------------------------------------------------------------*/
void Get_Possible_Queen_Positions(
    const Queen* Me,
    T_Position* pos,
    int8_t* nb_pos )
{
    Get_Possible_Straight_Positions( (Piece*)Me, pos, nb_pos );

    T_Position diag_pos[13] = {0};
    int8_t nb_diag_pos = -1;
    Get_Possible_Diagonal_Positions( (Piece*) Me, diag_pos, &nb_diag_pos );

    for( int8_t idx = 0 ; idx<=nb_diag_pos ; idx++ )
    {
        pos[ *nb_pos + 1 + idx ] = diag_pos[idx];
    }
    *nb_pos = *nb_pos + nb_diag_pos + 1;
}
/*----------------------------------------------------------------------------*/
int8_t Get_Queen_Score( const Queen* Me )
{
    (void)Me; /* unused parameter */
    return 9;
}
