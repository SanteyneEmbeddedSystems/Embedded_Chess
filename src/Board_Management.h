#ifndef BOARD_MANAGEMENT_H
#define BOARD_MANAGEMENT_H

#include "T_Board_State.h"
#include "Position.h"
#include "Color.h"
#include "Piece.h"

T_Board_State Move_Piece_On_Board(
    T_Position initial_position,
    T_Position final_postion );

T_Board_State Undo_Last_Move(void);

T_Board_State Get_State(void);

T_Color Get_Current_Player(void);

Piece* Get_Piece_By_Rank_And_File( T_Rank rank, T_File file );

#endif // BOARD_MANAGEMENT_H
