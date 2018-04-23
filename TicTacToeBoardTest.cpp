/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
*/
//begin
TEST(TicTacToeBoardTest, SetUp)
{
  TicTacToeBoard test;
  ASSERT_TRUE(true);
}
//test turn swap
TEST(TicTacToeBoardTest, toggleTurnTest)
{
  TicTacToeBoard test;
  ASSERT_TRUE(test.toggleTurn() == 'O');
}
//test vertical win for X
TEST(TicTacToeBoardTest, winTest)
{
  TicTacToeBoard test;
  ASSERT_TRUE(test.placePiece(1,0) == 'X');
  ASSERT_TRUE(test.toggleTurn() == 'O');
  ASSERT_TRUE(test.placePiece(2,0) == 'X');
  ASSERT_TRUE(test.toggleTurn() == 'O');
  ASSERT_TRUE(test.placePiece(3,0) == 'X');
  ASSERT_TRUE(test.getWinner() == 'X');
}
//test empty board
TEST(TicTacToeBoardTest, toggleTurnTest)
{
  TicTacToeBoard test;
  ASSERT_TRUE(test.getWinner() == 'Invalid');
}
