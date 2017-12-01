#include<iostream>
#include "board.h"

using namespace std;

// Test suite for the Board class
// We highly encourage that you implement these functions
// using your test cases for each function to make sure 
// that your Board functions comply RMEs.

void test_default_Constructor();
void test_non_default_Constructor();
void test_fenString_Constructor();
void test_printBoard_as_FENstring();
void test_toMove();
void test_makeMove();
void test_getFirstFreeRow();
void test_updateToMove();
void test_isBoardFull();
void test_inBounds();
void test_piecesInDirection();
void test_isWin();

//int main() {
//    test_default_Constructor();
//    test_non_default_Constructor();
//    test_fenString_Constructor();
//    test_printBoard_as_FENstring();
//    test_toMove();
//    test_makeMove();
//    test_getFirstFreeRow();
//    test_updateToMove();
//    test_isBoardFull();
//    test_inBounds();
//    test_piecesInDirection();
//    test_isWin();
//
//    return 0;
//}

// Sample test case for the default constructor
void test_default_Constructor() {
    cout << "Begin testing for Default Constructor:" << endl;
    Board board;
    board.prettyPrintBoard(cout);
    cout << endl;
    cout << "Finish testing for Default Constructor." << endl << endl;
}

void test_non_default_Constructor() {
    cout << "Begin testing for Non Default Constructor:" << endl;
    Board board("7/7/7/7/7/7");
    board.prettyPrintBoard(cout);
    cout << endl;
    
    Board fenBoard1("1xoox2/7/7/7/7/7");
    fenBoard1.prettyPrintBoard(cout);
    cout << endl;
    
    Board fenBoard2("1xoox2/2xxo2/3o3/7/7/7");
    fenBoard2.prettyPrintBoard(cout);
    cout << endl;
    
    Board fenBoard3("1xoox2/2xxo2/3o3/o7/6x/7");
    fenBoard3.prettyPrintBoard(cout);
    cout << endl;
    cout << "Finish testing for Non Default Constructor." << endl << endl;

}

void test_fenString_Constructor() {
    cout << "Testing non-default constructor" << endl;
    Board board("7/7/7/7/7/7");
    board.prettyPrintBoard(cout);
    cout << endl;

    Board fenBoard1("1xoox2/7/7/7/7/7");
    fenBoard1.prettyPrintBoard(cout);
    cout << endl;

    Board fenBoard2("1xoox2/2xxo2/3o3/7/7/7");
    fenBoard2.prettyPrintBoard(cout);
    cout << endl;

    Board fenBoard3("1xoox2/2xxo2/3o3/o7/6x/7");
    fenBoard3.prettyPrintBoard(cout);
    cout << endl;
}

void test_printBoard_as_FENstring() {
    cout << "Begin testing for Print Board as FEN String:" << endl;
    
    Board board;
    cout << "Should be 7/7/7/7/7/7 x: ";
    board.printBoard_as_FENstring(cout);
    
    Board board1("1xoox2/7/7/7/7/7");
    cout << "Should be 1xoox2/7/7/7/7/7 x: ";
    board1.printBoard_as_FENstring(cout);
    
    Board board2("1xoox2/2xxo2/3o3/7/7/7");
    cout << "Should be 1xoox2/2xxo2/3o3/7/7/7 x: ";
    board2.printBoard_as_FENstring(cout);
    
    Board board3("1xoox2/2xxo2/3o3/3x3/7/7");
    cout << "Should be 1xoox2/2xxo2/3o3/3x3/7/7 o: ";
    board3.printBoard_as_FENstring(cout);
    
    Board board4("1xoox2/2xxo2/3o3/3x3/ox5/7");
    cout << "Should be 1xoox2/2xxo2/3o3/3x3/ox5/7 o: ";
    board4.printBoard_as_FENstring(cout);
    
    Board board5("x2xoo/x2oox/x2oxo/x6/7/7");
    cout << "Should be x2xoo/x2oox/x2oxo/x6/7/7 o: ";
    board5.printBoard_as_FENstring(cout);
    
    cout << "Finish testing for Print Board as FEN String." << endl << endl;
}

void test_updateToMove() {
    cout << "Begin testing for Update to Move:" << endl;
    
    // test #1 - test updateToMove after the first move of the game
    Board test_board1;
    int updateToMove = 0;
    cout << "Should print 2: ";
    if (test_board1.toMove() == 1) {
        updateToMove = 2;
    }
    else if (test_board1.toMove() == 2) {
        updateToMove = 1;
    }
    cout << updateToMove << endl;
    
    /* test #2 - test whether updateToMove updates effectively using toMove (opposite return value) */
    Board test_board2;
    test_board2.makeMove(3);
    cout << "Should print 1: ";
    if (test_board2.toMove() == 1) {
        updateToMove = 2;
    }
    else if (test_board2.toMove() == 2) {
        updateToMove = 1;
    }
    cout << updateToMove << endl;
    
    /* test #3 - test whether updateToMove updates effectively after being called twice using toMove (opposite return value) */
    test_board2.makeMove(2);
    cout << "Should print 2: ";
    if (test_board2.toMove() == 1) {
        updateToMove = 2;
    }
    else if (test_board2.toMove() == 2) {
        updateToMove = 1;
    }
    cout << updateToMove << endl;
    
    /* test #4 - test whether updateToMove updates accordingly to a board
                 created from a FEN string (specifically to # of x's and o's) */
    Board test_board3("3xo1x/3x3/3o3/7/7/7");
    cout << "Should print 1: ";
    if (test_board3.toMove() == 1) {
        updateToMove = 2;
    }
    else if (test_board3.toMove() == 2) {
        updateToMove = 1;
    }
    cout << updateToMove << endl;
    
    cout << "Finish testing for Update to Move." << endl << endl;
}

void test_toMove() {
    cout << "Begin testing for To Move:" << endl;
    
    // test #1 - following start of game
    Board test_board1;
    cout << "Should print 1: " << test_board1.toMove() << endl;
    // test #2 - FEN string during Player 2's turn
    Board test_board2("3x3/7/7/7/7/7");
    cout << "Should print 2: " << test_board2.toMove() << endl;
    // test #3 - FEN string during Player 1's turn
    Board test_board3("3xo1x/3xo2/3o3/7/7/7");
    cout << "Should print 1: " << test_board3.toMove() << endl;
    
    cout << "Finish testing for To Move." << endl << endl;
}

void test_makeMove() {
    cout << "Begin testing for Make Move:" << endl;
    
    // construct a late-in-the-game board
    Board test_board1("xxoxoox/1xooxoo/1oxxx2/1xxoo2/2ooo2/2x1x2");
    
    // NoResult
    cout << "Should print 3: " << test_board1.makeMove(6) << endl;
    cout << "Should print 3: " << test_board1.makeMove(0) << endl;
    cout << "Should print 3: " << test_board1.makeMove(0) << endl;
    cout << "Should print 3: " << test_board1.makeMove(0) << endl;
    cout << "Should print 3: " << test_board1.makeMove(0) << endl;
    cout << "Should print 3: " << test_board1.makeMove(3) << endl;
    
    // IllegalMove
    cout << "Should print 0: " << test_board1.makeMove(2) << endl;
    cout << "Should print 0: " << test_board1.makeMove(3) << endl;
    cout << "Should print 0: " << test_board1.makeMove(4) << endl;
    
    // Win
    cout << "Should print 2: " << test_board1.makeMove(1) << endl;
    cout << "Should print 2: " << test_board1.makeMove(5) << endl;
    
    // NoResult
    cout << "Should print 3: " << test_board1.makeMove(5) << endl;
    cout << "Should print 3: " << test_board1.makeMove(6) << endl;
    cout << "Should print 3: " << test_board1.makeMove(5) << endl;
    cout << "Should print 3: " << test_board1.makeMove(6) << endl;
    cout << "Should print 3: " << test_board1.makeMove(5) << endl;
    cout << "Should print 3: " << test_board1.makeMove(6) << endl;
    
    // Win
    cout << "Should print 2: " << test_board1.makeMove(0) << endl;
    
    // Draw
    cout << "Should print 1: " << test_board1.makeMove(1) << endl;
    Board test_board2("xoxoxox/xoxoxox/oxoxoxo/oxoxoxo/xoxoxox/xoxoxo1");
    cout << "Should print 1: " << test_board2.makeMove(6) << endl;
    
    cout << "Finish testing for Make Move." << endl << endl;
}

void test_isWin() {
    cout << "Begin testing for Is Win:" << endl;
    
    // testing various outputs for a winning move
    cout << "The following tests should indicate a Win by printing 2:" << endl;
    
    // test #1
    cout << "Test #1: ";
    Board test_board1("xo5/xo5/xo5/7/7/7");
    cout << test_board1.makeMove(0) << ", ";
    cout << test_board1.makeMove(1) << endl;
    
    // test #2
    cout << "Test #2: ";
    Board test_board2("xooo1o1/oxxx1o1/xxx2o1/oxx4/7/7");
    cout << test_board2.makeMove(4) << ", ";
    cout << test_board2.makeMove(2) << ", ";
    cout << test_board2.makeMove(5) << ", ";
    cout << test_board2.makeMove(3) << endl;
    
    cout << "The following tests should indicate a NoResult by printing 3:";
    cout << endl;
    
    // test #3
    cout << "Test #3: ";
    cout << test_board2.makeMove(1) << ", ";
    cout << test_board2.makeMove(6) << ", ";
    cout << test_board2.makeMove(0) << ", ";
    cout << test_board2.makeMove(1) << endl;

    // test #4
    cout << "Test #4: ";
    Board test_board3;
    cout << test_board3.makeMove(1) << ", ";
    cout << test_board3.makeMove(5) << ", ";
    cout << test_board3.makeMove(6) << ", ";
    cout << test_board3.makeMove(6) << ", ";
    cout << test_board3.makeMove(2) << endl;
    
    cout << "Finish testing for Is Win." << endl << endl;
}

void test_getFirstFreeRow() {
    cout << "Begin testing for Get First Free Row:" << endl;
    
    // construct a board to force getFirstFreeRow() to extract every row value
    Board test_board1("xooxxo1/1xxoox1/2oxxo1/3oox1/4ox1/5o1");
    /* for each column, show 1st that there is no piece in the given spot
       then, show that a piece gets placed there once a move gets made in that
       that column; this shows the accuracy of getFirstFreeRow() */
    cout << "Should print 0: " << test_board1.atLocation(1, 0) << endl;
    test_board1.makeMove(0);
    cout << "Should print 2: " << test_board1.atLocation(1, 0) << endl;
    
    cout << "Should print 0: " << test_board1.atLocation(2, 1) << endl;
    test_board1.makeMove(1);
    cout << "Should print 1: " << test_board1.atLocation(2, 1) << endl;
    
    cout << "Should print 0: " << test_board1.atLocation(3, 2) << endl;
    test_board1.makeMove(2);
    cout << "Should print 2: " << test_board1.atLocation(3, 2) << endl;
    
    cout << "Should print 0: " << test_board1.atLocation(4, 3) << endl;
    test_board1.makeMove(3);
    cout << "Should print 1: " << test_board1.atLocation(4, 3) << endl;
    
    cout << "Should print 0: " << test_board1.atLocation(5, 4) << endl;
    test_board1.makeMove(4);
    cout << "Should print 2: " << test_board1.atLocation(5, 4) << endl;
    
    cout << "Should print 0: " << test_board1.makeMove(5) << endl;
    
    cout << "Should print 0: " << test_board1.atLocation(0, 6) << endl;
    test_board1.makeMove(6);
    cout << "Should print 1: " << test_board1.atLocation(0, 6) << endl;
 
    cout << "Finish testing for Get First Free Row." << endl << endl;
}

void test_piecesInDirection() {
    cout << "Begin testing for Pieces in Direction:" << endl;
    
    Board test_board1("x1o1oxo/2x1oox/2x2x1/7/7/7");
    
    /* test by making moves that test multiple different directions, focus
       first on values that don't cause a win */
    cout << "The following tests should indicate a NoResult by printing 3: " << endl;
    cout << test_board1.makeMove(0) << ", ";
    cout << test_board1.makeMove(1) << ", ";
    cout << test_board1.makeMove(3) << ", ";
    cout << test_board1.makeMove(6) << ", ";
    cout << test_board1.makeMove(4) << ", ";
    cout << test_board1.makeMove(1) << ", ";
    cout << test_board1.makeMove(3) << ", ";
    cout << test_board1.makeMove(2) << ", ";
    cout << test_board1.makeMove(0) << ", ";
    cout << test_board1.makeMove(4) << endl;
    test_board1.prettyPrintBoard(cout);

    
    /* then test values that do cause a win, including those forced to count
       greater numbers of pieces and those near the edges of the board */
    cout << "The following tests should indicate a Win by printing 2: " << endl;
    cout << test_board1.makeMove(5) << ", ";
    cout << test_board1.makeMove(2) << ", ";
    test_board1.makeMove(0);
    test_board1.makeMove(6);
    cout << test_board1.makeMove(6) << ", ";
    cout << test_board1.makeMove(2) << ", ";
    cout << test_board1.makeMove(0) << ", ";
    cout << test_board1.makeMove(3) << ", ";
    cout << test_board1.makeMove(0) << ", ";
    test_board1.makeMove(6);
    test_board1.makeMove(1);
    cout << test_board1.makeMove(5) << ", ";
    test_board1.makeMove(3);
    cout << test_board1.makeMove(3) << endl;
    test_board1.prettyPrintBoard(cout);
    
    cout << "Finish testing for Pieces in Direction." << endl << endl;
}

void test_isBoardFull() {
    cout << "Begin testing for Is Board Full:" << endl;
    // test #1 - after first move, when board is empty
    Board test_board1;
    cout << "Should indicate a NoResult by printing a 3: ";
    cout << test_board1.makeMove(3) << endl;
    
    // test #2 - test when board is nearly full
    Board test_board2("xoxoxox/xoxoxox/oxoxoxo/oxoxoxo/xoxoxox/xoxoxo1");
    
    // test #3 - test when board is full
    cout << "Should indicate a Draw by printing 1: " << test_board2.makeMove(6) << endl;
    cout << "Should indicate an IllegalMove by printing 0: ";
    cout << test_board2.makeMove(6) << endl;
    
    // test #4 - test when winning move fills the board
    Board test_board3("oxoxxox/oxooxox/xoxoxxo/xoxxoxo/oxoxoxo/oxoo1ox");
    cout << "Should indicate a Win by printing a 2: ";
    cout << test_board3.makeMove(4) << endl;
    
    cout << "Finish testing for Is Board Full." << endl << endl;
}

void test_inBounds() {
    cout << "Begin testing for In Bounds:" << endl;
    
    Board test_board1;
    Board test_board2("oxoxxox/oxooxox/xoxoxxo/xoxxoxo/2oxoxo/2xooo1");
    
    // test #1 - regular move at boundary in middle of board
    cout << "Should indicate a NoResult by printing a 3: ";
    cout << test_board2.makeMove(1) << endl;
    
    // test #2 - move at boundary when when col = 0
    cout << "Should indicate a NoResult by printing a 3: ";
    cout << test_board2.makeMove(0) << endl;
    
    // test #3 - move at boundary when row = 0 (different board than rest of tests)
    cout << "Should indicate a NoResult by printing a 3: ";
    cout << test_board1.makeMove(0) << endl;
    
    // test #4 - move on the corner
    cout << "Should indicate a NoResult by printing a 3: ";
    cout << test_board2.makeMove(0) << endl;
    
    // test #5 - move at boundary when row = 6
    cout << "Should indicate a NoResult by printing a 3: ";
    cout << test_board2.makeMove(1) << endl;
    
    // test #6 - Player2 winning with the last move on a corner
    cout << "Should indicate a Win by printing a 2: ";
    cout << test_board2.makeMove(6) << endl;
    
    cout << "Finish testing for In Bounds." << endl << endl;
}
