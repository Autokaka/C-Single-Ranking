#include <iostream>
#include <iomanip>
using namespace std;
#define PI 3.1415927

int main() 
{
	double r;
	while (cin >> r)
		cout << fixed << setprecision(3) << (PI * r * r * r * 4 / 3) << endl;
	return 0;
}
