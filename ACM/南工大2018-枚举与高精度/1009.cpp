#include <iostream>
using namespace std;

#define N 1000

struct node
{
	int num;
	int seq;
	int pos;
} guess[N];

int main()
{
	int n, dic[4], gus[4];
	int numa, numb , numc, numd;
	while (cin >> n, n)
	{
		int possi = 0, storage[4], tmp[4];
		for (int i = 0; i < n; i++)
			cin >> guess[i].num >> guess[i].seq >> guess[i].pos;
		for (int i = 3585; i <= 9999; i++)
		{
			int j = i;
			for (int k = 0; k < 4; k++)
			{
				dic[k] = j % 10;
				j /= 10;
			}
			int cnt = 0, tn = n;
			for (int cpy = 0; cpy < 4; cpy++)
				tmp[cpy] = dic[cpy];
			while (tn--)
			{
				for (int cpy = 0; cpy < 4; cpy++)
					dic[cpy] = tmp[cpy];
				int cnt1 = 0, cnt2 = 0, tmpgus = guess[tn].num;
				for (int k = 0; k < 4; k++)
				{
					gus[k] = tmpgus % 10;
					tmpgus /= 10;
				}
				for (int i = 0; i < 4; i++)
				{
					if (gus[i] == dic[i])
						cnt2++;	
				}
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						if (gus[j] == dic[i] && gus[j] != -1)
						{
							cnt1++;
							gus[j] = -1;
							dic[i] = -1;
							break;
						}
					}
				}
				if (cnt1 == guess[tn].seq && cnt2 == guess[tn].pos)
					cnt++;
				else
					goto loop;
				if (cnt == n)
				{
					possi++;
					for (int cpy = 0; cpy < 4; cpy++)
						storage[cpy] = tmp[cpy];
					goto loop;
				}
				else
					continue;
			}
			loop:
				continue;	
		}
		if (possi == 1)
			cout << storage[3] << storage[2] << storage[1] << storage[0] << endl;
		else
			cout << "Not sure\n";
	}
	return 0;
}

