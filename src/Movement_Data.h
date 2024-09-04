#ifndef MOVEMENT_DATA_H
#define MOVEMENT_DATA_H

typedef struct _T_Movement_Data T_Movement_Data;


#include "Piece.h"
#include "Position.h"
#include "T_Board_State.h"
#include <stdint.h>


#define NB_RECORDABLE_MOVEMENTS 64

typedef uint8_t T_Move_Type;
#define NORMAL 0
#define H_ROOK_CASTLING 1
#define A_ROOK_CASTLING 2
#define EN_PASSANT 3
#define TWO_SQUARES 4
#define PROMOTION 5

typedef struct _T_Movement_Data {
    Piece* moved_piece;
    Piece* captured_piece;
    T_Position initial_position;
    T_Position final_position;
    uint8_t move_index;
    uint8_t move_type:4;
    uint8_t board_state:4;
} T_Movement_Data;

T_Movement_Data Create_Movement_Data(
    Piece* moving_piece,
    T_Position initial_position,
    T_Position final_position,
    uint8_t index );

#endif
