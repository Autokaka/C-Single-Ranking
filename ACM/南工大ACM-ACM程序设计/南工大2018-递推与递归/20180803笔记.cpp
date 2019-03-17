#include <iostream>
using namespace std;

long long f[110] = {0, 1, 2}; 

int main()
{
	cout << f[1] << " " << f[2] << " ";
	for (int i = 3; i < 100; i++)
	{
		f[i] = (3 * f[i - 1] + 5 * f[i - 2]) % 7;
		cout << f[i] % 7 << " ";
	}
	cout << endl << endl << endl << endl;
	
	
	
	int i, j;
	for (i = 1; i < 49; i++)//抽屉原理，余数在0~6， 有7 * 7 = 49种，测试50个案例必定能找到规律 
	{
		int flag = 0;
		for (j = 1; j < i; j++)
		{
			if (f[i] == f[j] && f[i + 1] == f[j + 1])
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
	}
	
	
	
	int n;
	cin >> n;
	cout << f[(n - j) % (i - j) + j] << endl;
	return 0;
}
