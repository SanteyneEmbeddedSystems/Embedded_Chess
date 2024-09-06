#ifndef PIECE_H
#define PIECE_H

typedef struct _Piece Piece;

#include "stdbool.h"

#include "Color.h"
#include "Position.h"
#include "Movement_Data.h"


/******************************************************************************/
/** Class definition **/
/******************************************************************************/
typedef struct {
    bool (*is_move_valid)( const Piece*, T_Movement_Data* );
    bool (*can_capture_at_position)( const Piece*, T_Position );
    void (*move)( Piece*, T_Movement_Data* );
    void (*undo_move)( Piece*, T_Movement_Data* );
    char (*get_id)(const Piece*);
    void (*get_possible_positions)( const Piece*, T_Position*, int8_t* );
    int8_t (*get_score)( const Piece* );
} Piece_Meth;


struct _Piece {
    const Piece_Meth* Virtual_Methods;
    T_Position Position;
    T_Color Color;
};


/******************************************************************************/
/** Public methods **/
/******************************************************************************/
T_Color Get_Color( const Piece* Me );
T_Position Get_Position( const Piece* Me );


/******************************************************************************/
/** Virtual methods **/
/******************************************************************************/
/* Assumes that Me is movement.moved_piece */
/* Assumes that Me is on movement.initial_position */
/* Assumes that movement.final_position is free or occupied by opponent */
/* Does not verify if final state is check nor checkmate */
/* Does not modify the board */
bool Is_Movement_Valid( const Piece* Me, T_Movement_Data* movement );

bool Can_Capture_At_Position( const Piece* Me, T_Position position);

/* Modifies internal attributes of Piece */
void Move_Piece( Piece* Me, T_Movement_Data* movement );
void Undo_Piece_Move( Piece* Me, T_Movement_Data* movement );

char Get_Identifier( const Piece* Me );

/* Returns the list of positions that can be taken by the Piece totally ignoring
the other Pieces of the board.
This methods shall be used by Minimax to increase algo speed. */
void Get_Possible_Positions(
    const Piece* Me,
    T_Position* possible_pos,
    int8_t* nb_pos );

int8_t Get_Score( const Piece* Me );

#endif
