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
        movement->initial_position,
        movement->final_position );
}
/*----------------------------------------------------------------------------*/
bool Can_Capture_Straight(
    T_Rank piece_rank,
    T_File piece_file,
    T_Rank capture_rank,
    T_File capture_file )
{
    if( piece_file == capture_file )
    { /* Movement is along a rank. */
        T_Rank start = piece_rank + 1; /* +1 to not test its own square. */
        T_Rank end = capture_rank; /* No -1 do avoid underflow, use '<' in for
                                loop instead (to not test destination square. */
        if( piece_rank > end )
        {
            start = capture_rank + 1;
            end = piece_rank;
        }
        for( T_Rank rank = start ; rank < end ; rank++ )
        {
            if( NULL!=Get_Piece( rank, piece_file ) )
            {
                return false;
            }
        }
    }
    else if( piece_rank == capture_rank )
    { /* Movement is along a file. */
        T_File start = piece_file + 1;
        T_File end = capture_file;
        if( piece_file > end )
        {
            start = capture_file + 1;
            end = piece_file;
        }
        for( T_File file = start ; file < end ; file++ )
        {
            if( NULL!=Get_Piece( piece_rank, file ) )
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}
/*----------------------------------------------------------------------------*/
bool Can_Capture_Diagonal(
    T_Rank piece_rank,
    T_File piece_file,
    T_Rank capture_rank,
    T_File capture_file )
{
    int8_t diff_rank = (int8_t)capture_rank-(int8_t)piece_rank;
    int8_t diff_file = (int8_t)capture_file-(int8_t)piece_file;

    if( diff_rank==diff_file || diff_rank==-diff_file )
    { /* movement is along a diagonal */
        if( diff_rank!=1 && diff_rank!=-1 )
        { /* Movement is more than 1 square */
            /* Test squares between initial piece position and
            capture position. */
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

            do
            {
                piece_rank += rank_modif;
                piece_file += file_modif;
                if( NULL!=Get_Piece( piece_rank, piece_file ) )
                {
                    return false;
                }
            } while( piece_rank!=(capture_rank-rank_modif) );
        }
    }
    else
    {
        return false;
    }

    return true;
}
/*----------------------------------------------------------------------------*/
void Move_Piece_Default(
    Piece* Me,
    T_Movement_Data* movement )
{
    Me->Position = movement->final_position;
}
/*----------------------------------------------------------------------------*/
void Undo_Piece_Move_Default(
    Piece* Me,
    T_Movement_Data* movement )
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
    T_Rank current_rank = Me->Position.rank;
    T_File current_file = Me->Position.file;
    *nb_pos = -1;

    for( T_Rank rank = current_rank+1; rank<=RANK_8; rank++ )
    {
        Piece* captured_piece = Get_Piece( rank, current_file );
        if( NULL!=captured_piece )
        {
            if( Get_Color(Me)!=Get_Color(captured_piece) )
            {
                Add_Position( nb_pos, pos, rank, current_file );
                /*(*nb_pos)++;
                pos[*nb_pos] = Create_Position( rank, current_file );*/
            }
            break;
        }
        else
        {
            Add_Position( nb_pos, pos, rank, current_file );
            /*(*nb_pos)++;
            pos[*nb_pos] = Create_Position( rank, current_file );*/
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
                /*(*nb_pos)++;
                pos[*nb_pos] = Create_Position( rank, current_file );*/
            }
            break;
        }
        else
        {
            Add_Position( nb_pos, pos, rank, current_file );
            /*(*nb_pos)++;
            pos[*nb_pos] = Create_Position( rank, current_file );*/
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
                /*(*nb_pos)++;
                pos[*nb_pos] = Create_Position( current_rank, file );*/
            }
            break;
        }
        else
        {
            Add_Position( nb_pos, pos, current_rank, file );
            /*(*nb_pos)++;
            pos[*nb_pos] = Create_Position( current_rank, file );*/
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
                /*(*nb_pos)++;
                pos[*nb_pos] = Create_Position( current_rank, file );*/
            }
            break;
        }
        else
        {
            Add_Position( nb_pos, pos, current_rank, file );
            /*(*nb_pos)++;
            pos[*nb_pos] = Create_Position( current_rank, file );*/
        }
    }
}
/*----------------------------------------------------------------------------*/
void Get_Possible_Diagonal_Positions(
    const Piece* Me,
    T_Position* pos,
    int8_t* nb_pos )
{
    T_Rank current_rank = Me->Position.rank;
    T_File current_file = Me->Position.file;
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
                /*(*nb_pos)++;
                pos[*nb_pos] = Create_Position( rank, file );*/
            }
            break;
        }
        else
        {
            Add_Position( nb_pos, pos, rank, file );
            /*(*nb_pos)++;
            pos[*nb_pos] = Create_Position( rank, file );*/
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
                /*(*nb_pos)++;
                pos[*nb_pos] = Create_Position( rank, file );*/
            }
            break;
        }
        else
        {
            Add_Position( nb_pos, pos, rank, file );
            /*(*nb_pos)++;
            pos[*nb_pos] = Create_Position( rank, file );*/
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
                /*(*nb_pos)++;
                pos[*nb_pos] = Create_Position( rank, file );*/
            }
            break;
        }
        else
        {
            Add_Position( nb_pos, pos, rank, file );
            /*(*nb_pos)++;
            pos[*nb_pos] = Create_Position( rank, file );*/
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
                /*(*nb_pos)++;
                pos[*nb_pos] = Create_Position( rank, file );*/
            }
            break;
        }
        else
        {
            Add_Position( nb_pos, pos, rank, file );
            /*(*nb_pos)++;
            pos[*nb_pos] = Create_Position( rank, file );*/
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
    return Me->Virtual_Methods->is_move_valid( Me, movement );
}
/*----------------------------------------------------------------------------*/
bool Can_Capture_At_Position(
    const Piece* Me,
    T_Position initial_position,
    T_Position final_position)
{
    return Me->Virtual_Methods->can_capture_at_position(
        Me, initial_position, final_position);
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
    Me->Virtual_Methods->get_possible_positions( Me, possible_pos, nb_pos );
}
/*----------------------------------------------------------------------------*/
int8_t Get_Score( const Piece* Me )
{
    return Me->Virtual_Methods->get_score(Me);
}
