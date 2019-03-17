#include <iostream>
using namespace std;

int main()
{
	int n, m;//ÁÐ£¬ÐÐ 
	while (cin >> n >> m)
	{
		n += 2, m += 2;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				if (i == 1 || i == m)
				{
					if (j == 1 || j == n)
						cout << "+";
					else
						cout << "-";
				}
				else
				{
					if (j == 1 || j == n)
						cout << "|";
					else
						cout << " ";
				}
				if (j == n)
					cout << endl;
			}
		cout << endl;
	}
	return 0;
}
