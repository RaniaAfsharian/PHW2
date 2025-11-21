#include "game.h"

int main()
{
    string name1, name2;
    char sign1, sign2;

    cout << "--- Tic-Tac-Toe Game Setup ---" << endl;

    cout << "Enter Player 1 Name (X): ";
    getline(cin, name1);
    sign1 = 'X';

    cout << "Enter Player 2 Name (O): ";
    getline(cin, name2);
    sign2 = 'O';

    Player player1(name1, sign1);
    Player player2(name2, sign2);

    Dooz game(player1, player2);

    game.startGame();

    return 0;
}
