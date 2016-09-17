//
// Created by Sindre Nistad on 6/19/16.
//

#include <cassert>
#include "Piece.h"

using namespace std;

bool Piece::canMovePawn(Board* board, std::string move_to){

}

bool Piece::canMove(Board* board, std::string move_to) {
    switch (Piece::type){
        case Type::pawn:
            // First move: move one or two up (or down)
            break;
        case Type::knight:
            break;
        case Type::bishop:
            break;
        case Type::rook:
            break;
        case Type::king:
            break;
        case Type::queen:
            break;
        default:
            return false;
    }
};

void Piece::setPosition(Position pos){
    this->position = pos;
}

void Piece::setPosition(int column, int row) {
    this->position = Position(row, column);
}

Piece::Piece(Type t, Color c, int column, int row) {
    Piece::Piece(t, c, Position(row, column));
}

Piece::Piece(Type t, Color c, Position position) {
    this->type = t;
    this->color = c;
    this->position = position;
}

//Piece::Piece(Type t, Color c) {
//    this->type = t;
//    this->color = c;
//    this->position = NULL;
//}

Piece::Piece() {
    this->type = Type::none;
    this->position = NULL;
}

Piece::~Piece() {
//    delete this->position;
//    delete this->type;
//    delete this->color;
//    delete this->hasMoved;
//    delete this;
}

Position Piece::getPosition(void) {
    return this->position;
}

Type Piece::getType(void) {
    return type;
}

Color Piece::getColor(void) {
    return color;
}

char Piece::to_string() {
    if (this == nullptr || this == NULL) return ' ';
    switch (this->getType()) {
        case Type::pawn:
            return (this->getColor() == Color::black) ? PAWNBLACK : PAWNWHITE;
        case Type::knight:
            return (this->getColor() == Color::black) ? KNIGHTBLACK : KNIGHTWHITE;
        case Type::bishop:
            return (this->getColor() == Color::black) ? BISHOPBLACK : BISHOPWHITE;
        case Type::rook:
            return (this->getColor() == Color::black) ? ROOKBLACK : ROOKWHITE;
        case Type::queen:
            return (this->getColor() == Color::black) ? QUEENBLACK : QUEENWHITE;
        case Type::king:
            return (this->getColor() == Color::black) ? KINGBLACK : KINGWHITE;
        default:
            return ' ';
    }
}

/*
 * Implementation of the Position class
 */

Position::Position(int row, int column){
    assert(0 <= row && row < BOARDSIZE);
    assert(0 <= column && column < BOARDSIZE);

    char letter = column + 'a';
    char number = row + '1';
    char p[3] = {letter, number, '\0'};


    this->row = row;
    this->column = column;
    this->position = p;
}

Position::Position(std::string position) {
    int letter =  position[0] - 'a';
    int number =  position[1] - '1'; // In chess, it goes from 1 - 8.

    assert(0 <= letter && letter < BOARDSIZE);
    assert(0 <= number && number < BOARDSIZE);

    this->column = letter;
    this->row = number;
    this->position = position;
}

int Position::getColumn() {
    return this->column;
}

int Position::getRow() {
    return this->row;
}

std::string Position::getPosition() {
    return this->position;
}

Position::Position() {

}
