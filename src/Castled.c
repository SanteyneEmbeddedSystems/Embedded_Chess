#include "Castled.h"

#include "Piece_Protected.h" /* inheritance */


/******************************************************************************/
/** Protected methods implementation **/
/******************************************************************************/
void Move_Castled( Castled* Me, T_Movement_Data* movement )
{
    Move_Piece_Default( (Piece*)Me, movement );
    if( Me->First_Move_Index==NB_RECORDABLE_MOVEMENTS )
    {
        Me->First_Move_Index = movement->move_index;
    }
}
/*----------------------------------------------------------------------------*/
void Undo_Castled_Move( Castled* Me, T_Movement_Data* movement )
{
    Undo_Piece_Move_Default( (Piece*)Me, movement );
    if( Me->First_Move_Index==movement->move_index )
    {
        Me->First_Move_Index = NB_RECORDABLE_MOVEMENTS;
    }
}
/*----------------------------------------------------------------------------*/
uint8_t Get_First_Move_Index( const Castled* Me )
{
    return Me->First_Move_Index;
}
