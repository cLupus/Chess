//
// Created by Sindre Nistad on 6/19/16.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H


#include <string>
#include "Piece.h"

#define BOARDSIZE 8

#define PAWNWHITE 'P'
#define PAWNBLACK 'p'
#define KNIGHTWHITE 'N'
#define KNIGHTBLACK 'n'
#define BISHOPWHITE 'B'
#define BISHOPBLACK 'b'
#define ROOKWHITE 'R'
#define ROOKBLACK 'r'
#define QUEENWHITE 'Q'
#define QUEENBLACK 'q'
#define KINGWHITE 'K'
#define KINGBLACK 'k'

class Piece;
struct Position;

class Board {
public:
    // Constructors / destructors
    Board();
    ~Board();

    Piece*** board;

    // Methods
    bool removePiece(std::string position);
    Piece getPiece(std::string position);
    void printBoard();
    char piece2char(Piece* piece);

};

#endif //CHESS_BOARD_H
