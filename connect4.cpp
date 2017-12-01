#include "connect4.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

Board getBoard(string &p1, string &p2);

void terminalPlay(){
    string P1;
    string P2;
    char j;
    int i;
    Board a = getBoard(P1, P2);
    bool done = false;
    while (!done) {
        a.prettyPrintBoard(cout);
        cout << "\nEnter: the column to move, q to quit, s to save" << endl;
        if (a.toMove() == 1) {
            cout << P1 << " enter your move: ";
        }
        else {
            cout << P2 << " enter your move: ";
        }
        cin >> i;
        if (cin.good()) {
            if (i > NUM_COLS || i < 1) {
                cout << "ILLEGAL MOVE: Try again" << endl;
            }
            else if (i <= NUM_COLS && i >= 1) {
                int move = i - 1;
                Result result = a.makeMove(move);
                if (result == IllegalMove) {
                    cout << "ILLEGAL MOVE: Try again" << endl;
                }
                else if (result == Win) {
                    if (a.makeMove(move) == 1) {
                        cout << "Congratulations " << P1 << "! You won!" << endl;
                    }
                    else {
                        cout << "Congratulations " << P2 << "! You won!" << endl;
                    }
                    done = true;
                    a.prettyPrintBoard(cout);
                }
                else if (result == Draw) {
                    cout << "Draw!" << endl;
                    done = true;
                    a.prettyPrintBoard(cout);
                }
                else if (result == NoResult) {
                }
            }
        }
        else {
            cin.clear();
            cin >> j;
            if (j == 's') {
                saveBoard(P1, P2, a);
            }
            else if (j == 'q') {
                cout << "Thanks for playing!" << endl;
                done = true;
            }
            else {
                cout << "ILLEGAL MOVE: Try again" << endl;
            }
        }
    }
}

Board getBoard(string &p1, string &p2) {
    cout << "Enter L to load a game, or P to play: " << flush;
    Board a;
    string j, fen;
    cin >> j;
    if (j == "P" || j == "p") {
        cout << "Player 1, enter your name: " << flush;
        getline(cin, p1);
        getline(cin, p1);
        cout << endl << "Player 2, enter your name: " << flush;
        getline(cin, p2);
        a = Board();
    }
    else if (j == "L" || j == "l") {
        cout << "Enter the filename: " << flush;
        ifstream file;
        string fileName;
        cin >> fileName;
        file.open(fileName.c_str());
        getline(file, p1);
        getline(file, p2);
        getline(file, fen);
        a = Board(fen);
    }
    cout << endl;
    return a;
}

void saveBoard(string p1, string p2, const Board &board) {
    cout << "Enter the filename: " << flush;
    ofstream file;
    string fileName = "";
    cin >> fileName;
    file.open(fileName.c_str());
    file << p1 << endl;
    file << p2 << endl;
    board.printBoard_as_FENstring(file);
}

