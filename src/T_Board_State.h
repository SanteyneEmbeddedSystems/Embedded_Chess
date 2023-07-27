#ifndef T_BOARD_STATE_H
#define T_BOARD_STATE_H

#include <stdint.h>

typedef uint8_t T_Board_State;

#define INVALID         0
#define ON_GOING        1
#define WHITE_CHECK     2
#define WHITE_CHECKMATE 3
#define BLACK_CHECK     4
#define BLACK_CHECKMATE 5
#define STALEMATE       6


#endif
