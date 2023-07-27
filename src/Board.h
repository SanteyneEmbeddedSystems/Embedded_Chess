#ifndef BOARD_H
#define BOARD_H

#include "Color.h"
#include "Position.h"
#include "Piece.h"
#include "King.h"
#include "Rook.h"
#include "T_Board_State.h"


/******************************************************************************/
/** Class definition **/
/******************************************************************************/

#define NB_RECORDABLE_MOVEMENTS 64

typedef struct {
    T_Movement_Data Movements[NB_RECORDABLE_MOVEMENTS];
    Piece* Pieces[8][8];
    King* White_King;
    King* Black_King;
    Rook* White_A_Rook;
    Rook* White_H_Rook;
    Rook* Black_A_Rook;
    Rook* Black_H_Rook;
    uint8_t Nb_Movements;
} Board;


/******************************************************************************/
/** Public methods **/
/******************************************************************************/


#endif
