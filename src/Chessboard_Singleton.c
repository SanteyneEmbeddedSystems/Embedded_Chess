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
    .Super =
    {
        .Virtual_Methods = &Rook_Meth,
        .Color = WHITE,
        .Position =
        {
            .rank = RANK_1,
            .file = FILE_A
        }
    },
    .First_Move_Index = NB_RECORDABLE_MOVEMENTS
};

Knight b_white_knight = {
    .Super =
    {
        .Virtual_Methods = &Knight_Meth,
        .Color = WHITE,
        .Position =
        {
            .rank = RANK_1,
            .file = FILE_B
        }
    }
};

Bishop c_white_bishop = {
    .Super =
    {
        .Virtual_Methods = &Bishop_Meth,
        .Color = WHITE,
        .Position =
        {
            .rank = RANK_1,
            .file = FILE_C
        }
    }
};

Queen white_queen = {
    .Super =
    {
        .Virtual_Methods = &Queen_Meth,
        .Color = WHITE,
        .Position =
        {
            .rank = RANK_1,
            .file = FILE_D
        }
    }
};

King white_king = {
    .Super =
    {
        .Virtual_Methods = &King_Meth,
        .Color = WHITE,
        .Position =
        {
            .rank = RANK_1,
            .file = FILE_E
        }
    },
    .First_Move_Index = NB_RECORDABLE_MOVEMENTS
};

Bishop f_white_bishop = {
    .Super =
    {
        .Virtual_Methods = &Bishop_Meth,
        .Color = WHITE,
        .Position =
        {
            .rank = RANK_1,
            .file = FILE_F
        }
    }
};

Knight g_white_knight = {
    .Super =
    {
        .Virtual_Methods = &Knight_Meth,
        .Color = WHITE,
        .Position =
        {
            .rank = RANK_1,
            .file = FILE_G
        }
    }
};

Rook h_white_rook = {
    .Super =
    {
        .Virtual_Methods = &Rook_Meth,
        .Color = WHITE,
        .Position =
        {
            .rank = RANK_1,
            .file = FILE_H
        }
    },
    .First_Move_Index = NB_RECORDABLE_MOVEMENTS
};

Pawn pawn_a2 = {
    .Super =
    {
        .Virtual_Methods = &Pawn_Meth,
        .Color = WHITE,
        .Position =
        {
            .rank = RANK_2,
            .file = FILE_A
        }
    }
};

Pawn pawn_b2 = {
    .Super =
    {
        .Virtual_Methods = &Pawn_Meth,
        .Color = WHITE,
        .Position =
        {
            .rank = RANK_2,
            .file = FILE_B
        }
    }
};

Pawn pawn_c2 = {
    .Super =
    {
        .Virtual_Methods = &Pawn_Meth,
        .Color = WHITE,
        .Position =
        {
            .rank = RANK_2,
            .file = FILE_C
        }
    }
};

Pawn pawn_d2 = {
    .Super =
    {
        .Virtual_Methods = &Pawn_Meth,
        .Color = WHITE,
        .Position =
        {
            .rank = RANK_2,
            .file = FILE_D
        }
    }
};

Pawn pawn_e2 = {
    .Super =
    {
        .Virtual_Methods = &Pawn_Meth,
        .Color = WHITE,
        .Position =
        {
            .rank = RANK_2,
            .file = FILE_E
        }
    }
};

Pawn pawn_f2 = {
    .Super =
    {
        .Virtual_Methods = &Pawn_Meth,
        .Color = WHITE,
        .Position =
        {
            .rank = RANK_2,
            .file = FILE_F
        }
    }
};

Pawn pawn_g2 = {
    .Super =
    {
        .Virtual_Methods = &Pawn_Meth,
        .Color = WHITE,
        .Position =
        {
            .rank = RANK_2,
            .file = FILE_G
        }
    }
};

Pawn pawn_h2 = {
    .Super =
    {
        .Virtual_Methods = &Pawn_Meth,
        .Color = WHITE,
        .Position =
        {
            .rank = RANK_2,
            .file = FILE_H
        }
    }
};

/* Black */
Rook a_black_rook = {
    .Super =
    {
        .Virtual_Methods = &Rook_Meth,
        .Color = BLACK,
        .Position =
        {
            .rank = RANK_8,
            .file = FILE_A
        }
    },
    .First_Move_Index = NB_RECORDABLE_MOVEMENTS
};

Knight b_black_knight = {
    .Super =
    {
        .Virtual_Methods = &Knight_Meth,
        .Color = BLACK,
        .Position =
        {
            .rank = RANK_8,
            .file = FILE_B
        }
    }
};

Bishop c_black_bishop = {
    .Super =
    {
        .Virtual_Methods = &Bishop_Meth,
        .Color = BLACK,
        .Position =
        {
            .rank = RANK_8,
            .file = FILE_C
        }
    }
};

Queen black_queen = {
    .Super =
    {
        .Virtual_Methods = &Queen_Meth,
        .Color = BLACK,
        .Position =
        {
            .rank = RANK_8,
            .file = FILE_D
        }
    }
};

King black_king = {
    .Super =
    {
        .Virtual_Methods = &King_Meth,
        .Color = BLACK,
        .Position =
        {
            .rank = RANK_8,
            .file = FILE_E
        }
    },
    .First_Move_Index = NB_RECORDABLE_MOVEMENTS
};

Bishop f_black_bishop = {
    .Super =
    {
        .Virtual_Methods = &Bishop_Meth,
        .Color = BLACK,
        .Position =
        {
            .rank = RANK_8,
            .file = FILE_F
        }
    }
};

Knight g_black_knight = {
    .Super =
    {
        .Virtual_Methods = &Knight_Meth,
        .Color = BLACK,
        .Position =
        {
            .rank = RANK_8,
            .file = FILE_G
        }
    }
};

Rook h_black_rook = {
    .Super =
    {
        .Virtual_Methods = &Rook_Meth,
        .Color = BLACK,
        .Position =
        {
            .rank = RANK_8,
            .file = FILE_H
        }
    },
    .First_Move_Index = NB_RECORDABLE_MOVEMENTS
};

Pawn pawn_a7 = {
    .Super =
    {
        .Virtual_Methods = &Pawn_Meth,
        .Color = BLACK,
        .Position =
        {
            .rank = RANK_7,
            .file = FILE_A
        }
    }
};

Pawn pawn_b7 = {
    .Super =
    {
        .Virtual_Methods = &Pawn_Meth,
        .Color = BLACK,
        .Position =
        {
            .rank = RANK_7,
            .file = FILE_B
        }
    }
};

Pawn pawn_c7 = {
    .Super =
    {
        .Virtual_Methods = &Pawn_Meth,
        .Color = BLACK,
        .Position =
        {
            .rank = RANK_7,
            .file = FILE_C
        }
    }
};

Pawn pawn_d7 = {
    .Super =
    {
        .Virtual_Methods = &Pawn_Meth,
        .Color = BLACK,
        .Position =
        {
            .rank = RANK_7,
            .file = FILE_D
        }
    }
};

Pawn pawn_e7 = {
    .Super =
    {
        .Virtual_Methods = &Pawn_Meth,
        .Color = BLACK,
        .Position =
        {
            .rank = RANK_7,
            .file = FILE_E
        }
    }
};

Pawn pawn_f7 = {
    .Super =
    {
        .Virtual_Methods = &Pawn_Meth,
        .Color = BLACK,
        .Position =
        {
            .rank = RANK_7,
            .file = FILE_F
        }
    }
};

Pawn pawn_g7 = {
    .Super =
    {
        .Virtual_Methods = &Pawn_Meth,
        .Color = BLACK,
        .Position =
        {
            .rank = RANK_7,
            .file = FILE_G
        }
    }
};

Pawn pawn_h7 = {
    .Super =
    {
        .Virtual_Methods = &Pawn_Meth,
        .Color = BLACK,
        .Position =
        {
            .rank = RANK_7,
            .file = FILE_H
        }
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
    /*.Pieces = {
        {(Piece*)&a_white_rook, NULL, NULL, NULL, (Piece*)&white_king, NULL,NULL, NULL },
        {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
        {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
        {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
        {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
        {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
        {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
        {NULL, NULL, NULL, NULL, (Piece*)&black_king, NULL, NULL, (Piece*)&h_black_rook }
    },*/
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
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
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
            .move_index = 0,
            .board_state = INVALID
        }
    }
};
