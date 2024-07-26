chess : main.o Bishop.o Board.o Chessboard_Singleton.o Debug_Controller.o Debug_Viewer.o King.o Knight.o Movement_Data.o Pawn.o Piece.o Position.o Queen.o Rook.o
	gcc -o chess main.o Bishop.o Board.o Chessboard_Singleton.o Debug_Controller.o Debug_Viewer.o King.o Knight.o Movement_Data.o Pawn.o Piece.o Position.o Queen.o Rook.o

main.o : main.c
	gcc -c -Wall main.c

Bishop.o : Bishop.c
	gcc -c -Wall Bishop.c

Board.o : Board.c
	gcc -c -Wall Board.c

Chessboard_Singleton.o : Chessboard_Singleton.c
	gcc -c -Wall Chessboard_Singleton.c

Debug_Controller.o : Debug_Controller.c
	gcc -c -Wall Debug_Controller.c

Debug_Viewer.o : Debug_Viewer.c
	gcc -c -Wall Debug_Viewer.c

King.o : King.c
	gcc -c -Wall King.c

Knight.o : Knight.c
	gcc -c -Wall Knight.c

Movement_Data.o : Movement_Data.c
	gcc -c -Wall Movement_Data.c

Pawn.o : Pawn.c
	gcc -c -Wall Pawn.c

Piece.o : Piece.c
	gcc -c -Wall Piece.c

Position.o : Position.c
	gcc -c -Wall Position.c

Queen.o : Queen.c
	gcc -c -Wall Queen.c

Rook.o : Rook.c
	gcc -c -Wall Rook.c


clean :
	rm -f *.o