#include "board.h"


Board::Board() {
    for (int i = 0; i < NUM_ROWS; ++i){
        for (int j = 0; j < NUM_COLS; ++j){
            data[i][j] = Empty;
        }
    }
    nextPlayer_to_move = Player1;
}

Board::Board(const string &fen) {
    
    int nextCol = 0;
    int stringIndex = 0;
    int valueAmountTotal = 0;
    int num = 0;
    int numx = 0;
    int numo = 0;
    for (int row = 0; row < NUM_ROWS; row++) {
        nextCol = 0;
        valueAmountTotal = 0;
        while (fen[stringIndex] != '/' && stringIndex < fen.length()) {
            while (nextCol < NUM_COLS){
                if(fen[stringIndex] == PLAYER1_TOKEN) {
                    data[row][nextCol] = Player1;
                    nextCol++;
                    numx++;
                }
                
                else if (fen[stringIndex] == PLAYER2_TOKEN) {
                    data[row][nextCol] = Player2;
                    nextCol++;
                    numo++;
                }
                
                else {
                    int value = fen[stringIndex] - '0';
                    valueAmountTotal = valueAmountTotal + value;
                    for(num = 0; num < value; num++){
                        data[row][nextCol] = Empty;
                        ++nextCol;
                    }
                }
                stringIndex++;
            }
            if (nextCol >= NUM_COLS)
                nextCol = 0;
        }
        stringIndex++;
    }
    stringIndex++;
    int count = 0;
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            if (data[i][j] != Empty) {
                count++;
            }
        }
    }
    if (count % 2 == 0) {
        nextPlayer_to_move = Player1;
    }
    else {
        nextPlayer_to_move = Player2;
    }
}

void Board::printBoard_as_FENstring(ostream &os) const {
    Board boardx(string fen);
    char slash = '/';
    int numEmpty = 0;
    int numx = 0;
    int numo = 0;
    for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
            if (data[i][j] == Empty){
                numEmpty++;
            }
            
            else if (data[i][j] == Player1) {
                if (numEmpty != 0){
                    os << numEmpty << 'x';
                }
                else if (numEmpty == 0) {
                    os << 'x';
                }
                numEmpty = 0;
                numx++;
                toMove();
            }
            else if (data[i][j] == Player2){
                if (numEmpty != 0){
                    os << numEmpty << 'o';
                }
                else if (numEmpty == 0){
                    os << 'o';
                }
                numEmpty = 0;
                numo++;
                toMove();
            }
        }
        if (i == NUM_ROWS -1) {
            os << numEmpty;
        }
        else {
            os << numEmpty << slash;
        }
        numEmpty = 0;
    }
    
    if (toMove() == 1){
        os << " " << 'x';
    }
    
    if (toMove() == 2){
        os << " " << 'o';
    }
    
    os << endl;
}

PieceType Board::atLocation(int row, int col) {
    return data[row][col];
}

void Board::prettyPrintBoard(ostream &os) const {
    os << endl;
    for (int row = NUM_ROWS - 1; row >= 0; row--)  {
        os << "     +---+---+---+---+---+---+---+"
        << endl
        << "    ";
        
        for (int col = 0; col < NUM_COLS; col++)   {
            os << " | " ;
            if ( data[row][col] == Player1)
                os <<  PLAYER1_TOKEN;
            else if (data[row][col] == Player2)
                os << PLAYER2_TOKEN;
            else
                os << EMPTY_TOKEN;
        }
        os << " |" << endl;
    }
    os << "     +---+---+---+---+---+---+---+" << endl
    <<"  col  1   2   3   4   5   6   7" << endl;
    return;
}

int Board::toMove() const {
    int numMoves = 0;
    for (int i = 0; i < NUM_ROWS; ++i){
        for (int j = 0; j < NUM_COLS; ++j){
            if ( data[i][j] != Empty){
                numMoves++;
            }
        }
    }
    
    if (numMoves % 2 == 0){
        return 1;
    }
    return 2;
}

Result Board::makeMove(int col) {
    int firstFreeRow = getFirstFreeRow(col);
    if (firstFreeRow == NUM_ROWS) {
        return IllegalMove;
    }
    updateToMove();
    data[firstFreeRow][col] = nextPlayer_to_move;
    if (isWin(firstFreeRow, col)) {
        return Win;
    }
    else if (isBoardFull()) {
        return Draw;
    }
    return NoResult;
}

int Board::getFirstFreeRow(int col) const {
    
    for (int row = 0; row < NUM_ROWS; ++row){
        if (data[row][col] == Empty){
            return row;
        }
    }
    return NUM_ROWS;
}

PieceType Board::updateToMove() {
    int numMoves = 0;
    for (int i = 0; i < NUM_ROWS; ++i){
        for (int j = 0; j < NUM_COLS; ++j){
            if (data[i][j] == Player1 || data[i][j] == Player2) {
                ++numMoves;
            }
        }
    }
    
    if (numMoves % 2 == 0){
        nextPlayer_to_move = Player1;
        return Player2;
    }
    else if (numMoves % 2 != 0){
        nextPlayer_to_move = Player2;
    }
    return Player1;
}

bool Board::isBoardFull() const {
    
    int count = 0;
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            if(data[row][col] == Empty) {
                count++;
            }
        }
    }
    
    if (count != 0) {
        return false;
    }
    return true;
}

bool Board::inBounds(int row, int col) const {
    if (row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS) {
        return true;
    }
    return false;
}

int Board::piecesInDirection(int row, int col, int dRow, int dCol) const {
    int count = 0;
    int i = row;
    int j = col;
    while ((inBounds(i, j)) && (data[i][j] == data[row][col])) {
        i += dRow;
        j += dCol;
        if ((data[i][j] == data[row][col]) && (inBounds(i, j))) {
            count++;
        }
    }
    return count;
}

bool Board::isWin(int row, int col) const {
    int right = piecesInDirection(row, col, 0, 1);
    int left = piecesInDirection(row, col, 0, -1);
    int up = piecesInDirection(row, col, 1, 0);
    int down = piecesInDirection(row, col, -1, 0);
    int downLeft = piecesInDirection(row, col, -1, -1);
    int upRight = piecesInDirection(row, col, 1, 1);
    int upLeft = piecesInDirection(row, col, 1, -1);
    int downRight = piecesInDirection(row, col, -1, 1);
    if ((right + left) >= 3) {
        return true;
    }
    else if ((up + down) >= 3) {
        return true;
    }
    else if ((upRight + downLeft) >= 3) {
        return true;
    }
    else if ((upLeft + downRight) >= 3) {
        return true;
    }
    return false;
}
