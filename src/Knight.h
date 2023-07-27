#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"


/******************************************************************************/
/** Class definition **/
/******************************************************************************/
typedef struct {
    /* Inherit from Piece */
    Piece Super;
} Knight;


/******************************************************************************/
/** Public methods **/
/******************************************************************************/
extern Piece_Meth Knight_Meth;


#endif // KNIGHT_H
