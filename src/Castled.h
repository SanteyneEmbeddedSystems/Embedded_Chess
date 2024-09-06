#ifndef CASTLED_H
#define CASTLED_H

#include "Piece.h"  /* inheritance */


/******************************************************************************/
/** Class definition **/
/******************************************************************************/
typedef struct {
    /* Inherits from Piece */
    Piece Super;
    uint8_t First_Move_Index;
} Castled;


/******************************************************************************/
/** Protected methods **/
/******************************************************************************/
void Move_Castled( Castled* Me, T_Movement_Data* movement );
void Undo_Castled_Move( Castled* Me, T_Movement_Data* movement );
uint8_t Get_First_Move_Index( const Castled* Me );

#endif
