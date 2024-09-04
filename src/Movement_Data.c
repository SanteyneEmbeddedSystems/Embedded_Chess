#include "Movement_Data.h"

#include <stdlib.h> /* NULL */

T_Movement_Data Create_Movement_Data(
    Piece* moving_piece,
    T_Position initial_position,
    T_Position final_position,
    uint8_t index )
{
    T_Movement_Data result;
    result.moved_piece = moving_piece;
    result.initial_position = initial_position;
    result.final_position = final_position;
    result.captured_piece = NULL;
    result.move_type = NORMAL;
    result.move_index = index;
    result.board_state = INVALID;
    return result;
}
