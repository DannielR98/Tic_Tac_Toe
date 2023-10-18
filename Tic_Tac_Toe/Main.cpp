
#include <iostream>
#include <stdlib.h>

using namespace std;

char Map[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };

int blockerino;
char turn = 'X';
int row = 0;
int column = 0;
bool draw = false;


void displayerino_boarderino() {
    cout << "      |      |      " << endl;
    cout << "  " << Map[0][0] << "   |  " << Map[0][1] << "   |  " << Map[0][2] << endl;
    cout << "______|______|______" << endl;
    cout << "      |      |      " << endl;

    cout << "   " << Map[1][0] << "     " << Map[1][1] << "      " << Map[1][2] << endl;

    cout << "______|______|______" << endl;
    cout << "      |      |      " << endl;

    cout << "   " << Map[2][0] << "     " << Map[2][1] << "      " << Map[2][2] << endl;
    cout << "      |      |      " << endl;
}

void switcherino() {
    cin >> blockerino;
    switch (blockerino)
    {
    case 1:
        row = 0;
        column = 0;
        break;

    case 2:
        row = 0;
        column = 1;
        break;

    case 3:
        row = 0;
        column = 2;
        break;

    case 4:
        row = 1;
        column = 0;
        break;

    case 5:
        row = 1;
        column = 1;
        break;

    case 6:
        row = 1;
        column = 2;
        break;

    case 7:
        row = 2;
        column = 0;
        break;

    case 8:
        row = 2;
        column = 1;
        break;

    case 9:
        row = 2;
        column = 2;
        break;

    default:
        cout << "Choose a valid number" << endl;
        switcherino();
    }

}

void switcherino_blockerinoX() {

    if (turn == 'X')
    {
        cout << "Player 1's turn (X): " << endl;
    }
    else if (turn =='O')
    {
        cout << "Player 2's turn (O): " << endl;
    }
    



    switcherino();

    if (turn == 'X' && Map[row][column] != 'O' && Map[row][column] != 'X')
    {

        Map[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && Map[row][column] != 'O' && Map[row][column] != 'X')
    {
        Map[row][column] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "Choose valid number" << endl;
        switcherino_blockerinoX();
    }

    



}




bool is_game_over() {
     for (int i = 0; i < 3; i++)
         if (Map[i][0] == Map[i][1] && Map[i][0] == Map[i][2] || Map[0][i] == Map[1][i] && Map[0][i] == Map[2][i])
         {
             return false;
         }
     if (Map[0][0] == Map[1][1] && Map[0][0] == Map[2][2] || Map[0][2] == Map[1][1] && Map[0][2] == Map[2][0])
     {
         return false;
     }

     for (int i = 0; i < 3; i++)
     {
         for (int j = 0; j < 3; j++)
         {
             if (Map[i][j] != 'X' && Map[i][j] != 'O')
             {
                 return true;
             }
         }
     }

     draw = true;
     return false;
}

int main()
{
    cout << "Prepare for the best game in history" << endl;

   

    


    while (is_game_over()) {
        displayerino_boarderino();
        switcherino_blockerinoX();
        is_game_over();
    }
    

    if (turn == 'X' && draw == false) {
        cout << "Congrats! " << endl;
        cout << "O lost" << endl;
    }
    else if (turn == 'O' && draw == false)
    {
        cout << "Congrats! " << endl;
        cout << "X lost" << endl;
    }
    else
    {
        cout << "Game is a draw" << endl;
    }

    displayerino_boarderino();
    system("pause");
 
    
 
    
    

    


    return 0;
}
