#ifndef ROOK_H
#define ROOK_H

#include "Castled.h"
#include <stdbool.h>


/******************************************************************************/
/** Class definition **/
/******************************************************************************/
typedef struct {
    /* Inherits from Castled */
    Castled Super;
} Rook;


/******************************************************************************/
/** Public methods **/
/******************************************************************************/
bool Has_Rook_Moved( const Rook* Me );


extern Piece_Meth Rook_Meth;

#endif

