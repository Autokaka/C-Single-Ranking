#ifndef GOBANG_H
#define GOBANG_H

class Gobang
{
public:
	Gobang(int=15);
	~Gobang();
	void play();
	void print();
private:
	int judge();
	int ComboCheck(int, int, int, int);
	void Draw(int, int, int);

	void YouGo(int);

	void AIGo(int);
	void printScore();//≤‚ ‘”√Ω”ø⁄
	void AIdefend(int, int = 2);
	void AIinvade(int, int = 3);
	
	int size;
	int **Goboard;
	int **Scoreboard;
};

#endif