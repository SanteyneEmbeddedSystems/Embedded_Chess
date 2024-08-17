#ifndef CHESSBOARD_PIECE_H
#define CHESSBOARD_PIECE_H

#include "Position.h"
#include "Piece.h"


Piece* Get_Piece( T_Rank rank, T_File file );
Piece* Get_Piece_By_Position( T_Position position );

#endif
