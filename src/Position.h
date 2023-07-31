#ifndef POSITION_H
#define POSITION_H

#include <stdint.h>

typedef uint8_t T_Rank;
#define RANK_1 0
#define RANK_2 1
#define RANK_3 2
#define RANK_4 3
#define RANK_5 4
#define RANK_6 5
#define RANK_7 6
#define RANK_8 7


typedef uint8_t T_File;
#define FILE_A 0
#define FILE_B 1
#define FILE_C 2
#define FILE_D 3
#define FILE_E 4
#define FILE_F 5
#define FILE_G 6
#define FILE_H 7


typedef struct {
    uint8_t rank:3;
    uint8_t file:3;
} T_Position;

T_Position Create_Position( T_Rank rank, T_File file );

T_Rank Get_Rank( T_Position position );
T_File Get_File( T_Position position );

#endif
