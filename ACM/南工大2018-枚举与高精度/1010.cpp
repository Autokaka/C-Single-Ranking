#include <iostream>
#include <cstring>
using namespace std;

char sign[200];
double num[200];
char tmp[500];

int main()
{
	while(gets(tmp), strcmp(tmp, "0"))
	{
		int signpos = 0, numpos = 0;
		for (int i = 0; i < strlen(tmp); i++)
		{
			if (tmp[i] == ' ')
				continue;
			if (tmp[i] == '+' || tmp[i] == '-' || tmp[i] == '*' || tmp[i] == '/')
			{
				sign[signpos++] = tmp[i];
				continue;
			}	
			if (tmp[i - 2] != ' ' && tmp[i - 2] == '+' || tmp[i - 2] == '-' || tmp[i - 2] == '*' || tmp[i - 2] == '/')
			{
				num[++numpos] = tmp[i] - '0';
				continue;
			}
			else
				num[numpos] = 10 * num[numpos] + (tmp[i] - '0');
		}
		for (int i = 0; i < strlen(sign); i++)
		{
			if (sign[i] == '*')
			{
				num[i + 1] *= num[i];
				num[i] = 0;
				if (sign[i - 1] == '-')
					sign[i] = '-';
				else
					sign[i] = '+';	
			}	
			if (sign[i] == '/')
			{
				num[i + 1] = num[i] / num[i + 1];
				num[i] = 0;
				if (sign[i - 1] == '-')
					sign[i] = '-';
				else
					sign[i] = '+';
			}	
		}
		for (int i = 0; i < strlen(sign); i++)
		{
			if (sign[i] == '+')
				num[i + 1] += num[i];
			else
				num[i + 1] = num[i] - num[i + 1];
			num[i] = 0;
		}
		printf("%.2lf\n", num[strlen(sign)]);
		memset(tmp, 0, sizeof(char));
		memset(sign, 0, sizeof(char));
		memset(num, 0, sizeof(double));
	}
	return 0;
}
