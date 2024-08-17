#ifndef PAWN_H
#define PAWN_H


#include "Piece.h"


/******************************************************************************/
/** Class definition **/
/******************************************************************************/
typedef struct {
    /* Inherits from Piece */
    Piece Super;
} Pawn;


/******************************************************************************/
/** Public methods **/
/******************************************************************************/



extern Piece_Meth Pawn_Meth;

#endif
