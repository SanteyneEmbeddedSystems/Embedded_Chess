#ifndef KING_H
#define KING_H

#include "Piece.h"
#include "Position.h"
#include <stdint.h>


/******************************************************************************/
/** Class definition **/
/******************************************************************************/
typedef struct {
    /* Inherit from Piece */
    Piece Super;
    T_Position Current_Position;
    uint8_t First_Move_Index;
} King;


/******************************************************************************/
/** Public methods **/
/******************************************************************************/
T_Position Get_Position( const King* Me );
void Get_Possible_Positions(
    const King* Me,
    T_Position* possible_king_pos,
    int8_t* nb_pos );

extern Piece_Meth King_Meth;

#endif
