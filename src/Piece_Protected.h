#ifndef PIECE_PROTECTED_H
#define PIECE_PROTECTED_H


#include "Piece.h"
#include "stdbool.h"
#include "Position.h"
#include "Movement_Data.h"

typedef  bool (*T_Can_Capture_Func) ( const Piece*, T_Position , T_Position );

bool Is_Piece_Movement_Valid(
    const Piece* Me,
    T_Movement_Data* movement,
    T_Can_Capture_Func capture_func );

bool Can_Capture_Straight(
    T_Rank piece_rank,
    T_File piece_file,
    T_Rank capture_rank,
    T_File capture_file );

bool Can_Capture_Diagonal(
    T_Rank piece_rank,
    T_File piece_file,
    T_Rank capture_rank,
    T_File capture_file );

void Move_Piece_Default(
    Piece* Me,
    T_Movement_Data* movement );

void Undo_Piece_Move_Default(
    Piece* Me,
    T_Movement_Data* movement );

#endif
