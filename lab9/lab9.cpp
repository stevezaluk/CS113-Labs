#include <iostream>
#include <string>

using namespace std;

char player = 'X';

/*
    In class can you show me how you displayed your rows and columns
    This was the way that I got mine to work.

    I would love to see your code
*/
bool boardFull(char board[3][3]) {
    int boxesFull = 0;
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == 'X' || board[i][j] == 'O') {
                boxesFull++;
            }
        }
    }

    if(boxesFull == 9) {
        return true;
    } else {
        return false;
    }
}

/*
    Really wanted to come up with a better solution for this,
    but i got crunched for time so I decided to use yours.
*/
bool gameWon(char board[3][3], int row, int col) {
    char piece = board[row][col];
    bool won = true;

    // Does row win?
    for (int i = 0; i < 3; i++)
        if (board[row][i] != piece)
        {
            won = false;
            break;
        }
    
    // Does column win?
    if (!won) {

        won = true;
        for (int i = 0; i < 3; i++)
            if (board[i][col] != piece)
            {
                won = false;
                break;
            }
    }

    // Check diagonal
    if (!won && row == col)
    {
        won = true;
        for (int i = 0; i < 3; i++)
            if (board[i][i] != piece)
            {
                won = false;
                break;
            }
    }

    // Check other diagonal
    if (!won && ((row == 0 && col == 2) || (row == 2 && col == 0) || (row == col)) )
    {
        won = true;
        int c = 2;
        for (int i = 0; i < 3; i++) {
            if (board[i][c] != piece)
            {
                won = false;
                break;
            }
            c -= 1;
        }
    }
    return won;
}

void displayBoard(char board[3][3]) {
    for (int x = 0; x < 3; x++) {
        for(int i = 0; i < 3; i++) {
            cout << "+---+";
            if(i == 2) {
                cout << endl;
                for(int j = 0; j < 3; j++) {
                    cout <<  "| " << board[x][j] << " |";
                }
            }
        }
        cout << endl;
    }
    cout << "+---++---++---+" << endl;
}

bool getMove(char board[3][3], int &row, int &col) {
    cout << "Enter Row (1-3): "; // remove UI stuff from here
    cin >> row;

    cout << "Enter Column (1-3): ";
    cin >> col;

    if((row <= 0 || row > 3) || (col <= 0 || col > 3)) { 
        cout << "* Row or column must be 1 through 3" << endl;
        return false;
    } else if(board[row-1][col-1] !=  ' ') {
        cout << "* (" << row << ", " << col << ") is already in use" << endl;
        return false;
    }

    board[row - 1][col - 1] = player;
    displayBoard(board);

    if(gameWon(board, row - 1, col - 1) == true) {
        cout << "* Player " << player << " WINS!!!" << endl;
        return false;
    } else if(boardFull(board) == true) {
        cout << "* Game is a draw" << endl;
        return false;
    }

    if(player == 'O') {
        player = 'X';
    } else {
        player = 'O';
    }

    return true;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    int rowInput = 0;
    int colInput = 0;
    
    do {
        cout << endl << player << "'s Turn" << endl;
    } while(getMove(board, rowInput, colInput));

    return 0;
}
