#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() 
{
	double n[2][2] = { 0 };
	while(1)
	{
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				if (!(cin >> n[i][j]))
					return 0;
		cout << fixed << setprecision(2) << sqrt(pow(n[0][0] - n[1][0], 2) + pow(n[0][1] - n[1][1], 2)) << endl;
	}	
	return 0;
}
