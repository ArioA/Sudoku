#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"

using namespace std;

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char *filename, char board[9][9]) {

  cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename);
  if (!in)
    cout << "Failed!" << endl;
  assert(in);

  char buffer[512];

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }

  cout << ((row == 9) ? "Success!" : "Failed!") << endl;
  assert(row == 9);
}

/* internal helper function */
void print_frame(int row) {
  if (!(row % 3))
    cout << "  +===========+===========+===========+" << endl;
  else
    cout << "  +---+---+---+---+---+---+---+---+---+" << endl;
}

/* internal helper function */
void print_row(const char *data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|" << endl;
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++) 
    cout << (char) ('1'+r) << "   ";
  cout << endl;
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}

/* add your functions here */


//Precondition: board is a 9x9 sudoku board (complete or otherwise) filled
//with characters, where '.' represents empty squares.
//Postcondition: returns true if board is filled, false otherwise.
//board needn't be logically valid.

bool is_complete(const char board[9][9])
{
  for(int row = 0; row < 9; row++)
    {
      for(int column = 0; column < 9; column++)
	{
	  if((board[row][column] < '1' || board[row][column] > '9'))
	    return false;
	}
    }

  return true;
}


//Precondition: board is a 9x9 array of characters consisting of only
// '.' or digits.
//Returns false if digit cannot be placed in position on board 
//(logically or due to range).
//Returns true if placing digit in position on board is valid, and updates
//board with digit placed in position.
bool make_move(const char* position, char digit, char board[9][9])
{
  if(position[0] < 'A' || position[0] > 'I' || position[1] < '1' || position[1] > '9')
    return false; // Checks for invalid position.

  int pos_char = static_cast<int>(position[0] - 65);
  int pos_int = static_cast<int>(position[1] - 49);

  if(board[pos_char][pos_int] <= '9' && board[pos_char][pos_int] >= '1')
    return false; //Checks if cell in question is occupied.

  for(int k = 0; k < 9; k++) //Checks both row and column                             
    {                        //for same number as digit.
      if(board[k][pos_int] == digit ||
	 board[pos_char][k] == digit)
	return false;
    }

  for(int j = 0; j < 3; j++)    //Checks that same number doesn't
    for(int l = 0; l < 3; l++)  //occur in same 3x3 square.
      {
	if(board[pos_char - (pos_char%3) + j][pos_int - (pos_int%3) + l] == digit)
	  return false;
      }

  board[pos_char][pos_int] = digit; //Only reached if a valid move.

  return true;
}

//Saves the 9x9 character array board to a file named filename.
//The file filename is then in 9x9 grid form.

bool save_board(const char* filename, const char board[9][9])
{
  ofstream out(filename);

  if(!out)
    return false;

  int row;

  for(row = 0; row < 9 && out; row++)
    {
      for(int column = 0; column < 9; column++)
	out.put(board[row][column]); //Outputs board row by row.

      out.put('\n');
    }

  out.close();
 
  return ((row == 9) ? true : false);

}

/*
Precondition: board is a (incomplete or otherwise) sudoku board, 
where the '.' character represents empty squares. 
Returns 1 if board is solvable and a solution to board is found. In this
case, board is upadated to its solution.
Returns 0 if board is impossible to solve and solution has not been found.
In this case, board is left in its original state.
*/ 

bool solve_board(char board[9][9])
{
  if(is_complete(board))
    {
      return 1;
    }

  char digit, position[2];
  int pos_char, pos_int;

  for(position[0] = 'A'; position[0] <= 'I'; position[0]++)
    {
      pos_char = static_cast<int>(position[0]) - 65;

      for(position[1] = '1'; position[1] <= '9'; position[1]++)
	{
          pos_int = static_cast<int>(position[1]) - 49;

	  for(digit = '1'; digit <= '9'; digit++)
	    {
	      if(make_move(position, digit, board))
		{
		  solve_board(board);

		  if(is_complete(board))
		    return 1; // Exits recursive loop if solution found.
		  else
		  board[pos_char][pos_int] = '.';
		}
	    }
	
	  if(board[pos_char][pos_int] == '.')
	    return 0; // Tells function to give up and go
	}             // back if all moves are impossible.
    }

  return 0; // Only reached if board is impossible to solve.
}
