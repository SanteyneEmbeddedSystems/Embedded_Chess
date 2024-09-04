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
extern Piece_Meth King_Meth;

#endif
