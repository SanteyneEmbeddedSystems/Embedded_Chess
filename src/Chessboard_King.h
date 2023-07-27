#ifndef CHESSBOARD_KING_H
#define CHESSBOARD_KING_H

#include "Chessboard_Piece.h" /* Inheritance */

#include "T_Board_State.h"




/* Return true is the piece at position is captureable by the player_color */
bool Is_Position_Capturable( T_Position position, T_Color player_color );

bool Has_Rook_Already_Moved( T_Color rook_color, T_File rook_file );

T_Board_State Get_State(void);

#endif
