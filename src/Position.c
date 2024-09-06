#include "Position.h"


T_Position Create_Position( T_Rank rank, T_File file )
{
    T_Position result;
    result.file = file;
    result.rank = rank;
    return result;
}

T_Rank Get_Rank( T_Position position )
{
    return position.rank;
}

T_File Get_File( T_Position position )
{
    return position.file;
}

bool Are_Positions_Equal( T_Position pos1, T_Position pos2 )
{
    if( pos1.file==pos2.file && pos1.rank==pos2.rank )
    {
        return true;
    }
    else
    {
        return false;
    }
}
