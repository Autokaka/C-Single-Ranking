#include <iostream>
#include <string.h>
using namespace std; 

bool compare(char &a, char &b)
{
	char tmp;
	if (a > b)
	{
		tmp = a, a = b, b = tmp;
		return 1;
	}	
	return 0;
}

int main() 
{
	char n[3];
	while ( cin >> n )
	{
		int cnt;
		do 
		{
			cnt = 0;
			for (int i = 0; i < strlen(n) - 1; i++)
				compare(n[i], n[i + 1])? cnt++ : cnt; 
		} while (cnt != 0);
		for (int i = 0; i < strlen(n); i++)
		{
			cout << n[i];
			if (i < strlen(n) - 1)
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}
