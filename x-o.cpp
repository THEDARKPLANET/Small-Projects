#include<iostream>
using namespace std;

// main variable
char pos;
char Player='X';
char Matrix[3][3]={'1','2','3',
                   '4','5','6',
                   '7','8','9'};

// to drow the game to user
void Drow()
{
  system("clear");
  //horizon top frame
  cout << " ------------\n";

  for(int arr=0;arr<3;arr++)
  {
    cout << "| ";// space before the number in etch array to set all in frame
    for(int com=0;com<3;com++)
    {
      if(com == 2)
      {
        cout << Matrix[arr][2];
        cout << "  |";// space after the last number in array
      }else{
        cout << Matrix[arr][com] << "   ";// space between etch number
      }
    }
    cout << endl;
  }
  //horizon bottom frame
  cout << " ------------\n";
}

void input()
{
  cout << "Enter your position Player (" << Player << ") ";
  cin >> pos;
  for(int arr=0;arr<3;arr++)
  {
    for(int com=0;com<3;com++)
    {
      if(Matrix[arr][com] == pos)
      {
        Matrix[arr][com] = Player;
      }
    }
  }
  if(Player == 'X')
      {
        Player = 'O';
      }else{
        Player = 'X';
      }
}

char CheckWinner()
{
  int x=0,o=0,counter=0; // to count x and o and equealed
  for(int arr=0;arr<3;arr++) // to check winner horizon
  {
    for(int com=0;com<3;com++)
    {
      if(Matrix[arr][com] == 'X')
      {
        x++;
      }else if(Matrix[arr][com] == 'O')
      {
        o++;
      }
      if(x == 3)
      {
        return 'X';
      }
      if(o == 3)
      {
        return 'O';
      }
    }
    x=0 , o=0; // solve the bug (game end with two position of X or O)
  }

  for(int arr=0;arr<3;arr++) // to check winner vertical
  {
    for(int com=0;com<3;com++)
    {
      if(Matrix[com][arr] == 'X')
      {
        x++;
      }else if(Matrix[com][arr] == 'O')
      {
        o++;
      }
      if(x == 3)
      {
        return 'X';
      }
      if(o == 3)
      {
        return 'O';
      }
    }
    x=0 , o=0; // solve bug 2
  }
  //check winner in radios
  //----------------------------------------------------------------------
  if(Matrix[0][0] == 'X' && Matrix[1][1] == 'X' && Matrix[2][2] == 'X') 
    return 'X';
  if(Matrix[0][0] == 'O' && Matrix[1][1] == 'O' && Matrix[2][2] == 'O')
    return 'O';
  //----------------------------------------------------------------------
  if(Matrix[0][2] == 'X' && Matrix[1][1] == 'X' && Matrix[2][0] == 'X')
    return 'X';
  if(Matrix[0][2] == 'O' && Matrix[1][1] == 'O' && Matrix[2][0] == 'O')
    return 'O';
  //----------------------------------------------------------------------
  
  // check an empety spaces
  for(int arr=0;arr<3;arr++)
  {
    for(int com=0;com<3;com++)
    {
      if(Matrix[arr][com] != 'X' && Matrix[arr][com] != 'O')
        counter++;
    }
  }

  // for equealed
  if(counter == 0)
    return '=';

  return '^';
}

int main()
{
  // if the function return ^ this means that the game is unfinished so the while loop repete the game
  while(CheckWinner() == '^')
  {
    Drow();
    input();
    CheckWinner();
  }

  // to report who is the winner
  Drow();
  if(CheckWinner() == 'X')
    printf("\n The Player X is Winner \n");
  if(CheckWinner() == 'O')
    printf("\n The Player O is Winner \n");
  if(CheckWinner() == '=')
    printf("\n No Winner \n");
  
 return 0; 
}
