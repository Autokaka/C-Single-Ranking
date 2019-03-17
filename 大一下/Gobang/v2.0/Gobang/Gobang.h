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
	void Pointest(int, int, int, int, int, int);//≤‚ ‘”√Ω”ø⁄
	
	int size;
	int **Goboard;
};

#endif