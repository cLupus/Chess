#include <iostream>
#include "Board.h"

using namespace std;

int main() {
//    uint *col, *row;
//    char pos[3] = "a8";
//    Position p = Board::position2cr(pos);
//    cout << p.column << p.row << endl;
    Board* board;
    board = new Board();

    board->printBoard();
    return 0;
}