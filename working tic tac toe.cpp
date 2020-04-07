#include <iostream>
#include <iomanip>
using namespace std;
//constants
const int ROWS = 3, COLS = 3;
//prototypes
bool switchFunc(int user_choice, int *ptrRow, int *ptrCol, char board[ROWS][COLS]);
void GetChoice(bool *ptrTurn, int *ptrRow, int *ptrCol, char board[ROWS][COLS]);
void DisplayBoard(char gameBoard[ROWS][COLS]);
bool checkWinner(char board[ROWS][COLS]);
bool Tie(char board[ROWS][COLS]);

int main()
{
    char game_board[ROWS][COLS] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}}; 

    int row, col;
    bool Turn = true; // true for p1 choice false for p2 choice
    bool filled = false;
    bool gameOver = false;
    int user_choice;

    //pointers
    int *ptrRow = &row;
    int *ptrCol = &col;
    bool *ptrTurn = &Turn;

    do
    {   
        cout << endl << endl;

        DisplayBoard(game_board);
        GetChoice(ptrTurn, ptrRow, ptrCol, game_board);
   
        if (filled == false && Turn == true)
        {
            game_board[row][col] = 'X';
            Turn = false;
        }
        else if(filled == false && Turn == false)
        {
            game_board[row][col] = 'O';
            Turn = true;
        }

        gameOver = checkWinner(game_board);
        if (gameOver == false)
        {
            gameOver = Tie(game_board);

        }

        
      
    } while (gameOver == false);
    DisplayBoard(game_board);

}

void GetChoice(bool *ptrTurn, int *ptrRow, int *ptrCol, char board[ROWS][COLS])
{
    int choice;
    bool filled = false;
    
        if (*ptrTurn == true)
        {   
            do
            {
                cout << "Player 1 enter choice [X]: ";
                cin >> choice;
                filled = switchFunc(choice, ptrRow, ptrCol, board);
                if (filled == true)
                {
                    cout << "spot taken." << endl;
                    cin.clear();
                    cin.ignore(1200, '\n');
                }            
            } while (filled == true);
            
            
            
            
        }
        else if (*ptrTurn == false)
        {
            do
            {
                cout << "Player 2 enter choice [O]: ";
                cin >> choice;
                filled = switchFunc(choice, ptrRow, ptrCol, board);
                if (filled == true)
                {
                    cout << "spot taken." << endl;
                    cin.clear();
                    cin.ignore(1200, '\n');
                }            
            } while (filled == true);          
        }
    
}

bool switchFunc(int user_choice, int *ptrRow, int *ptrCol, char board[ROWS][COLS])
{   
    bool filled = false;
    switch (user_choice)
    {
    case 1: *ptrRow = 0; *ptrCol = 0;
        /* code */
        break;
    case 2: *ptrRow = 0; *ptrCol = 1;
        break;
    case 3: *ptrRow = 0; *ptrCol = 2;
        break;
    case 4: *ptrRow = 1; *ptrCol = 0;
        break;
    case 5: *ptrRow = 1; *ptrCol =1;
        break;
    case 6: *ptrRow = 1; *ptrCol =2;
        break;
    case 7: *ptrRow = 2; *ptrCol = 0;
        break;
    case 8: *ptrRow = 2; *ptrCol = 1;
        break;
    case 9: *ptrRow = 2; *ptrCol = 2;
    
    }
    if (board[*ptrRow][*ptrCol] == 'X' || board[*ptrRow][*ptrCol] == 'O')
    {
        filled = true;
        return filled;
    }
    else
    {   
        return filled;
    }
}

void DisplayBoard(char gameBoard[ROWS][COLS])
{
    for (int x = 0; x < ROWS; x++)
    {
        for (int y = 0; y < COLS; y ++)
        {   
            cout << setw(2);
            cout  << gameBoard[x][y];
        }
        cout << endl;
    }
}

bool checkWinner(char board[ROWS][COLS])
{   
    int P1rowCount = 0;
    int P2rowCount = 0;
    int P2ColCount = 0;
    int P1ColCount = 0;
    
    
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (board[row][col] == 'X')
            {
                P1rowCount++;
            }
            else if(board[row][col] == 'O')
            {
                P2rowCount++;
            }

        }
        if(P1rowCount == 3)
        {
            cout << "Player one wins." << endl;
            return true;
        }
        else if(P2rowCount == 3)
        {
            cout << "Player two wins." << endl;
            return true;
        }
        P1rowCount = 0;
        P2rowCount = 0;
    }

    for (int col = 0; col < ROWS; col++)
    {
        for (int row = 0; row < COLS; row++)
        {
            if (board[row][col] == 'X')
            {
                P1ColCount++;
            }
            else if(board[row][col] == 'O')
            {
                P2ColCount++;
            }

        }
        if(P1ColCount == 3)
        {
            cout << "Player one wins." << endl;
            return true;
        }
        else if(P2ColCount == 3)
        {
            cout << "Player two wins." << endl;
            return true;
        }
        P1ColCount = 0;
        P2ColCount = 0;
    }

    if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'))
    {
        cout << "Player one wins." << endl;
        return true;
    }
    else if ((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
    {
        cout << "Player two wins." << endl;
        return true;
    }
    return false;
    
}

bool Tie(char board[ROWS][COLS])
{   
    int count = 0;
    for (int x = 0; x < ROWS; x++)
    {
        for (int y = 0; y < ROWS; y++)
        {
            if (isdigit(board[x][y]))
            {
                count++;
            }
        }
    }
    if (count == 0)
    {
        cout << "The game is a tie." << endl;
        return true;
    }
    return false;
}
    
