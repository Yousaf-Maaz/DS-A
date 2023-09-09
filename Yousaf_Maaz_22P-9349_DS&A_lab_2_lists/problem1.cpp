/*1. Write a program that simulates a simple collision detection game. Create a 2D
grid of 3x3 that represents the game world. Each cell can contain either a
reward or a collision object. Randomly populate the array with either – or x,
where – represents a safe place, and x represents a collision object. However,
at the start of the game, the player must be located in the middle of the grid.
So, the character at the middle the grid should be o. If the player moves to a
cell containing a reward, he won, so display the message “Yayy, you won, it
was a reward”. But if that cell contained a collision object, the player will die,
so display the message “You lost, it was a collision object”. Implement
movement of a player within the grid using pointers. The valid moves for
a player are either top, bottom, left, and right.*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int sizeofmatrix = 3;

    char Array[sizeofmatrix][sizeofmatrix];

    char *movepoint = &Array[1][1]; 
    *movepoint = 'o';

    srand(time(0)); // random

    for (int i = 0; i < sizeofmatrix; ++i)
    {
        for (int j = 0; j < sizeofmatrix; ++j)
        {
            char *curr = &Array[i][j];
            if (*curr != 'o')
            {
                if (rand() % 2 == 0)
                {
                    *curr = '-';
                }
                else
                {
                    *curr = 'x';
                }
            }
        }
    }

    while (true)
    {
        for (int i = 0; i < sizeofmatrix; ++i)
        {
            for (int j = 0; j < sizeofmatrix; ++j)
            {
                cout << Array[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Enter move left: " << endl;
        cout << "Enter move right: " << endl;
        cout << "Enter move top: " << endl;
        cout << "Enter move bottom: " << endl;
        string enter;
        cin >> enter;

        char *newPlayerPos = movepoint;

        if (enter == "top")
        {
            newPlayerPos -= sizeofmatrix;
        }
        else if (enter == "left")
        {
            newPlayerPos--;
        }
        else if (enter == "bottom")
        {
            newPlayerPos += sizeofmatrix;
        }
        else if (enter == "right")
        {
            newPlayerPos++;
        }
        else
        {
            cout << "Invalid move." << endl;
            continue;
        }

        if (newPlayerPos < &Array[0][0] || newPlayerPos >= &Array[sizeofmatrix][sizeofmatrix])
        {
            cout << "Invalid move. " << endl;
            continue;
        }

        if (*newPlayerPos == 'x')
        {
            cout << "You lost, it was a collision object." << endl;
            break;
        }
        else if (*newPlayerPos == '-')
        {
            *movepoint = '-';
            *newPlayerPos = 'o';
            movepoint = newPlayerPos;
            cout << "Yayy, you won, it was a reward." << endl;
        }
        else
        {

            break;
        }
    }

    return 0;
}
