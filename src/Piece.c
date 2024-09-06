#include "Piece.h"
#include "Piece_Protected.h"


#include <stdlib.h> /* NULL */

#include "Chessboard_Piece.h" /* association to Chessboard */


/******************************************************************************/
/** Public methods implementation**/
/******************************************************************************/
T_Color Get_Color( const Piece* Me )
{
    return Me->Color;
}
/*----------------------------------------------------------------------------*/
T_Position Get_Position( const Piece* Me)
{
    return Me->Position;
}
/*----------------------------------------------------------------------------*/
bool Is_Captured( const Piece* Me )
{
    if( Me->Piece_Is_Captured==1 )
    {
        return true;
    }
    else
    {
        return false;
    }
}
/*----------------------------------------------------------------------------*/
void Set_Captured( Piece* Me )
{
    Me->Piece_Is_Captured = 1;
}
/*----------------------------------------------------------------------------*/
void Reset_Captured( Piece* Me )
{
    Me->Piece_Is_Captured = 0;
}


/******************************************************************************/
/** Protected methods implementation**/
/******************************************************************************/
bool Is_Piece_Movement_Valid(
    const Piece* Me,
    T_Movement_Data* movement,
    T_Can_Capture_Func capture_func )
{
    movement->move_type = NORMAL;
    return capture_func(
        Me,
        movement->final_position );
}
/*----------------------------------------------------------------------------*/
void Move_Piece_Default( Piece* Me, T_Movement_Data* movement )
{
    Me->Position = movement->final_position;
}
/*----------------------------------------------------------------------------*/
void Undo_Piece_Move_Default( Piece* Me, T_Movement_Data* movement )
{
    Me->Position = movement->initial_position;
}
/*----------------------------------------------------------------------------*/
void Add_Position( int8_t* nb_pos, T_Position* pos, T_Rank rank, T_File file )
{
    (*nb_pos)++;
    pos[*nb_pos] = Create_Position( rank, file );
}
/*----------------------------------------------------------------------------*/
void Add_Position_If_Free(
    const Piece* Me,
    int8_t* nb_pos,
    T_Position* pos,
    T_Rank rank,
    T_File file )
{
    Piece* captured_piece = Get_Piece( rank, file );
    if( NULL==captured_piece
       || Get_Color(Me)!=Get_Color(captured_piece) )
    {
        Add_Position( nb_pos, pos, rank, file );
    }
}
/*----------------------------------------------------------------------------*/
void Get_Possible_Straight_Positions(
    const Piece* Me,
    T_Position* pos,
    int8_t* nb_pos )
{
    T_Rank current_rank = Get_Rank(Me->Position);
    T_File current_file = Get_File(Me->Position);
    *nb_pos = -1;

    for( T_Rank rank = current_rank+1; rank<=RANK_8; rank++ )
    {
        Piece* captured_piece = Get_Piece( rank, current_file );
        if( NULL!=captured_piece )
        {
            if( Get_Color(Me)!=Get_Color(captured_piece) )
            {
                Add_Position( nb_pos, pos, rank, current_file );
            }
            break;
        }
        else
        {
            Add_Position( nb_pos, pos, rank, current_file );
        }
    }
    for( T_Rank rank = current_rank-1; rank>=RANK_1; rank-- )
    {
        Piece* captured_piece = Get_Piece( rank, current_file );
        if( NULL!=captured_piece )
        {
            if( Get_Color(Me)!=Get_Color(captured_piece) )
            {
                Add_Position( nb_pos, pos, rank, current_file );
            }
            break;
        }
        else
        {
            Add_Position( nb_pos, pos, rank, current_file );
        }
    }
    for( T_File file = current_file+1; file<=FILE_H; file++ )
    {
        Piece* captured_piece = Get_Piece( current_rank, file );
        if( NULL!=captured_piece )
        {
            if( Get_Color(Me)!=Get_Color(captured_piece) )
            {
                Add_Position( nb_pos, pos, current_rank, file );
            }
            break;
        }
        else
        {
            Add_Position( nb_pos, pos, current_rank, file );
        }
    }
    for( T_File file = current_file-1; file>=FILE_A; file-- )
    {
        Piece* captured_piece = Get_Piece( current_rank, file );
        if( NULL!=captured_piece )
        {
            if( Get_Color(Me)!=Get_Color(captured_piece) )
            {
                Add_Position( nb_pos, pos, current_rank, file );
            }
            break;
        }
        else
        {
            Add_Position( nb_pos, pos, current_rank, file );
        }
    }
}
/*----------------------------------------------------------------------------*/
void Get_Possible_Diagonal_Positions(
    const Piece* Me,
    T_Position* pos,
    int8_t* nb_pos )
{
    T_Rank current_rank = Get_Rank(Me->Position);
    T_File current_file = Get_File(Me->Position);
    *nb_pos = -1;
    uint8_t square_idx;

    T_Rank rank = current_rank+1;
    T_File file = current_file+1;
    for( square_idx =1 ; rank<=RANK_8 && file<=FILE_H; square_idx++ )
    {
        Piece* captured_piece = Get_Piece( rank, file );
        if( NULL!=captured_piece )
        {
            if( Get_Color(Me)!=Get_Color(captured_piece) )
            {
                Add_Position( nb_pos, pos, rank, file );
            }
            break;
        }
        else
        {
            Add_Position( nb_pos, pos, rank, file );
        }
        rank++;
        file++;
    }

    rank = current_rank-1;
    file = current_file-1;
    for( square_idx =1 ; rank>=RANK_1 && file>=FILE_A; square_idx++ )
    {
        Piece* captured_piece = Get_Piece( rank, file );
        if( NULL!=captured_piece )
        {
            if( Get_Color(Me)!=Get_Color(captured_piece) )
            {
                Add_Position( nb_pos, pos, rank, file );
            }
            break;
        }
        else
        {
            Add_Position( nb_pos, pos, rank, file );
        }
        rank--;
        file--;
    }

    rank = current_rank+1;
    file = current_file-1;
    for( square_idx =1 ; rank<=RANK_8 && file>=FILE_A; square_idx++ )
    {
        Piece* captured_piece = Get_Piece( rank, file );
        if( NULL!=captured_piece )
        {
            if( Get_Color(Me)!=Get_Color(captured_piece) )
            {
                Add_Position( nb_pos, pos, rank, file );
            }
            break;
        }
        else
        {
            Add_Position( nb_pos, pos, rank, file );
        }
        rank++;
        file--;
    }

    rank = current_rank-1;
    file = current_file+1;
    for( square_idx =1 ; rank>=RANK_1 && file<=FILE_H; square_idx++ )
    {
        Piece* captured_piece = Get_Piece( rank, file );
        if( NULL!=captured_piece )
        {
            if( Get_Color(Me)!=Get_Color(captured_piece) )
            {
                Add_Position( nb_pos, pos, rank, file );
            }
            break;
        }
        else
        {
            Add_Position( nb_pos, pos, rank, file );
        }
        rank--;
        file++;
    }
}


/******************************************************************************/
/** Virtual methods **/
/******************************************************************************/
bool Is_Movement_Valid(
    const Piece* Me,
    T_Movement_Data* movement )
{
    if(Me->Piece_Is_Captured==0)
    {
        return Me->Virtual_Methods->is_move_valid( Me, movement );
    }
    else
    {
        return false;
    }
}
/*----------------------------------------------------------------------------*/
bool Can_Capture_At_Position( const Piece* Me, T_Position position)
{
    if(Me->Piece_Is_Captured==0)
    {
        return Me->Virtual_Methods->can_capture_at_position(Me, position);
    }
    else
    {
        return false;
    }
}/*----------------------------------------------------------------------------*/
void Move_Piece( Piece* Me, T_Movement_Data* movement )
{
    Me->Virtual_Methods->move(Me,movement);
}
/*----------------------------------------------------------------------------*/
void Undo_Piece_Move( Piece* Me, T_Movement_Data* movement )
{
    Me->Virtual_Methods->undo_move(Me,movement);
}
/*----------------------------------------------------------------------------*/
char Get_Identifier( const Piece* Me )
{
    return Me->Virtual_Methods->get_id(Me);
}
/*----------------------------------------------------------------------------*/
void Get_Possible_Positions(
    const Piece* Me,
    T_Position* possible_pos,
    int8_t* nb_pos )
{
    if(Me->Piece_Is_Captured==0)
    {
        Me->Virtual_Methods->get_possible_positions( Me, possible_pos, nb_pos );
    }
    else
    {
        *nb_pos = -1;
    }
}
/*----------------------------------------------------------------------------*/
int8_t Get_Score( const Piece* Me )
{
    if(Me->Piece_Is_Captured==0)
    {
        return Me->Virtual_Methods->get_score(Me);
    }
    else
    {
        return 0;
    }
}
