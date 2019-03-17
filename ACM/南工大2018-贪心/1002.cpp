#include <stdio.h>
using namespace std;

#define X 250

int room[X];

int main()
{
	int T, N, left, right, i;
	scanf("%d", &T);
	while (T--)
	{
		for (int i = 0; i < X; i++)
			room[i] = 0;
		scanf("%d", &N);
		while (N--)
		{
			scanf("%d%d", &left, &right);
			if (left > right)
			{
				int tmp = right;
				right = left;
				left = tmp;
			}
			if (left % 2 == 0)
				left /= 2;
			else
				left = left / 2 + 1;
			if (right % 2 == 0)
				right /= 2;
			else
				right = right / 2 + 1;
			for (i = left; i <= right; i++)
				room[i]++;
		}
		int big = 0;
		for (i = 0; i < X; i++)
			if (room[i] > big)
				big = room[i];
		printf("%d\n", big * 10);
	}
	return 0;
}

