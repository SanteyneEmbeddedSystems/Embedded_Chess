extern "C" {
    #include "Board_Management.h"
}

void setup( void )
{
    Serial.begin(9600);
    while (!Serial) {
    }
    Serial.println("Serial communication ready");
}

void loop( void )
{
    bool is_command_valid = false;
    String command;
    
    char start_file = 'a';
    char start_rank = '1';
    char end_file = 'h';
    char end_rank = '8';

    T_Position start_position = { .rank = RANK_3, .file = FILE_H };
    T_Position end_position = { .rank = RANK_5, .file = FILE_A };

    while(is_command_valid==false)
    {
        command = Ask_For_Command();
        Serial.println(command);
        if( command[0]=='u' && command[1]=='n'
           && command[2]=='d' && command[3]=='o' )
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
        Serial.println("Undo_Last_Move");
    }
    else if( command[0]=='p' && command[1]=='l'
           && command[2]=='a' && command[3]=='y' )
    {
        int16_t eval = 0;
        eval = Find_Best_Move( 4, &start_position, &end_position );
        Move_Piece_On_Board( start_position, end_position );
        Serial.print("IA plays : ");
        Serial.write(start_position.file+97);
        Serial.print(start_position.rank+1);
        Serial.print('-');
        Serial.write(end_position.file+97);
        Serial.print(end_position.rank+1);
        Serial.println("");

    }
    else
    {
        start_position = Create_Position_From_Chars(
            start_file,
            start_rank );
        end_position = Create_Position_From_Chars( end_file, end_rank );
        Move_Piece_On_Board( start_position, end_position );
        Serial.print("Human plays : ");
        Serial.write(start_position.file+97);
        Serial.print(start_position.rank+1);
        Serial.print('-');
        Serial.write(end_position.file+97);
        Serial.print(end_position.rank+1);
        Serial.println("");
    }
    is_command_valid = false;
}

String Ask_For_Command( void )
{
    Serial.print("Enter movement : ");
    while (Serial.available() == 0)
    {
      /* wait for data available */
    }     
    String command = Serial.readString();
    command.trim();
    return command;
}


bool Treat_Command(
    String command,
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

T_Position Create_Position_From_Chars( char file, char rank )
{
    T_Position result;
    result.file = file-97;
    result.rank = rank-1;
    return result;
}
