#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

using namespace std;

class Board
{
private:
    char board[3][3]{{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int moveCount = 0;

public:
    bool isSlotTaken(int row, int col) const;
    bool isValidMove(int row, int col) const;
    bool makeMove(int row, int col, char player);
    bool setAction(int row, int col, char player);
    bool isFull() const;
    void drawBoard() const;
    bool checkWin(char player) const;
};

class Player
{
private:
    string name;
    char sign;

public:
    Player(string name, char sign);
    void setName(string pname);
    string getName() const;
    char getSign() const;
};

class Dooz
{
private:
    Board board;
    Player player1;
    Player player2;
    Player *currentPlayer;

public:
    Dooz(const Player &p1, const Player &p2);
    void switchTurn();
    void startGame();
};

#endif
