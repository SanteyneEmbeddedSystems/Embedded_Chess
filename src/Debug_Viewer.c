#include "Debug_Viewer.h"

#include <stdlib.h> /* NULL */
#include <stdio.h> /* printf */
#include <stdint.h> /* uint16_t */

#include "Board_Management.h"


/******************************************************************************/
/** Squares and chessmen drawing stuff */
/******************************************************************************/
/*
A square of the chessboard is drawn on console as a 16*8 rectangle of
characters.
A piece of WHITE square is drawn with simple quote (') character.
A piece of BLACK square is drawn with space ( ) character.
A piece of WHITE chessman is drawn with zero (0) character.
A piece of BLACK chessman is drawn with vertical bar (|) character.

The pattern of a piece is stored using a array of 8 uint16_t.
So it can be considered as 16*8 array of bits. Each bit represent a character.
If bit is 0 a piece of square shall be drawn.
If bit is 1 a piece of chessman shall be drawn.

An empty square could be stored as an array of bits all equal to 0.
*/

#define NB_SQUARE_LINE 8

static const uint16_t PAWN_PATTERN[NB_SQUARE_LINE]={
0b0000000000000000,
0b0000001111000000,
0b0000011111100000,
0b0000001111000000,
0b0000001111000000,
0b0000111111110000,
0b0011111111111100,
0b0000000000000000};

static const uint16_t ROOK_PATTERN[NB_SQUARE_LINE]={
0b0000000000000000,
0b0011001111001100,
0b0011111111111100,
0b0000111111110000,
0b0000111111110000,
0b0000111111110000,
0b0011111111111100,
0b0011111111111100};

static const uint16_t KNIGHT_PATTERN[NB_SQUARE_LINE]={
0b0000000000000000,
0b0000001111000000,
0b0000111111110000,
0b0011111111110000,
0b0011111111110000,
0b0000001111110000,
0b0000111111110000,
0b0011111111111100};

static const uint16_t BISHOP_PATTERN[NB_SQUARE_LINE]={
0b0000000000000000,
0b0000001111000000,
0b0000111100000000,
0b0000111111110000,
0b0000001111000000,
0b0000001111000000,
0b0000111111110000,
0b0011111111111100};

static const uint16_t QUEEN_PATTERN[NB_SQUARE_LINE]={
0b0000000000000000,
0b0000001111000000,
0b0011001111001100,
0b0011111111111100,
0b0000011111100000,
0b0000111111110000,
0b0001111111111000,
0b0011111111111100};

static const uint16_t KING_PATTERN[NB_SQUARE_LINE]={
0b0000000110000000,
0b0000001111000000,
0b0000000110000000,
0b0000011111100000,
0b0000011111100000,
0b0000111111110000,
0b0001111111111000,
0b0011111111111100};


/******************************************************************************/
/** Private functions declaration **/
/******************************************************************************/
static void Draw_Square_Line(
    T_Color square_color,
    T_Color piece_color,
    uint16_t line_pattern );

static void Draw_Line_Id(void);


/******************************************************************************/
/** Public functions implementation **/
/******************************************************************************/
void Display_Board( void )
{
    printf("\n\n\n");
    Draw_Line_Id();
    printf("\n");
    T_Color square_color = WHITE;
    for( int rank = 7 ; rank>=0 ; rank-- )
    {
        /* Get the color of the first square on the rank (file a) */
        if(rank%2)
        {
            square_color = BLACK;
        }
        else
        {
            square_color = WHITE;
        }

        /* Get Pieces data of the current rank */
        T_Color rank_piece_color[8] = {WHITE};
        char rank_piece_id[8] = {0};
        for( int file = 0 ; file<=7 ; file++ )
        {
            Piece* current_piece = NULL;
            current_piece = Get_Piece( rank, file );
            if (NULL!=current_piece)
            {
                rank_piece_color[file] = Get_Color(current_piece);
                rank_piece_id[file] = Get_Identifier(current_piece);
            }
        }

        /* Draw line by line */
        for( int square_line=0 ; square_line<=NB_SQUARE_LINE-1 ; square_line++ )
        {
            /* Draw the margin with rank number. */
            if(square_line==4)
            {
                printf(" %u  ", rank+1 );
            }
            else
            {
                printf("    ");
            }

            for( int file = 0 ; file<=7 ; file++ )
            {
                uint16_t line_pattern = 0;
                switch( rank_piece_id[file] )
                {
                    case 'P':
                        line_pattern = PAWN_PATTERN[square_line];
                        break;
                    case 'R':
                        line_pattern = ROOK_PATTERN[square_line];
                        break;
                    case 'N':
                        line_pattern = KNIGHT_PATTERN[square_line];
                        break;
                    case 'B':
                        line_pattern = BISHOP_PATTERN[square_line];
                        break;
                    case 'Q':
                        line_pattern = QUEEN_PATTERN[square_line];
                        break;
                    case 'K':
                        line_pattern = KING_PATTERN[square_line];
                        break;
                    case 0: /* empty square */
                        line_pattern = 0;
                        break;
                }
                Draw_Square_Line(
                    square_color,
                    rank_piece_color[file], /* no matter */
                    line_pattern );

                /* Change the color of square. */
                if(square_color==BLACK)
                {
                    square_color = WHITE;
                }
                else
                {
                    square_color = BLACK;
                }
            }

            /* Draw the rank number. */
            if(square_line==4)
            {
                printf("  %u", rank+1 );
            }

            printf("\n");
        }
    }
    printf("\n");
    Draw_Line_Id();
    printf("\n");

    switch( Get_State() )
    {
        case INVALID :
            printf("INVALID");
            break;
        case ON_GOING :
            if( WHITE==Get_Current_Player() )
            {
                printf( "White player plays.\n");
            }
            else
            {
                printf( "Black player plays.\n");
            }
            break;
        case WHITE_CHECK :
        case BLACK_CHECK :
            printf("Check !\n");
            if( WHITE==Get_Current_Player() )
            {
                printf( "White player plays.\n");
            }
            else
            {
                printf( "Black player plays.\n");
            }
            break;
        case WHITE_CHECKMATE :
        case BLACK_CHECKMATE :
            printf("Checkmate !");
            break;
        case STALEMATE :
            printf("Stalemate !");
            break;
    }
}
/*----------------------------------------------------------------------------*/
void Ask_For_Command( char* command )
{
    printf("Enter movement : ");
    scanf("%5s", command );
    /* Empty buffer */
    scanf("%*[^\n]");
    getchar();
}


/******************************************************************************/
/** Private functions implementation **/
/******************************************************************************/
static void Draw_Square_Line(
    T_Color square_color,
    T_Color chessman_color,
    uint16_t line_pattern )
{
    for( int bit_idx=15; bit_idx>=0 ; bit_idx-- )
    {
        uint16_t mask = 1<<bit_idx;
        if( line_pattern & mask )
        {
            /* Draw a piece of a chessman. */
            if(chessman_color==WHITE)
            {
                printf("0");
            }
            else if(chessman_color==BLACK)
            {
                printf("|");
            }
        }
        else
        {
            /* Draw a piece of a square. */
            if(square_color==WHITE)
            {
                printf(" ");
            }
            else if(square_color==BLACK)
            {
                printf("'");
            }
        }
    }
}
/*----------------------------------------------------------------------------*/
static void Draw_Line_Id(void)
{
    printf("            a               b               c               d");
    printf("               e               f               g               h");
    printf("\n");
}
