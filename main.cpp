#include <iostream>
#include <cstdio>
#include "sudoku.h"

using namespace std;

int main() {

  char board[9][9];

  /* This section illustrates the use of the pre-supplied helper functions. */
  cout << "============== Pre-supplied functions ==================" << endl << endl;

  cout << "Calling load_board():" << endl;
  load_board("easy.dat", board);

  cout << endl << "Displaying Sudoku board with display_board():" << endl;
  display_board(board);
  cout << "Done!" << endl << endl;

  cout << "====================== Question 1 ======================" << endl << endl;

  //Both should load. Could add a display_board(board) to confirm.

  load_board("easy.dat", board);

  cout << "Board is ";

  if (!is_complete(board))
    cout << "NOT ";

  cout << "complete." << endl << endl;



  load_board("easy-solution.dat", board);

  cout << "Board is ";

  if (!is_complete(board))
    cout << "NOT ";

  cout << "complete." << endl << endl;



  cout << "====================== Question 2 ======================" << endl << endl;

  load_board("easy.dat", board);

  // Should be OK
  cout << "Putting '1' into I8 is ";
  if (!make_move("I8", '1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  //  display_board(board);


  //Testing for deliberately invalid moves.

  cout << "Putting '1' into I8 is ";

  if (!make_move("J8", '1', board)) 
    cout << "NOT ";

  cout << "a valid move (should be NOT). The board is:" << endl;
  display_board(board);



  cout << "Putting '1' into A9 is ";

  if (!make_move("A9", '1', board)) 
    cout << "NOT ";

  cout << "a valid move (should be NOT). The board is:" << endl;
  display_board(board);



  cout << "Putting '1' into C5 is ";

  if (!make_move("C5", '1', board)) 
    cout << "NOT ";

  cout << "a valid move (should be NOT). The board is:" << endl;
  display_board(board);



  cout << "Putting '1' into I7 is ";

  if (!make_move("I7", '1', board)) 
    cout << "NOT ";

  cout << "a valid move (should be NOT). The board is:" << endl;
  display_board(board);



  cout << "Putting '1' into F2 is ";

  if (!make_move("F2", '1', board)) 
    cout << "NOT ";

  cout << "a valid move (should be NOT). The board is:" << endl;
  display_board(board);



  cout << "====================== Question 3 ======================" << endl << endl;
  

  load_board("easy.dat", board);

  if (save_board("easy-copy.dat", board))
    cout << "Save board to 'easy-copy.dat' successful." << endl;
  else
    cout << "Save board failed." << endl;

  cout << endl;


// Testing with a breadth of characters.

  char chicken[9][9];

  for(int k = 0; k < 9; k++)
    for(int j = 0; j < 9; j++)
      chicken[k][j] = static_cast<char>(k*j + 50);

  if (save_board("loadarubbish.dat", chicken))
    cout << "Save board to 'loadarubbish.dat' successful." << endl;
  else
    cout << "Save board failed." << endl;

  cout << endl;

  cout << "====================== Question 4 ======================" << endl << endl;
 
//Testing to see if boards are solvable. Should print either complete or 
//original board if board is solvable or not respectively.

//Searches for solution of easy board.

  load_board("easy.dat", board); 

  if (solve_board(board)) {
    cout << "The 'easy' board has a solution:" << endl;
  } else 
    cout << "A solution cannot be found for board:" << endl;

  display_board(board);
  cout << endl;
  
//Searches for solution of medium board.

  load_board("medium.dat", board); 

  if (solve_board(board)) {
    cout << "The 'medium' board has a solution:" << endl;
  } else 
    cout << "A solution cannot be found for board:" << endl;

  display_board(board);
  cout << endl;

//Searches for solution of mystery1 board.

  load_board("mystery1.dat", board);

  if (solve_board(board)) {
    cout << "The 'mystery1' board has a solution:" << endl;
  } else 
    cout << "A solution cannot be found for board:" << endl;

  display_board(board);
  cout << endl;

//Searches for solution of mystery2 board.

  load_board("mystery2.dat", board);

  if (solve_board(board)) {
    cout << "The 'mystery2' board has a solution:" << endl;
  } else 
    cout << "A solution cannot be found for board:" << endl;

  display_board(board);
  cout << endl;

//Searches for solution of mystery3 board.

  load_board("mystery3.dat", board);

  if (solve_board(board)) {
    cout << "The 'mystery3' board has a solution:" << endl;
  } else 
    cout << "A solution cannot be found for board:" << endl;

  display_board(board);
  cout << endl;




  cout << "====================== Question 5 ======================" << endl << endl;

  cout << "See findings.txt file for my conclusion." << endl << endl;

  return 0;
}
