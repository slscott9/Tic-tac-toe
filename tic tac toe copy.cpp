#include <iostream>
#include <iomanip>
using namespace std;
//globals
const int ROWS = 3, COL = 3;

//prototypes
void Player1Choices(char array[][COL], int rows);
void DisplayGame(char array[][COL], int row);
int playerWins(char array[][COL], int size);
void Player2choice(char array[][COL], int rows);
int ValidateEntry();


int main()
{
    char game_board[ROWS][COL] = {{'*','*','*'}, {'*','*','*'}, {'*','*','*'}};
    int num = 3;

    while(num != 4)
    {   
        Player1Choices(game_board, ROWS);
        if(playerWins(game_board,ROWS)) break;
        
        Player2choice(game_board,ROWS);
        if(playerWins(game_board,ROWS)) break;

        
        
    }
}

//function for player one choice
void Player1Choices(char array[][COL], int rows)
{   
    int user1_choice_row, user1_choice_col;

    cout << "Player 1 enter your choice for row: " << endl;
    user1_choice_row = ValidateEntry();
;
    cout << "Player 1 enter your choice for column: " << endl;
    user1_choice_col = ValidateEntry();
;

    array[user1_choice_row][user1_choice_col] = 'X';
    DisplayGame(array,rows);
    

    
}
void Player2choice(char array[][COL], int rows)
{   
    int user2_choice_row, user2_choice_col;

    cout << "Player 2 enter row: " << endl;
    user2_choice_row = ValidateEntry();
;
    cout << "Player 2 enter column: " << endl;
    user2_choice_col = ValidateEntry();
;

    array[user2_choice_row][user2_choice_col] = 'O';
    DisplayGame(array,rows);
}

//function to display gameboard
void DisplayGame(char array[][COL], int rows)
{
    for(int x = 0; x < ROWS;x++)
    {   
        for (int col = 0; col < COL;col++)
         {   
            cout << setw(4) << array[x][col];
         }
         cout << endl;
    }
}

int playerWins(char array[][COL], int size)
{   
    int player1_count = 0, player2_count = 0, Player1diagonal = 0, player2diagonal = 0;
    //checks rows so go across
    for(int row = 0; row < size;row++)
    {   
        player1_count = 0, player2_count = 0;

        for(int col = 0; col < size;col++)
        {   
           
            if (array[row][col] == 'X')
            {
                player1_count++;
            }
            else if(array[row][col]=='O')
            {
                player2_count++;
            }
            
            
        }
        if (player1_count == 3)
        {
            cout << "Player 1 wins" << endl;
            return 4;
        }
        else if (player2_count == 3)
        {
            cout << "Player 2 wins" << endl;
            return 4;
        }
        
    }
    //check columns so go down
    for (int col = 0; col < size; col++)
    {   
        player1_count = 0, player2_count = 0;

        for (int row = 0; row < size; row++)
        {
            if (array[row][col] == 'X')
            {
                player1_count++;
                
            }
            else if (array[row][col] == 'O')
            {
                player2_count++;
            } 
        }
        if(player1_count == 3)
        {
            cout << "Player 1 wins" << endl;
            return 4;
        }
        else if(player2_count == 3)
        {
            cout << "Player 2 wins." << endl;
            return 4;
        }
    }
    if ((array[0][0] == 'X') && (array[1][1] == 'X') && (array[2][2] == 'X'))
        {
            cout << "Player 1 wins." << endl;
            return 4;
        }
    if ((array[0][0] == 'O') && (array[1][1] == 'O') && (array[2][2] == 'O'))
    {
        cout << "Player 2 wins." << endl;
        return 4;
    }
    if ((array[0][2] == 'X') && (array[1][1] == 'X') && (array[2][0] == 'X'))
    {
        cout << "Player 1 wins." << endl;
        return 4;
    }
    if ((array[0][2] == 'O') && (array[1][1] == 'O') && (array[2][0] == 'O'))
    {
        cout << "Player 2 wins." << endl;
        return 4;
    }
    for(int x = 0; x<size;x++)
    {
        for (int y = 0; y < size; y++)
        {
            if (array[x][y] != '*')
            {
                cout << "The game is a tie.";
                return 4;
            }
        }
    }



    return 0;
}

//input validation
int ValidateEntry()
{
    int num;
    while(!(cin >> num)|| num <0 || num > 2)
    {
        cout << "Error number must be between 0 and 2: ";
        cin.clear();
        cin.ignore(1200, '\n');
    }
    return num;
}




