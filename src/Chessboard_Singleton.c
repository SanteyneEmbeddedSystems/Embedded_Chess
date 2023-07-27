#include "Board.h"


/******************************************************************************/
/** Inclusions **/
/******************************************************************************/
/* Utilities */
#include <stdlib.h> /* NULL */

/* Parts */
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"


/******************************************************************************/
/** Singleton definition**/
/******************************************************************************/
/* White */
Rook a_white_rook = {
    .Super = {
        .Virtual_Methods = &Rook_Meth,
        .Color = WHITE},
    .First_Move_Index = NB_RECORDABLE_MOVEMENTS
};

Knight b_white_knight = {
    .Super = {
        .Virtual_Methods = &Knight_Meth,
        .Color = WHITE},
};

Bishop c_white_bishop = {
    .Super = {
        .Virtual_Methods = &Bishop_Meth,
        .Color = WHITE}
};

King white_king = {
    .Super = {
        .Virtual_Methods = &King_Meth,
        .Color = WHITE
    },
    .Current_Position = {
        .rank = RANK_1,
        .file = FILE_E
    },
    .First_Move_Index = NB_RECORDABLE_MOVEMENTS
};

Queen white_queen = {
    .Super = {
        .Virtual_Methods = &Queen_Meth,
        .Color = WHITE
    }
};

Bishop f_white_bishop = {
    .Super = {
        .Virtual_Methods = &Bishop_Meth,
        .Color = WHITE
    }
};

Knight g_white_knight = {
    .Super = {
        .Virtual_Methods = &Knight_Meth,
        .Color = WHITE
    }
};

Rook h_white_rook = {
    .Super = {
        .Virtual_Methods = &Rook_Meth,
        .Color = WHITE
    },
    .First_Move_Index = NB_RECORDABLE_MOVEMENTS
};

Pawn pawn_a2 = {
    .Super = {
        .Virtual_Methods = &Pawn_Meth,
        .Color = WHITE
    }
};

Pawn pawn_b2 = {
    .Super = {
        .Virtual_Methods = &Pawn_Meth,
        .Color = WHITE
    }
};

Pawn pawn_c2 = {
    .Super = {
        .Virtual_Methods = &Pawn_Meth,
        .Color = WHITE
    }
};

Pawn pawn_d2 = {
    .Super = {
        .Virtual_Methods = &Pawn_Meth,
        .Color = WHITE
    }
};

Pawn pawn_e2 = {
    .Super = {
        .Virtual_Methods = &Pawn_Meth,
        .Color = WHITE
    }
};

Pawn pawn_f2 = {
    .Super = {
        .Virtual_Methods = &Pawn_Meth,
        .Color = WHITE
    }
};

Pawn pawn_g2 = {
    .Super = {
        .Virtual_Methods = &Pawn_Meth,
        .Color = WHITE
    }
};

Pawn pawn_h2 = {
    .Super = {
        .Virtual_Methods = &Pawn_Meth,
        .Color = WHITE
    }
};

/* Black */
Rook a_black_rook = {
    .Super = {
        .Virtual_Methods = &Rook_Meth,
        .Color = BLACK
    },
    .First_Move_Index = NB_RECORDABLE_MOVEMENTS
};

Knight b_black_knight = {
    .Super = {
        .Virtual_Methods = &Knight_Meth,
        .Color = BLACK
    }
};

Bishop c_black_bishop = {
    .Super = {
        .Virtual_Methods = &Bishop_Meth,
        .Color = BLACK
    }
};

King black_king = {
    .Super = {
        .Virtual_Methods = &King_Meth,
        .Color = BLACK
    },
    .Current_Position = {
        .rank = RANK_8,
        .file = FILE_E
    },
    .First_Move_Index = NB_RECORDABLE_MOVEMENTS
};

Queen black_queen = {
    .Super = {
        .Virtual_Methods = &Queen_Meth,
        .Color = BLACK
    }
};

Bishop f_black_bishop = {
    .Super = {
        .Virtual_Methods = &Bishop_Meth,
        .Color = BLACK
    }
};

Knight g_black_knight = {
    .Super = {
        .Virtual_Methods = &Knight_Meth,
        .Color = BLACK
    }
};

Rook h_black_rook = {
    .Super = {
        .Virtual_Methods = &Rook_Meth,
        .Color = BLACK
    },
    .First_Move_Index = NB_RECORDABLE_MOVEMENTS
};

Pawn pawn_a7 = {
    .Super = {
        .Virtual_Methods = &Pawn_Meth,
        .Color = BLACK
    }
};

Pawn pawn_b7 = {
    .Super = {
        .Virtual_Methods = &Pawn_Meth,
        .Color = BLACK
    }
};

Pawn pawn_c7 = {
    .Super = {
        .Virtual_Methods = &Pawn_Meth,
        .Color = BLACK
    }
};

Pawn pawn_d7 = {
    .Super = {
        .Virtual_Methods = &Pawn_Meth,
        .Color = BLACK
    }
};

Pawn pawn_e7 = {
    .Super = {
        .Virtual_Methods = &Pawn_Meth,
        .Color = BLACK
    }
};

Pawn pawn_f7 = {
    .Super = {
        .Virtual_Methods = &Pawn_Meth,
        .Color = BLACK
    }
};

Pawn pawn_g7 = {
    .Super = {
        .Virtual_Methods = &Pawn_Meth,
        .Color = BLACK
    }
};

Pawn pawn_h7 = {
    .Super = {
        .Virtual_Methods = &Pawn_Meth,
        .Color = BLACK
    }
};


Board Chessboard = {
    .Pieces = {
        {(Piece*)&a_white_rook, (Piece*)&b_white_knight,
        (Piece*)&c_white_bishop, (Piece*)&white_queen,
        (Piece*)&white_king, (Piece*)&f_white_bishop,
        (Piece*)&g_white_knight, (Piece*)&h_white_rook },
        {(Piece*)&pawn_a2,(Piece*)&pawn_b2,(Piece*)&pawn_c2,(Piece*)&pawn_d2,
        (Piece*)&pawn_e2,(Piece*)&pawn_f2,(Piece*)&pawn_g2,(Piece*)&pawn_h2},
        {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
        {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
        {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
        {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
        {(Piece*)&pawn_a7,(Piece*)&pawn_b7,(Piece*)&pawn_c7,(Piece*)&pawn_d7,
        (Piece*)&pawn_e7,(Piece*)&pawn_f7,(Piece*)&pawn_g7,(Piece*)&pawn_h7},
        {(Piece*)&a_black_rook, (Piece*)&b_black_knight,
        (Piece*)&c_black_bishop, (Piece*)&black_queen,
        (Piece*)&black_king, (Piece*)&f_black_bishop,
        (Piece*)&g_black_knight, (Piece*)&h_black_rook }
    },
    .White_King = &white_king,
    .Black_King = &black_king,
    .White_A_Rook = &a_white_rook,
    .White_H_Rook = &h_white_rook,
    .Black_A_Rook = &a_black_rook,
    .Black_H_Rook = &h_black_rook,
    .Nb_Movements = 0,
    .Movements =
    {
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0,
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        },
        {
            .moved_piece = NULL,
            .captured_piece = NULL,
            .initial_position =
            {
                .rank = 0,
                .file = 0
            },
            .final_position =
            {
                .rank = 0,
                .file = 0
            },
            .move_type = NORMAL,
            .move_index = 0
        }

    }
};
