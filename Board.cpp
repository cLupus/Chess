//
// Created by Sindre Nistad on 6/19/16.
//

#include <boost/concept_check.hpp>
#include <iostream>
#include "Board.h"

void createFirstRow(Piece*** board, Color color){
    int i = (color == Color::black) ? 0: 7;

    // Place rooks
    board[i][0] = new Piece(Type::rook, color);
    board[i][7] = new Piece(Type::rook, color);

    // Place knights
    board[i][1] = new Piece(Type::knight, color);
    board[i][6] = new Piece(Type::knight, color);

    // Place bishops
    board[i][2] = new Piece(Type::bishop, color);
    board[i][5] = new Piece(Type::bishop, color);

    // Place the queen
    board[i][3] = new Piece(Type::queen, color);

    // Place the king
    board[i][4] = new Piece(Type::king, color);

}

void placePawns(Piece*** board, Color color){
    int i = (color == Color::black) ? 1: 6;
    for (int j = 0; j < BOARDSIZE; ++j) {
        board[i][j] = new Piece(Type::pawn, color);
    }
}

Piece*** createBoard(){
    Piece*** board = 0;
    board = new Piece**[BOARDSIZE];

    for (int i = 0; i < BOARDSIZE; ++i) {
        board[i] = new Piece*[BOARDSIZE];
        if (i == 0){
            // Create first row of black
            createFirstRow(board, Color::black);
        }else if (i == 1){
            // Place black pawns
            placePawns(board, Color::black);
        }else if (i == 6){
            // Place white pawns
            placePawns(board, Color::white);
        }else if (i == 7){
            // Place white pieces
            createFirstRow(board, Color::white);
        }

        for (int j = 0; j < BOARDSIZE; ++j) {
            board[i][j]->setPosition(i, j);
        }
    }
    return board;
}

void Board::printBoard() {
    for (int i = 0; i < BOARDSIZE; ++i) {
        for (int j = 0; j < BOARDSIZE; ++j) {
//            std::cout << piece2char(this->board[i][j]) << '\t';
            std::cout << this->board[i][j]->to_string() << '\t';
        }
        std::cout << std::endl;
    }
}



Board::Board(){
    this->board = createBoard();
}

Board::~Board() {
    for (int i = 0; i < BOARDSIZE; ++i) {
        delete[] board[i];
    }
    delete[] board;
}

