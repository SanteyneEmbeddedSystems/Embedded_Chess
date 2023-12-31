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
    bool (*can_capture_at_position)( const Piece*, T_Position , T_Position );
    void (*move)( Piece*, T_Movement_Data* );
    void (*undo_move)( Piece*, T_Movement_Data* );
    char (*get_id)(const Piece*);
} Piece_Meth;


struct _Piece {
    const Piece_Meth* Virtual_Methods;
    T_Color Color;
};


/******************************************************************************/
/** Public methods **/
/******************************************************************************/
T_Color Get_Color( const Piece* Me );


/******************************************************************************/
/** Virtual methods **/
/******************************************************************************/
/* assume that Me is movement.moved_piece */
/* assume that Me is on movement.initial_position */
/* assume that movement.final_position is free or occupied by opponent */
/* do not verify if final state is check nor checkmate */
/* do not modify the board */
bool Is_Movement_Valid( const Piece* Me, T_Movement_Data* movement );

/* Assume that Me is on initial_position */
bool Can_Capture_At_Position(
    const Piece* Me,
    T_Position initial_position,
    T_Position final_position);

/* Modify internal attributes of Piece */
void Move_Piece( Piece* Me, T_Movement_Data* movement );
void Undo_Piece_Move( Piece* Me, T_Movement_Data* movement );

char Get_Identifier( const Piece* Me );

#endif
