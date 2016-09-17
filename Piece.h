//
// Created by Sindre Nistad on 6/19/16.
//

//===============================
// include guard
#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

//===============================
// forward declared dependencies
//class Board;

//===============================
// included dependencies
#include "string"
#include "Board.h"

//===============================
// define enums
enum Type {none, pawn, knight, bishop, rook, queen, king};
enum Color {black, white};

// structs
//struct Position{
//    int column;
//    int row;
//};

class Board;

class Position{
private:
    int column;
    int row;
    std::string position;

public:
    Position(int row, int column);
    Position(std::string position);

    Position();

    void setPosition(int row, int column);
    void setPosition(std::string position);

    int getRow(void);
    int getColumn(void);
    std::string getPosition(void);
};

//===============================
// The Piece class
class Piece {
private:
    Type type;
    Color color;
    Position position;
    bool hasMoved;
    bool canMovePawn(Board* board, std::string move_to);

public:
    Piece();
    Piece(Type type, Color color);
    Piece(Type t, Color c, int column, int row);
    Piece(Type t, Color c, Position position);
    ~Piece();

    char to_string(void);

    bool canMove(Board* board, std::string move_to);
    bool canTake(Board* board, std::string opposing_piece);
    bool move(Board* board, std::string move_to);

    // Setters
    void setPosition(Position position);
    void setPosition(int column, int row);

    // Getters
    Position getPosition(void);
    Type getType(void);
    Color getColor(void);
};

#endif //CHESS_PIECE_H
