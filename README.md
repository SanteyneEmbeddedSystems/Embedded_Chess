# Embedded_Chess
Provide an implementation of the chess game suitable for embedded system.
The characteristic of the implementation are :
* low memory consumption
* no dynamic memory allocation

To ease debug, a controller and a viewer for console are added.


## Design model

### User interface

![User interface model](doc/User_interface.svg "User interface design model")

### Board

![Board model](doc/Board.svg "Board design model")

### Piece

![Piece model](doc/Pieces.svg "Piece design model")

### Pawn

![Pawn model](doc/Pawn.svg "Pawn design model")

Pawn class specialize Queen class.  
It allows Pawn class to re-use the implementation of the abstract methods from
Piece by Queen class.

### King

![King model](doc/King.svg "King design model")

### Queen, Knight, Rook and Bishop

![Other Pieces model](doc/Others.svg "Other Pieces design model")