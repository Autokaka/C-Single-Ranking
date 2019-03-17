#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
	public:
		TicTacToe();
		void pvpMode();
		void pveMode();
    private:
		void play(int);
		void displayBoard();
		int judge();
		void check( int, int );
		int chessboard[3][3];
		int x, y, cnt;

};

#endif