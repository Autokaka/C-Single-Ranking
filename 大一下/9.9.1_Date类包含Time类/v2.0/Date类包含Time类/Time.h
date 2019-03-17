#ifndef TIME_H
#define TIME_H

class Time
{
	public:
		Time(int=0, int=0,int=0);
		int tick();
		void print(const int) const;
	private:
		int hour;
		int minute;
		int second;
};

#endif