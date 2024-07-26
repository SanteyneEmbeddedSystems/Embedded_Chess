chess : main.o Bishop.o Board.o Chessboard_Singleton.o Debug_Controller.o Debug_Viewer.o King.o Knight.o Movement_Data.o Pawn.o Piece.o Position.o Queen.o Rook.o
	gcc -o chess main.o Bishop.o Board.o Chessboard_Singleton.o Debug_Controller.o Debug_Viewer.o King.o Knight.o Movement_Data.o Pawn.o Piece.o Position.o Queen.o Rook.o

main.o : main.c Debug_Controller.h
	gcc -c -Wall main.c

Bishop.o : Bishop.c Bishop.h Piece_Protected.h Chessboard_Piece.h
	gcc -c -Wall Bishop.c

Board.o : Board.c Board.h Board_Management.h Chessboard_Piece.h Chessboard_King.h Chessboard_Pawn.h
	gcc -c -Wall Board.c

Chessboard_Singleton.o : Chessboard_Singleton.c Board.h Rook.h Knight.h Bishop.h King.h Queen.h Pawn.h
	gcc -c -Wall Chessboard_Singleton.c

Debug_Controller.o : Debug_Controller.c Debug_Controller.h Board_Management.h Debug_Viewer.h
	gcc -c -Wall Debug_Controller.c

Debug_Viewer.o : Debug_Viewer.c Debug_Viewer.h Board_Management.h
	gcc -c -Wall Debug_Viewer.c

King.o : King.c King.h Piece_Protected.h Chessboard_King.h
	gcc -c -Wall King.c

Knight.o : Knight.c Knight.h Piece_Protected.h Chessboard_Piece.h
	gcc -c -Wall Knight.c

Movement_Data.o : Movement_Data.c Movement_Data.h
	gcc -c -Wall Movement_Data.c

Pawn.o : Pawn.c Pawn.h Piece_Protected.h Queen_Protected.h Chessboard_Pawn.h
	gcc -c -Wall Pawn.c

Piece.o : Piece.c Piece.h Piece_Protected.h Chessboard_Piece.h
	gcc -c -Wall Piece.c

Position.o : Position.c Position.h
	gcc -c -Wall Position.c

Queen.o : Queen.c Queen.h Queen_Protected.h Piece_Protected.h Chessboard_Piece.h
	gcc -c -Wall Queen.c

Rook.o : Rook.c Rook.h Piece_Protected.h Chessboard_Piece.h
	gcc -c -Wall Rook.c

clean :
	rm -f *.o