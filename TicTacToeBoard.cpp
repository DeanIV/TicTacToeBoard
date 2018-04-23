#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
 **/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
 **/
Piece TicTacToeBoard::toggleTurn()
{
  //swap turn
  if(turn==X)
    turn=O;
  else if (turn==O)
    turn=X;

  return turn;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
 **/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  if(row > 3 || column > 3)
    return Invalid;
  if(board[row][column]!=Blank)
    return Invalid;
  else if(board[row][column]==Blank){
    board[row][column]=turn;
    toggleTurn();
    return board[row][column];
  }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
 **/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if(board[row][column]==Blank)
    return Blank;
  else if(board[row][column]!=Blank)
    return board[row][column];
  else
    return Invalid;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
 **/
Piece TicTacToeBoard::getWinner()
{
  int count=0;
  //check rows
  for(int i=0; i<BOARDSIZE; i++){
    if(board[i][1]==X && board[i][2]==X && board[i][3]==X)
      return X;
    if(board[i][1]==O && board[i][2]==O && board[i][3]==O)
      return O;
  }
  //check columns
  for(int i=0; i<BOARDSIZE; i++){
    if(board[1][i]==X && board[2][i]==X && board[3][i]==X)
      return X;
    if(board[1][i]==O && board[2][i]==O && board[3][i]==O)
      return O;
  }
    //TLBR diagonal
    if(board[1][1]==X && board[2][2]==X && board[3][3]==X)
      return X;
    if(board[1][1]==O && board[2][2]==O && board[3][3]==O)
      return O;
    //TRBL diagonal
    if(board[3][1]==X && board[2][2]==X && board[1][3]==X)
      return X;
    if(board[3][1]==O && board[2][2]==O && board[1][3]==O)
      return O;

    //check for full or not over
    for(int i=0; i<BOARDSIZE; i++)
      for(int j=0; j<BOARDSIZE; j++)
        if(board[i][j]!=Blank)
          count++;
    if(count==9)
      return Blank;
    else if(count!=9)
      return Invalid; 
}
