bool gameWon(char board[3][3], int row, int col)
{
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