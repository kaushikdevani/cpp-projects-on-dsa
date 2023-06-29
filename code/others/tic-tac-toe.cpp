#include <iostream>
using namespace std;

char ticks[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void print()
{
    cout << "     |     |     \n";
    cout << "  " << ticks[0][0] << "  |  " << ticks[0][1] << "  |  " << ticks[0][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << ticks[1][0] << "  |  " << ticks[1][1] << "  |  " << ticks[1][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << ticks[2][0] << "  |  " << ticks[2][1] << "  |  " << ticks[2][2] << "  \n";
    cout << "     |     |     \n";
}

bool isValidMove(char selectednum)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (selectednum == ticks[i][j])
            {
                return true;
            }
        }
    }
    return false;
}

bool checkWin(char player)
{
    // Checking rows
    for (int i = 0; i < 3; i++)
    {
        if (ticks[i][0] == player && ticks[i][1] == player && ticks[i][2] == player)
            return true;
    }

    // Checking columns
    for (int j = 0; j < 3; j++)
    {
        if (ticks[0][j] == player && ticks[1][j] == player && ticks[2][j] == player)
            return true;
    }

    // Checking diagonals
    if (ticks[0][0] == player && ticks[1][1] == player && ticks[2][2] == player)
        return true;

    if (ticks[0][2] == player && ticks[1][1] == player && ticks[2][0] == player)
        return true;

    return false;
}

bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (ticks[i][j] != 'x' && ticks[i][j] != 'o')
            {
                return false; 
            }
        }
    }
    return true;
}

int main()
{
    int replayOption = 1;

    while (replayOption == 1)
    {
        // Reset the game board
        ticks[0][0] = '1';
        ticks[0][1] = '2';
        ticks[0][2] = '3';
        ticks[1][0] = '4';
        ticks[1][1] = '5';
        ticks[1][2] = '6';
        ticks[2][0] = '7';
        ticks[2][1] = '8';
        ticks[2][2] = '9';

        print();

        for (int k = 0; k < 9; k++)
        {
            char currentPlayer = (k % 2 == 0) ? 'x' : 'o';
            cout << currentPlayer << " chance, pick a number: ";
            char selectednum;
            cin >> selectednum;

            while (!isValidMove(selectednum))
            {
                cout << "Invalid move! Please select a valid number: ";
                cin >> selectednum;
            }

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (selectednum == ticks[i][j])
                    {
                        ticks[i][j] = currentPlayer;
                    }
                }
            }

            print(); //printing after every move

            if (checkWin(currentPlayer))
            {
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            if (checkDraw())
            {
                cout << "It's a draw!" << endl;
                break;
            }
        }

        cout << "Press 1 if you want to replay: ";
        cin >> replayOption;
    }
    return 0;
}
