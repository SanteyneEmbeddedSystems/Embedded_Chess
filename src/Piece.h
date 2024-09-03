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
    const T_Color Color;
    int8_t Score;
};


/******************************************************************************/
/** Public methods **/
/******************************************************************************/
T_Color Get_Color( const Piece* Me );
int8_t Get_Score( const Piece* Me );

/******************************************************************************/
/** Virtual methods **/
/******************************************************************************/
/* Assumes that Me is movement.moved_piece */
/* Assumes that Me is on movement.initial_position */
/* Assumes that movement.final_position is free or occupied by opponent */
/* Does not verify if final state is check nor checkmate */
/* Does not modify the board */
bool Is_Movement_Valid( const Piece* Me, T_Movement_Data* movement );

/* Assumes that Me is on initial_position */
bool Can_Capture_At_Position(
    const Piece* Me,
    T_Position initial_position,
    T_Position final_position);

/* Modifies internal attributes of Piece */
void Move_Piece( Piece* Me, T_Movement_Data* movement );
void Undo_Piece_Move( Piece* Me, T_Movement_Data* movement );

char Get_Identifier( const Piece* Me );

#endif
