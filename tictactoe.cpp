#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displayBoard(const vector<vector<char>>& board) {
    cout << "\nTic-Tac-Toe Board:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << " " << board[i][j];
            if (j < 2) cout << " |";
        }
        cout << endl;
        if (i < 2) cout << "---+---+---" << endl;
    }
    cout << endl;
}


bool checkWin(const vector<vector<char>>& board, char player) {

    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}


bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}


void resetBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}


int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameRunning = true;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (gameRunning) {
        resetBoard(board);
        bool gameOver = false;

        while (!gameOver) {
            displayBoard(board);
            cout << "Player " << currentPlayer << ", enter your move (row and column: 1-3): ";
            int row, col;
            cin >> row >> col;


            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
                cout << "Invalid move. Try again." << endl;
                continue;
            }


            board[row - 1][col - 1] = currentPlayer;


            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            } else if (checkDraw(board)) {
                displayBoard(board);
                cout << "The game is a draw!" << endl;
                gameOver = true;
            } else {

                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }


        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if (playAgain == 'n' || playAgain == 'N') {
            gameRunning = false;
            cout << "Thanks for playing Tic-Tac-Toe!" << endl;
        } else {
            currentPlayer = 'X';
        }
    }

    return 0;
}
