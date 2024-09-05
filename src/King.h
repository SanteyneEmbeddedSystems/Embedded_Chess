#ifndef KING_H
#define KING_H

#include "Piece.h"
#include "Position.h"
#include <stdint.h>


/******************************************************************************/
/** Class definition **/
/******************************************************************************/
typedef struct {
    /* Inherits from Piece */
    Piece Super;
    uint8_t First_Move_Index;
} King;


/******************************************************************************/
/** Public methods **/
/******************************************************************************/
void Get_Possible_King_Positions_In_Check(
    const King* Me,
    T_Position* pos,
    int8_t* nb_pos );

extern Piece_Meth King_Meth;

#endif
