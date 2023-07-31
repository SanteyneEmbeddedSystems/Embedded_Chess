#ifndef QUEEN_PROTECTED_H
#define QUEEN_PROTECTED_H

#include "Queen.h"
#include <stdbool.h>
#include "Movement_Data.h"
#include "Position.h"


bool Is_Queen_Movement_Valid(
    const Queen* Me,
    T_Movement_Data* movement );

bool Can_Queen_Capture_At_Position(
    const Queen* Me,
    T_Position queen_position,
    T_Position capture_position);

char Get_Queen_Identifier(const Queen* Me);

#endif
