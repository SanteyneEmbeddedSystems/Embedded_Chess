#ifndef BOARD_H
#define BOARD_H


#include "Movement_Data.h"
#include "Piece.h"
#include "King.h"
#include "Rook.h"


/******************************************************************************/
/** Class definition **/
/******************************************************************************/
typedef struct {
    T_Movement_Data Movements[NB_RECORDABLE_MOVEMENTS];
    Piece* Pieces[8][8];
    Piece* White_Pieces[16];
    Piece* Black_Pieces[16];
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
