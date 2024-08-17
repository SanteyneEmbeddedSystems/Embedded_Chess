#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
#include <stdbool.h>


/******************************************************************************/
/** Class definition **/
/******************************************************************************/
typedef struct {
    /* Inherits from Piece */
    Piece Super;
    uint8_t First_Move_Index;
} Rook;


/******************************************************************************/
/** Public methods **/
/******************************************************************************/
bool Has_Rook_Moved( const Rook* Me );


extern Piece_Meth Rook_Meth;

#endif

