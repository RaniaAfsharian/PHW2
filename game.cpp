#include "game.h"

bool Board::isSlotTaken(int row, int col) const
{
    return board[row][col] != ' ';
}

bool Board::isValidMove(int row, int col) const
{
    if (row < 0 || row > 2 || col < 0 || col > 2)
        return false;
    return !isSlotTaken(row, col);
}

bool Board::makeMove(int row, int col, char player)
{
    if (isValidMove(row, col))
    {
        board[row][col] = player;
        moveCount++;
        return true;
    }
    return false;
}

bool Board::setAction(int row, int col, char player)
{
    if (!isSlotTaken(row, col))
    {
        board[row][col] = player;
        moveCount++;
        return true;
    }
    return false;
}

bool Board::isFull() const
{
    return moveCount == 9;
}

void Board::drawBoard() const
{
    cout << "   0   1   2" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << " " << board[i][j];
            if (j < 2)
                cout << " |";
        }
        cout << endl;
        if (i < 2)
            cout << "  -----------" << endl;
    }
}

bool Board::checkWin(char player) const
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
    }

    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
        {
            return true;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true;
    }

    return false;
}

