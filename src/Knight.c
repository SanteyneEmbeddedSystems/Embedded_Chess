#include "Knight.h"

#include <stdlib.h> /* NULL */
#include "Piece_Protected.h" /* inheritance */
#include "Chessboard_Piece.h" /* association to Chessboard */


/******************************************************************************/
/** Inherited methods implementation **/
/******************************************************************************/
static bool Is_Knight_Movement_Valid(
    const Knight* Me,
    T_Movement_Data* movement );

static bool Can_Knight_Capture_At_Position(
    const Knight* Me,
    T_Position position);

static char Get_Knight_Identifier(const Knight* Me);

static void Get_Possible_Knight_Positions(
    const Knight* Me,
    T_Position* pos,
    int8_t* nb_pos );

static int8_t Get_Knight_Score( const Knight* Me );

/*----------------------------------------------------------------------------*/
Piece_Meth Knight_Meth = {
    ( bool (*) ( const Piece*, T_Movement_Data* ) )Is_Knight_Movement_Valid,
    ( bool (*) (const Piece*, T_Position ) ) Can_Knight_Capture_At_Position,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Move_Piece_Default,
    ( void (*) ( Piece*, T_Movement_Data* ) ) Undo_Piece_Move_Default,
    ( char (*) ( const Piece* ) ) Get_Knight_Identifier,
    ( void (*) ( const Piece*, T_Position*, int8_t* ) )
        Get_Possible_Knight_Positions,
    ( int8_t (*) ( const Piece* ) ) Get_Knight_Score
};
/*----------------------------------------------------------------------------*/
static bool Is_Knight_Movement_Valid(
    const Knight* Me,
    T_Movement_Data* movement )
{
    return Is_Piece_Movement_Valid(
        (Piece*)Me,
        movement,
        (T_Can_Capture_Func)Can_Knight_Capture_At_Position );
}
/*----------------------------------------------------------------------------*/
static bool Can_Knight_Capture_At_Position(
    const Knight* Me,
    T_Position position)
{
    T_Position possible_pos[8];
    int8_t nb_pos;
    Get_Possible_Knight_Positions( Me, possible_pos, &nb_pos );
    for( int8_t pos_idx = 0 ; pos_idx<=nb_pos ; pos_idx++ )
    {
        if( true==Are_Positions_Equal( position, possible_pos[pos_idx] ) )
       {
           return true;
       }
    }
    return false;
}
/*----------------------------------------------------------------------------*/
static char Get_Knight_Identifier( const Knight* Me )
{
    (void)Me; /* unused parameter */
    return('N');
}
/*----------------------------------------------------------------------------*/
static void Get_Possible_Knight_Positions(
    const Knight* Me,
    T_Position* pos,
    int8_t* nb_pos )
{
    T_Position my_pos = Get_Position( (Piece*)Me );
    T_Rank current_rank = Get_Rank(my_pos);
    T_File current_file = Get_File(my_pos);
    *nb_pos = -1;

    if( current_rank>=RANK_3 )
    {
        if( current_file>=FILE_B )
        {
            Add_Position_If_Free(
                (Piece*)Me, nb_pos, pos, current_rank-2, current_file-1 );
        }
        if( current_file<=FILE_G )
        {
            Add_Position_If_Free(
                (Piece*)Me, nb_pos, pos, current_rank-2, current_file+1 );
        }
    }
    if( current_rank<=RANK_6 )
    {
        if( current_file>=FILE_B )
        {
            Add_Position_If_Free(
                (Piece*)Me, nb_pos, pos, current_rank+2, current_file-1 );
        }
        if( current_file<=FILE_G )
        {
            Add_Position_If_Free(
                (Piece*)Me, nb_pos, pos, current_rank+2, current_file+1 );
        }
    }
    if( current_file>=FILE_C )
    {
        if( current_rank>=RANK_2 )
        {
            Add_Position_If_Free(
                (Piece*)Me, nb_pos, pos, current_rank-1, current_file-2 );
        }
        if( current_rank<=RANK_7 )
        {
            Add_Position_If_Free(
                (Piece*)Me, nb_pos, pos, current_rank+1, current_file-2 );
        }
    }
    if( current_file<=FILE_F )
    {
        if( current_rank>=RANK_2 )
        {
            Add_Position_If_Free(
                (Piece*)Me, nb_pos, pos, current_rank-1, current_file+2 );
        }
        if( current_rank<=RANK_7 )
        {
            Add_Position_If_Free(
                (Piece*)Me, nb_pos, pos, current_rank+1, current_file+2 );
        }
    }
}
/*----------------------------------------------------------------------------*/
static int8_t Get_Knight_Score( const Knight* Me )
{
    (void)Me; /* unused parameter */
    return 3;
}
