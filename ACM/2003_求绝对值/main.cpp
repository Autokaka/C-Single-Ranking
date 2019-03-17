#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
 
int main() 
{
	double n;
	while (cin >> n)
	cout << fixed << setprecision(2) << sqrt(pow(n,2)) << endl;
	return 0;
}
