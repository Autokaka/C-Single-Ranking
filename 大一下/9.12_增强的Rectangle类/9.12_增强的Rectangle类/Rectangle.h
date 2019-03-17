#include"stdafx.h"


#include <iostream>
using namespace std;

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
	public:
		Rectangle(double=0, double=0, double=0, double=0, double=0, double=0, double=0, double=0);
		void setPosition(double, double, double, double, double, double, double, double);
		void calSystem(int);

	private:
		void check(double, double, double, double, double, double, double, double);
		int checkRectangle(double, double, double, double, double, double, double, double);
		int checkSquare(double, double, double, double, double, double, double, double);
		double xa, ya;
		double xb, yb;
		double xc, yc;
		double xd, yd;
};

#endif
