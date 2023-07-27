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
