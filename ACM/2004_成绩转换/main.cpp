#include <iostream>
using namespace std;
 
int main() 
{
	int n;
	char grade[11]{'E', 'E', 'E', 'E', 'E', 'E', 'D', 'C', 'B', 'A', 'A'};
	while (cin >> n)
	{
		if (n < 0 || n > 100)
			cout << "Score is error!" << endl;
		else
			cout << grade[n/10] << endl; 
	}
	return 0;
}
