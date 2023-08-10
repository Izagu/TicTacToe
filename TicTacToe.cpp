#include <iostream>
#include <string>
#include <cstdint>

// VARIABLES

// TicTacToe Board                             VISUAL AID
char board[3][3] = {{'1', '2', '3'},  //  1 | 2 | 3
                    {'4', '5', '6'},  //  __|___|___
                    {'7', '8', '9'}}; //  4 | 5 | 6
                                      // ___|___|___
                                      //  7 | 8 | 9
                                      //    |   |

// 0 = OPEN. 1 = TAKEN (Will update during play)
char valid[3][3] = {{'0', '0', '0'},
                    {'0', '0', '0'},
                    {'0', '0', '0'}};

// CURRENT PLAYER'S CHOICE
char choice;

// ROW AND COLUMN FOR BOARD
int row, column;

// PLAYERS (might not need)
char Player[2] = {'X', 'O'};

// TRUE = P1. FALSE = P2
bool Turn = true;

// KEEPS TRACKS OF A DRAW
bool Draw = false;

// WRITES THE BOARD
void CreateBoard() // system("cls")  clears console screen ( probably best to use at the end of the game )
{
    std::cout << "________________" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j != 2)
            {
                std::cout << board[i][j] << " | ";
            }
            else
            {
                std::cout << board[i][j] << '\n';
            }
        }
        if (i != 2)
        {
            std::cout << "__|___|___ \n";
        }
    }
}
// CHECK IF CHOICE IS VALID
bool CheckChoice(int choice)
{
    switch (choice)
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
    case 0:
        exit(0);
    default:
        std::cout << "Not a valid move.";
    }
    if (valid[row][column] == '0')
    {
        valid[row][column] = '1';
        return true;
    }
    else
        return false;
}
// UPDATE THE BOARD WITH PLAYER CHOICE
void UpdateBoard(char c)
{
    board[row][column] = c;
}

bool Winner()
{
    // HORIZONTAL WIN
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
        return true;
    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2])
        return true;
    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2])
        return true;

    // VERTICAL WIN
    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0])
        return true;
    else if (board[0][1] == board[1][1] && board[1][1] == board[2][1])
        return true;
    else if (board[0][2] == board[1][2] && board[1][2] == board[2][2])
        return true;

    // DIAGONAL WIN
    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    // DRAW
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (valid[i][j] == '0')
                return false;
        }
    }
    Draw = true;
    return false;
}

void PendingTurn()
{
    while (Winner() == false && Draw == false)
    {
        int response;
        if (Turn == true)
        {
            std::cout << "Select a number: ";
            std::cin >> response;
            if (CheckChoice(response))
            {
                UpdateBoard('X');
                Turn = false;
                std::cout << "\nPLAYER 2 TURN" << std::endl;
                CreateBoard();
            }
            else
            {
                std::cout << "This postion is taken. Try again.";
            }
        }
        else if (Turn == false)
        {
            std::cout << "Select a number: ";
            std::cin >> response;
            if (CheckChoice(response))
            {
                UpdateBoard('O');
                Turn = true;
                std::cout << "\nPLAYER 1 TURN" << std::endl;
                CreateBoard();
            }
            else
            {
                std::cout << "This postion is taken. Try again.";
            }
        }
    }
}

int main()
{

    std::cout << "________________________"
              << std::endl;
    std::cout << "     TIC TAC TOE\n"
              << std::endl;
    std::cout << "~PLAYER 1 IS 'X'. PLAYER 2 IS 'O'"
              << std::endl;
    std::cout << "~To Quit Press 0.\n"
              << std::endl;
    std::cout << "________________________"
              << std::endl;
    std::cout << "\nPLAYER 1 GOES FIRST"
              << std::endl;
    CreateBoard();
    PendingTurn();
    if (Draw == true)
    {
        std::cout << "THE GAME IS A DRAW.";
    }
    else if (Turn == false)
    {
        std::cout << "PLAYER 1 WINS";
    }
    else
        std::cout << "PLAYER 2 WINS";
    //  system("cls");
}

//  CHECK IF CURRENT PLAYER HAS WON
//  RETURN WINNER
//  ELSE CONTINUE PLAYING