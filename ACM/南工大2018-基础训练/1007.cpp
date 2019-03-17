#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	map<string, int> num;
	num["zero"] = 0;
	num["one"] = 1;
	num["two"] = 2;
	num["three"] = 3;
	num["four"] = 4;
	num["five"] = 5;
	num["six"] = 6;
	num["seven"] = 7;
	num["eight"] = 8;
	num["nine"] = 9;
	char tmp[1024];
	int flag = 0;
	vector<int> v1;
	vector<int> v2;
	while(~scanf("%s", tmp))
	{
		if (tmp[0] == '+')
			flag = 1;
		if (tmp[0] != '+' && tmp[0] != '=')
		{
			if (flag)
				v2.push_back(num[tmp]);
			else
				v1.push_back(num[tmp]);
		}
		if (tmp[0] == '=')
		{
			vector<int>::iterator it;
			int cnt = 1, n1 = 0, n2 = 0;
			for (it = v1.end() - 1; it >= v1.begin(); it--)
			{
				n1 += *it * cnt;
				cnt *= 10;
			}
			cnt = 1;
			for (it = v2.end() - 1; it >= v2.begin(); it--)
			{
				n2 += *it * cnt;
				cnt *= 10;
			}
			if (n1 == 0 && n2 == 0)
				return 0;
			cout << n1 + n2 << endl;
			flag = 0;
			v1.clear();
			v2.clear();
		}
	}
	return 0;
}

