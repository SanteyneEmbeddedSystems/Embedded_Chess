#ifndef QUEEN_PROTECTED_H
#define QUEEN_PROTECTED_H

#include "Queen.h"
#include <stdbool.h>
#include "Movement_Data.h"
#include "Position.h"


bool Is_Queen_Movement_Valid(
    const Queen* Me,
    T_Movement_Data* movement );

bool Can_Queen_Capture_At_Position( const Queen* Me, T_Position position );

char Get_Queen_Identifier(const Queen* Me);

void Get_Possible_Queen_Positions(
    const Queen* Me,
    T_Position* pos,
    int8_t* nb_pos );

int8_t Get_Queen_Score( const Queen* Me );

#endif
