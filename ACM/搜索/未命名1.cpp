#include <bits/stdc++.h>
using namespace std;
#define rp1(x, y, z) for((x) = (y); (x) <= (z); (x)++)
#define rp2(x, y, z) for((x) = (y); (x) < (z); (x)++)
#define rp3(x, y, z) for((x) = (y); (x) >= (z); (x)--)
#define rp4(x, y, z) for((x) = (y); (x) > (z); (x)--)
#define INF 0x7fffffff
#define N 102
string s[N];

bool cmp(string s1, string s2)
{
	return s1.size() < s2.size();
}

int main()
{
	int t, n, i, j, len, flag = 0, flag1 = 0;
	string ss;
	cin >> t;
	while (t--)
	{
		cin >> n;
		rp2(i, 0, n) cin >> s[i];
		sort(s, s + n, cmp);
		flag1 = 0;
		rp4(len, s[0].size(), 0)
		{
			if (flag) break;
			rp2(i, 0, s[0].size())
			{
				if (i + len > s[0].size()) break;
				ss = s[0].substr(i, len);
				flag = 0;
				rp2(j, 0, n)
				{
					if (s[i].find(ss, 0) == string::npos)
					{
						reverse(ss.begin(), ss.end());
						if (s[i].find(ss, 0) == string::npos)
						{
							flag = 1;
							break;
						}
					}
				}
				if (!flag)
				{
					cout << len << endl;
					flag1 = 1;
					break;
				}
			}
		}	
		if (!flag1)
			cout << 0 << endl;
	}
	
	return 0;
}

