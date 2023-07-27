#ifndef CHESSBOARD_PIECE_H
#define CHESSBOARD_PIECE_H

#include "Position.h"
#include "Piece.h"

#define NB_RECORDABLE_MOVEMENTS 64

Piece* Get_Piece_By_Rank_And_File( T_Rank rank, T_File file );
Piece* Get_Piece_By_Position( T_Position position );

#endif // CHESSBOARD_PIECE_H
