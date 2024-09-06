#ifndef PIECE_PROTECTED_H
#define PIECE_PROTECTED_H


#include "Piece.h"
#include "stdbool.h"
#include "Position.h"
#include "Movement_Data.h"

typedef  bool (*T_Can_Capture_Func) ( const Piece*, T_Position );

bool Is_Piece_Movement_Valid(
    const Piece* Me,
    T_Movement_Data* movement,
    T_Can_Capture_Func capture_func );

void Move_Piece_Default(
    Piece* Me,
    T_Movement_Data* movement );

void Undo_Piece_Move_Default(
    Piece* Me,
    T_Movement_Data* movement );

void Get_Possible_Straight_Positions(
    const Piece* Me,
    T_Position* pos,
    int8_t* nb_pos );

void Get_Possible_Diagonal_Positions(
    const Piece* Me,
    T_Position* pos,
    int8_t* nb_pos );

void Add_Position_If_Free(
    const Piece* Me,
    int8_t* nb_pos,
    T_Position* pos,
    T_Rank rank,
    T_File file );

void Add_Position( int8_t* nb_pos, T_Position* pos, T_Rank rank, T_File file );

#endif
