#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int size;
	cin >> size;
	string str;
	for (int i = 1; i <= size; i++)
	{
		cin >> str;
		int cnt = 0 ;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] >= '0' && str [i] <= '9')
				cnt++;
		}
		cout << cnt << endl;
	}
	
	return 0;
}
