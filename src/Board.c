#include "Board.h"


/******************************************************************************/
/** Inclusions **/
/******************************************************************************/
/* Utilities */
#include <stdlib.h> /* NULL */

/* Realized interfaces */
#include "Board_Management.h"
#include "Chessboard_Piece.h"
#include "Chessboard_King.h"
#include "Chessboard_Pawn.h"


/******************************************************************************/
/** Singleton declaration **/
/******************************************************************************/
Board Chessboard;


/******************************************************************************/
/** Private methods definition **/
/******************************************************************************/
static T_Board_State Compute_Board_Status( void );
static bool Is_Check( T_Color player_color );
static bool Is_Checkmate( T_Color player_color );
static T_Position Get_King_Position( T_Color king_color );
static const King* Get_King( T_Color king_color );
static void Set_Piece( Piece* new_piece, T_Position position );
static T_Board_State Update_Check_Status( T_Color player_color );
static bool Is_King_Check_After_Move(
    T_Color player_color,
    const King* player_king,
    T_Position player_king_position );
static bool Is_King_Check_After_Capture(
    T_Color player_color,
    T_Position checking_piece_position );
static void Get_Interception_Positions(
    T_Position king_pos,
    T_Position piece_pos,
    T_Position* interception_positions,
    int8_t* nb_pos );
static bool Is_Kink_Check_After_Interception(
    T_Color player_color,
    T_Position king_position,
    T_Position checking_piece_position );

static void Do_Castling(
    T_Move_Type move_type,
    T_Rank rook_rank,
    bool undo );


/* Perform movement without verifying/updating Kings status. */
static void Try_Move( T_Movement_Data* movement );

/* Cancel a Try_Move */
static void Cancel_Move( T_Movement_Data* movement );


/******************************************************************************/
/** Public methods implementation **/
/******************************************************************************/
T_Movement_Data* Get_Last_Move( void )
{
    uint8_t idx = Chessboard.Nb_Movements;
    if( idx >=1 )
    {
        return &(Chessboard.Movements[idx-1]);
    }
    else
    {
        return NULL;
    }
}
/*----------------------------------------------------------------------------*/
T_Board_State Get_State(void)
{
    uint8_t idx = Chessboard.Nb_Movements;
    if( idx >=1 )
    {
        return Chessboard.Movements[idx-1].board_state;
    }
    else
    {
        return ON_GOING; /* Initial state before first move */
    }
}
/*----------------------------------------------------------------------------*/
T_Color Get_Current_Player(void)
{
    return ((Chessboard.Nb_Movements)%2)==0 ? WHITE : BLACK;
}
/*----------------------------------------------------------------------------*/
Piece* Get_Piece_By_Rank_And_File( T_Rank rank, T_File file )
{
    return Chessboard.Pieces[rank][file];
}
/*----------------------------------------------------------------------------*/
Piece* Get_Piece_By_Position( T_Position position )
{
    return Chessboard.Pieces[Get_Rank(position)][Get_File(position)];
}
/*----------------------------------------------------------------------------*/
T_Board_State Move_Piece_On_Board(
    T_Position initial_position,
    T_Position final_position )
{
    T_Color current_player = Get_Current_Player();
    Piece* moving_piece = Get_Piece_By_Position( initial_position );

    /*------------------------------------------------------------------------*/
    /* Perform quick test on the validity of the move regarding moving piece
    and piece at destination. */
    /* Check color of the piece on initial position. */
    if( NULL==moving_piece )
    {
        /* No piece on initial position. */
        return INVALID;
    }
    else
    {
        if( Get_Color( moving_piece ) != current_player )
        {
            return INVALID;
        }
    }
    /* Check the color of the piece on final position. */
    Piece* destination_piece = Get_Piece_By_Position( final_position );
    if( NULL!=destination_piece )
    {
        if( Get_Color( destination_piece ) == current_player )
        {
            return INVALID;
        }
    }

    /*------------------------------------------------------------------------*/
    /* Analyze the move */
    T_Movement_Data movement = Create_Movement_Data(
        moving_piece,
        initial_position,
        final_position,
        Chessboard.Nb_Movements );
    bool is_allowed = Is_Movement_Valid( moving_piece, &movement );


    /*------------------------------------------------------------------------*/
    /* Perform the move */
    if( true==is_allowed )
    {
        Try_Move( &movement );
    }
    else
    {
        return INVALID;
    }

    /*------------------------------------------------------------------------*/
    /* Get the status of the chessboard after the move */
    T_Board_State move_status = Compute_Board_Status();

    /* Check if current player is check */
    if( ( ( move_status==WHITE_CHECK || move_status==WHITE_CHECKMATE )
         && WHITE==current_player )
       || ( (move_status==BLACK_CHECK || move_status==BLACK_CHECKMATE )
         && BLACK==current_player)
      )
    {
        Cancel_Move( &movement );
        return INVALID;
    }
    else
    {
        /* Validate the move */
        Move_Piece( moving_piece, &movement  );

        /* Store the board status */
        movement.board_state = move_status;

        /* Store the movement */
        Chessboard.Movements[Chessboard.Nb_Movements] = movement;
        (Chessboard.Nb_Movements)++;

        return move_status;
    }
}
/*----------------------------------------------------------------------------*/
bool Has_Rook_Already_Moved( T_Color rook_color, T_File rook_file )
{
    const Rook* rook = NULL;
    if( WHITE==rook_color )
    {
        if( FILE_A==rook_file )
        {
            rook = Chessboard.White_A_Rook;
        }
        else if( FILE_H==rook_file )
        {
            rook = Chessboard.White_H_Rook;
        }
    }
    else if( BLACK==rook_color )
    {
        if( FILE_A==rook_file )
        {
            rook = Chessboard.Black_A_Rook;
        }
        else if( FILE_H==rook_file )
        {
            rook = Chessboard.Black_H_Rook;
        }
    }
    return Has_Rook_Moved(rook);
}
/*----------------------------------------------------------------------------*/
bool Is_Position_Capturable( T_Position position, T_Color player_color )
{
    for( T_Rank rank = RANK_1 ; rank<= RANK_8 ; rank++ )
    {
        for( T_File file = FILE_A ; file <= FILE_H ; file++ )
        {
            Piece* current_piece = Get_Piece_By_Rank_And_File(rank,file);
            if( current_piece!=NULL )
            {
                if( Get_Color(current_piece)==player_color )
                {
                    T_Position current_position = Create_Position(rank,file);
                    if( true==Can_Capture_At_Position(
                        current_piece,
                        current_position,
                        position) )
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
/*----------------------------------------------------------------------------*/
T_Board_State Undo_Last_Move(void)
{
    T_Board_State undo_status;
    uint8_t idx = Chessboard.Nb_Movements;

    if( 0!=idx )
    {
        T_Movement_Data movement = Chessboard.Movements[idx-1];
        Cancel_Move( &movement );
        (Chessboard.Nb_Movements)--;
    }
    else
    {
        undo_status = INVALID;
    }

    return undo_status;
}
/*----------------------------------------------------------------------------*/


/******************************************************************************/
/** Private methods implementation */
/******************************************************************************/
static T_Board_State Compute_Board_Status( void )
{
    T_Board_State current_status = ON_GOING;
    T_Color current_player = Get_Current_Player();
    if( true==Is_Check(current_player) )
    {
        current_status = Update_Check_Status(current_player);
    }
    else
    {
        T_Color opponent_color = BLACK;
        if( BLACK==current_player )
        {
            opponent_color = WHITE;
        }
        if( true==Is_Check(opponent_color) )
        {
            current_status = Update_Check_Status(opponent_color);
        }
        else
        {
            current_status = ON_GOING;
        }
    }
    return current_status;
}
/*----------------------------------------------------------------------------*/
static bool Is_Check( T_Color player_color )
{
    T_Color opponent_color = BLACK;
    T_Position player_king_position;
    if( BLACK==player_color )
    {
        opponent_color = WHITE;
    }
    player_king_position = Get_King_Position( player_color );
    return Is_Position_Capturable( player_king_position ,opponent_color);
}
/*----------------------------------------------------------------------------*/
static bool Is_Checkmate( T_Color player_color )
{
    T_Position player_king_position;
    player_king_position = Get_King_Position( player_color );
    const King* player_king = Get_King( player_color );

    /* Count nb of pieces setting in check */
    T_Position checking_piece_position;
    uint8_t nb_checking_pieces = 0;
    for( T_Rank rank = RANK_1 ; rank<= RANK_8 ; rank++ )
    {
        for( T_File file = FILE_A ; file <= FILE_H ; file++ )
        {
            Piece* current_piece = Get_Piece_By_Rank_And_File(rank,file);
            if( current_piece!=NULL )
            {
                if( Get_Color(current_piece)!=player_color )
                {
                    T_Position current_position = Create_Position(rank,file);
                    if( true==Can_Capture_At_Position(
                        current_piece,
                        current_position,
                        player_king_position) )
                    {
                        nb_checking_pieces++;
                        checking_piece_position = current_position;
                    }
                }
            }
        }
    }

    if( nb_checking_pieces>=2 )
    { /* Two (or more) pieces setting in check */
        return Is_King_Check_After_Move(
            player_color,
            player_king,
            player_king_position);
    }
    else
    { /* Only on piece setting in check */
        /* Try to move King */
        if( false==Is_King_Check_After_Move(
                player_color,
                player_king,
                player_king_position) )
        {
            return false;
        }
        else if( false==Is_King_Check_After_Capture(
                    player_color,
                    checking_piece_position ))
        {
            return false;
        }
        else
        {
            return Is_Kink_Check_After_Interception(
                player_color,
                player_king_position,
                checking_piece_position );
        }
    }
}
/*----------------------------------------------------------------------------*/
static T_Position Get_King_Position( T_Color king_color )
{
    if(WHITE==king_color)
    {
        return Get_Position(Chessboard.White_King);
    }
    else
    {
        return Get_Position(Chessboard.Black_King);
    }
}
/*----------------------------------------------------------------------------*/
static const King* Get_King( T_Color king_color )
{
    if(WHITE==king_color)
    {
        return Chessboard.White_King;
    }
    else
    {
        return Chessboard.Black_King;
    }
}
/*----------------------------------------------------------------------------*/
static void Set_Piece( Piece* new_piece, T_Position position )
{
    Chessboard.Pieces[Get_Rank(position)][Get_File(position)] = new_piece;
}
/*----------------------------------------------------------------------------*/
static T_Board_State Update_Check_Status( T_Color player_color )
{
    T_Board_State player_status = ON_GOING;
    if( true==Is_Checkmate(player_color) )
    {
        switch( player_color )
        {
            case WHITE:
                player_status = WHITE_CHECKMATE;
                break;
            case BLACK:
                player_status = BLACK_CHECKMATE;
                break;
        }
    }
    else
    {
        switch( player_color )
        {
            case WHITE:
                player_status = WHITE_CHECK;
                break;
            case BLACK:
                player_status = BLACK_CHECK;
                break;
        }
    }
    return player_status;
}
/*----------------------------------------------------------------------------*/
static void Try_Move( T_Movement_Data* movement )
{
    /* Capture */
    if( movement->move_type==EN_PASSANT )
    {
        T_Position en_passant_pos;
        en_passant_pos = Create_Position(
            Get_Rank(movement->initial_position),
            Get_File(movement->final_position) );
        movement->captured_piece = Get_Piece_By_Position( en_passant_pos );
        Set_Piece( NULL, en_passant_pos );
    }
    else
    {
        movement->captured_piece =
            Get_Piece_By_Position(movement->final_position);
    }

    /* Move piece */
    Set_Piece( movement->moved_piece, movement->final_position );
    Set_Piece( NULL, movement->initial_position );
    Move_Piece( movement->moved_piece, movement );

    /* Perform additional move (castling). */
    Do_Castling(
        movement->move_type,
        Get_Rank(movement->initial_position),
        false );
}
/*----------------------------------------------------------------------------*/
static void Cancel_Move( T_Movement_Data* movement )
{
    /* Undo the piece move */
    Set_Piece( movement->moved_piece, movement->initial_position );
    Set_Piece( NULL, movement->final_position );

    /* Undo the additional move (castling). */
    Do_Castling(
        movement->move_type,
        Get_Rank(movement->initial_position),
        true );

    /* Undo the capture */
    if( movement->move_type==EN_PASSANT )
    {
        T_Position en_passant_pos;
        en_passant_pos = Create_Position(
            Get_Rank(movement->initial_position),
            Get_File(movement->final_position) );
        Set_Piece( movement->captured_piece, en_passant_pos );
    }
    else
    {
        Set_Piece( movement->captured_piece, movement->final_position );
    }

    Undo_Piece_Move( movement->moved_piece, movement );
}
/*----------------------------------------------------------------------------*/
static bool Is_King_Check_After_Move(
    T_Color player_color,
    const King* player_king,
    T_Position player_king_position )
{
    T_Position possible_king_pos[8];
    int8_t nb_pos;
    Get_Possible_Positions( player_king, possible_king_pos, &nb_pos );
    for( uint8_t pos_idx = 0 ; pos_idx<=nb_pos ; pos_idx++ )
    {
        T_Position captured_position = possible_king_pos[pos_idx];
        bool is_square_capturable = true;
        Piece* destination_piece;
        destination_piece = Get_Piece_By_Position(captured_position);
        if( NULL!=destination_piece )
        {
            if( Get_Color( destination_piece ) == player_color )
            {
                is_square_capturable = false;
            }
        }

        if(true==is_square_capturable)
        {
            T_Movement_Data movement = Create_Movement_Data(
                (Piece*)player_king,
                player_king_position,
                possible_king_pos[pos_idx],
                0 /* no matter, will not be stored */ );

            /* Move King */
            Try_Move( &movement );

            /* Verify status */
            bool king_is_check = Is_Check( player_color );

            /* Cancel move */
            Cancel_Move( &movement );

            /* Return is player is not check */
            if( false==king_is_check )
            {
                return false;
            }
        }
    }
    return true;
}
/*----------------------------------------------------------------------------*/
static bool Is_King_Check_After_Capture(
    T_Color player_color,
    T_Position checking_piece_position )
{
    for( T_Rank rank = RANK_1 ; rank<= RANK_8 ; rank++ )
    {
        for( T_File file = FILE_A ; file <= FILE_H ; file++ )
        {
            Piece* current_piece = Get_Piece_By_Rank_And_File(rank,file);
            if( current_piece!=NULL )
            {
                if( Get_Color(current_piece)==player_color )
                {
                    T_Position current_position = Create_Position(rank,file);
                    if( true==Can_Capture_At_Position(
                        current_piece,
                        current_position,
                        checking_piece_position) )
                    {
                        T_Movement_Data movement = Create_Movement_Data(
                            current_piece,
                            current_position,
                            checking_piece_position,
                            0 /* no matter, will not be stored */ );

                        Try_Move( &movement );

                        /* Verify status */
                        bool king_is_check = Is_Check( player_color );

                        /* Cancel move */
                        Cancel_Move( &movement );

                        /* Return if player is not check */
                        if( false==king_is_check )
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}
/*----------------------------------------------------------------------------*/
static void Get_Interception_Positions(
    T_Position king_pos,
    T_Position piece_pos,
    T_Position* interception_positions,
    int8_t* nb_pos )
{
    T_Rank king_rank = Get_Rank(king_pos);
    T_File king_file = Get_File(king_pos);
    T_Rank piece_rank = Get_Rank(piece_pos);
    T_File piece_file = Get_File(piece_pos);
    *nb_pos = -1;

    if(king_rank==piece_rank)
    {
        T_File start = piece_file + 1;
        T_File end = king_file - 1;
        if( piece_file > king_file )
        {
            start = king_file + 1;
            end = piece_file - 1;
        }
        for( T_File file = start ; file <= end ; file++ )
        {
            (*nb_pos)++;
            interception_positions[*nb_pos] = Create_Position(king_rank,file);
        }
    }
    else if(king_file==piece_file)
    {
        T_Rank start = piece_rank + 1;
        T_Rank end = king_rank - 1;
        if( piece_rank > king_rank )
        {
            start = king_rank + 1;
            end = piece_rank - 1;
        }
        for( T_Rank rank = start ; rank <= end ; rank++ )
        {
            (*nb_pos)++;
            interception_positions[*nb_pos] = Create_Position(rank,king_file);
        }
    }
    else
    {
        int8_t diff_rank = (int8_t)king_rank-(int8_t)piece_rank;
        int8_t diff_file = (int8_t)king_file-(int8_t)piece_file;

        if( diff_rank==diff_file || diff_rank==-diff_file )
        {
            if( diff_rank!=1 && diff_rank!=-1 )
            { /* there is a free square between King and Piece */

                int8_t rank_modif = -1;
                if( diff_rank>0 )
                {
                    rank_modif = 1;
                }
                int8_t file_modif = -1;
                if( diff_file>0 )
                {
                    file_modif = 1;
                }
                T_Rank rank = piece_rank ;
                T_File file = piece_file;

                do
                {
                    rank += rank_modif;
                    file += file_modif;
                    (*nb_pos)++;
                    interception_positions[*nb_pos]= Create_Position(rank,file);
                } while( rank!=(king_rank-rank_modif) );
            }
        }
    }
}
/*----------------------------------------------------------------------------*/
static bool Is_Kink_Check_After_Interception(
    T_Color player_color,
    T_Position king_position,
    T_Position checking_piece_position )
{
    T_Position interception_positions[6] = {0};
    int8_t nb_interception_pos = 0;
    Get_Interception_Positions(
        king_position,
        checking_piece_position,
        interception_positions,
        &nb_interception_pos );

    for( int8_t pos_idx = 0 ; pos_idx <nb_interception_pos ; pos_idx++ )
    {
        Piece* interception_piece = NULL;
        T_Position interception_piece_position;

        for( T_Rank rank = RANK_1 ; rank<= RANK_8 ; rank++ )
        {
            for( T_File file = FILE_A ; file <= FILE_H ; file++ )
            {
                interception_piece = Get_Piece_By_Rank_And_File(rank,file);
                if( interception_piece!=NULL )
                {
                    if( Get_Color(interception_piece)==player_color )
                    {
                        interception_piece_position= Create_Position(rank,file);
                        if( true==Can_Capture_At_Position(
                            interception_piece,
                            interception_piece_position,
                            interception_positions[pos_idx]) )
                        {
                            T_Movement_Data movement = Create_Movement_Data(
                                interception_piece,
                                interception_piece_position,
                                interception_positions[pos_idx],
                                0 /* no matter, will not be stored */ );

                            Try_Move( &movement );

                            /* Verify status */
                            bool king_is_check = Is_Check( player_color );

                            /* Cancel move */
                            Cancel_Move( &movement );

                            /* Return if player is not check */
                            if( false==king_is_check )
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}
/*----------------------------------------------------------------------------*/
static void Do_Castling(
    T_Move_Type move_type,
    T_Rank rook_rank,
    bool undo )
{
    T_Position rook_initial_position;
    T_Position rook_final_position;

    if( move_type==A_ROOK_CASTLING )
    {
        rook_initial_position = Create_Position( rook_rank, FILE_A );
        rook_final_position = Create_Position( rook_rank, FILE_D );
    }
    else if( move_type==H_ROOK_CASTLING )
    {
        rook_initial_position = Create_Position( rook_rank, FILE_H );
        rook_final_position = Create_Position( rook_rank, FILE_F );
    }
    else
    {
        return;
    }


    if(undo)
    {
        T_Position temp = rook_final_position;
        rook_final_position = rook_initial_position;
        rook_initial_position = temp;
    }

    Piece* rook_to_move;
    rook_to_move = Get_Piece_By_Position(rook_initial_position);
    Set_Piece( rook_to_move, rook_final_position );
    Set_Piece( NULL, rook_initial_position );
}
