#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	__int64 a,b,c;
	while(cin >> hex >> a >> b)
	{
		c = a + b;
		if(c < 0)
		{
		 cout << '-';	
		 c = -c;
		}
		cout << hex << uppercase << c <<endl;
	}
	return 0;
}
