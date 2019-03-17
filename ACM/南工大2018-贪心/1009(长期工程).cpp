#include <bits/stdc++.h>
using namespace std;
//threat[4][4]设定：-2->不能下棋了; -1->围墙的位置; 0->该处未下棋; 0+->下棋的位置 

#define X 4
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)

int box[X][X];

void testPrint(int box[X][X], int size)
{
	rep(i, 0, size)
	{
		rep(j, 0, size)
			printf("%-4d", box[i][j]);
		printf("\n");
	}	
}

bool Analyse(int box[X][X], int size)
{
	//终止判断  
	int fin = 0;
	rep(i, 0, size)
		rep(j, 0, size)
			if (box[i][j] != 0)
				fin++;
	if (fin == size * size)
		return 0;
	//情况分析  
	
}

int main()
{
	int size;
	while (~scanf("%d", &size), size)
	{
		memset(box, 0, sizeof(box));
		char tmp;
		rep(i, 0, size)
		{
			getchar();
			rep(j, 0, size)
			{
				scanf("%c", &tmp);
				if (tmp == '.')
					box[i][j] = 0;
				else
					box[i][j] = -1;
			}
		}
		//危胁打分，只需要一次 
		rep(i, 0, size)
		{
			rep(j, 0, size)
			{
				if (box[i][j] == -1)
					continue;
				//横向  
				int lmk = -1, rmk = -1;
				for (int k = j - 1; k >= 0; k--)
					if (box[i][k] == -1)
					{
						lmk = k;
						break;
					}	
				if (lmk != -1)
					box[i][j] = 3 - (lmk + 1);
				rep(k, j + 1, size)
					if (box[i][k] == -1)
					{
						rmk = k;
						break;
					}
				if (rmk != -1)
					box[i][j] += (size - rmk);
				//纵向 
				int umk = -1, dmk = -1;
				for (int k = i - 1; k >= 0; k--)
					if (box[k][j] == -1)
					{
						umk = k;
						break;
					}	
				if (umk != -1)
					box[i][j] = 3 - (umk + 1);
				rep(k, i + 1, size)
					if (box[k][j] == -1)
					{
						dmk = k;
						break;
					}
				if (dmk != -1)
					box[i][j] += (size - dmk);
			}
		}
		testPrint(box, size);
		/*while(Analyse(box, size))
		{
			
		}*/
	}
	return 0;
}

