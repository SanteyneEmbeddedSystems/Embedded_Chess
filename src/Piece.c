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
            if( NULL!=Get_Piece_By_Rank_And_File(rank,piece_file) )
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
            if( NULL!=Get_Piece_By_Rank_And_File(piece_rank,file) )
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
            /* Test squares between initial bishop position and
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
                if( NULL!=Get_Piece_By_Rank_And_File(piece_rank,piece_file) )
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
    /* nothing to do */
    (void)Me; /* unused parameter */
    (void)movement; /* unused parameter */
}
/*----------------------------------------------------------------------------*/
void Undo_Piece_Move_Default(
    Piece* Me,
    T_Movement_Data* movement )
{
    /* nothing to do */
    (void)Me; /* unused parameter */
    (void)movement; /* unused parameter */
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
