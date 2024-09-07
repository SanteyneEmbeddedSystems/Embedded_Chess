#include "Debug_Controller.h"

#include "Board_Management.h"
#include "Debug_Viewer.h"

#include "stdbool.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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
    while(1)
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
            else if( command[0]=='p' && command[1]=='l'
               && command[2]=='a' && command[3]=='y' )
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
        else if( command[0]=='p' && command[1]=='l'
               && command[2]=='a' && command[3]=='y' )
        {
            int16_t eval;
            time_t begin = time( NULL );
            if( WHITE==Get_Current_Player() )
            {
                eval = Find_Best_Move( 1, &start_position, &end_position );
            }
            else
            {
                eval = Find_Best_Move( 4, &start_position, &end_position );
            }
            time_t end = time( NULL);
            unsigned long secondes = (unsigned long) difftime( end, begin );
            Move_Piece_On_Board( start_position, end_position );
            printf("IA plays : %c%u-%c%u in %ld s for %i\n",
                   start_position.file+97,
                   start_position.rank+1,
                   end_position.file+97,
                   end_position.rank+1,
                   secondes,
                   eval);
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
    };
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
    result.file = file-97;
    result.rank = rank-1;
    return result;
}
