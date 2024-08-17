#include "Debug_Controller.h"

#include "Board_Management.h"
#include "Debug_Viewer.h"

#include "stdbool.h"
#include <stdio.h>
#include <stdlib.h>


static bool Treat_Command(
    char* command,
    char* start_file,
    char* start_rank,
    char* end_file,
    char* end_rank );

static T_Position Create_Position_From_Chars( char file, char rank );


void Play( void )
{
    bool is_command_valid = false;
    char command[5];

    char start_file = 'a';
    char start_rank = '1';
    char end_file = 'h';
    char end_rank = '8';

    T_Position start_position;
    T_Position end_position;

    Display_Board();
    T_Board_State state;
    do
    {
        while(is_command_valid==false)
        {
            Ask_For_Command(command);
            if( command[0]=='u' && command[1]=='n'
               && command[2]=='d' && command[3]=='o' )
            {
                is_command_valid = true;
            }
            else if( command[0]=='q' && command[1]=='u'
               && command[2]=='i' && command[3]=='t' )
            {
                is_command_valid = true;
            }
            else
            {
                is_command_valid = Treat_Command(
                    command,
                    &start_file,
                    &start_rank,
                    &end_file,
                    &end_rank );
            }

        }
        if( command[0]=='u' && command[1]=='n'
            && command[2]=='d' && command[3]=='o' )
        {
            Undo_Last_Move();
        }
        else if( command[0]=='q' && command[1]=='u'
               && command[2]=='i' && command[3]=='t' )
        {
            break;
        }
        else
        {
            start_position = Create_Position_From_Chars(
                start_file,
                start_rank );
            end_position = Create_Position_From_Chars( end_file, end_rank );
            Move_Piece_On_Board( start_position, end_position );
        }
        is_command_valid = false;
        Display_Board();
        state = Get_State();
    } while( BLACK_CHECKMATE!=state
            && WHITE_CHECKMATE!=state
            && STALEMATE!=state );

    getchar();
}


static bool Treat_Command(
    char* command,
    char* start_file,
    char* start_rank,
    char* end_file,
    char* end_rank )
{
    bool is_valid = true;

    if(command[0] >= 'a' && command[0] <= 'h' )
    {
        *start_file = command[0];
    }
    else
    {
        is_valid = false;
    }

    if(command[1] >= '1' && command[1] <= '8' )
    {
        *start_rank = command[1];
    }
    else
    {
        is_valid = false;
    }

    if(command[2] >= 'a' && command[2] <= 'h' )
    {
        *end_file = command[2];
    }
    else
    {
        is_valid = false;
    }

    if(command[3] >= '1' && command[3] <= '8' )
    {
        *end_rank = command[3];
    }
    else
    {
        is_valid = false;
    }



    return is_valid;
}


static T_Position Create_Position_From_Chars( char file, char rank )
{
    T_Position result;

    switch( file )
    {
        case 'a' :
            result.file = FILE_A;
            break;
        case 'b' :
            result.file = FILE_B;
            break;
        case 'c' :
            result.file = FILE_C;
            break;
        case 'd' :
            result.file = FILE_D;
            break;
        case 'e' :
            result.file = FILE_E;
            break;
        case 'f' :
            result.file = FILE_F;
            break;
        case 'g' :
            result.file = FILE_G;
            break;
        case 'h' :
            result.file = FILE_H;
            break;
        default :

            break;
    }
    switch( rank )
    {
        case '1' :
            result.rank = RANK_1;
            break;
        case '2' :
            result.rank = RANK_2;
            break;
        case '3' :
            result.rank = RANK_3;
            break;
        case '4' :
            result.rank = RANK_4;
            break;
        case '5' :
            result.rank = RANK_5;
            break;
        case '6' :
            result.rank = RANK_6;
            break;
        case '7' :
            result.rank = RANK_7;
            break;
        case '8' :
            result.rank = RANK_8;
            break;
        default :

            break;
    }
    return result;
}
