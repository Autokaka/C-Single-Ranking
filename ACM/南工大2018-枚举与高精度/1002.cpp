#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define FOR(x) for (int (x) = 0; (x) < strlen(s); (x)++)

int main()
{
	int n;
	char s[20], ans[5];
	while (~scanf("%d", &n))
	{
		scanf("%s", s);
		if (n == 0 && strcmp(s, "END") == 0)
			break;
		sort(s, s + strlen(s));
		int flag = 0;
		FOR(s1)
			FOR(s2)
				FOR(s3)
					FOR(s4)
						FOR(s5)
						{
							int sum = (s[s1] - 'A' + 1) - (s[s2] - 'A' + 1) * (s[s2] - 'A' + 1) + (s[s3] - 'A' + 1) * (s[s3] - 'A' + 1) * (s[s3] - 'A' + 1) - (s[s4] - 'A' + 1) * (s[s4] - 'A' + 1) * (s[s4] - 'A' + 1) * (s[s4] - 'A' + 1) + (s[s5] - 'A' + 1) * (s[s5] - 'A' + 1) * (s[s5] - 'A' + 1) * (s[s5] - 'A' + 1) * (s[s5] - 'A' + 1);
							if (n == sum && s1 != s2 && s2 != s3 && s3 != s4 && s4 != s5)
							{
								ans[0] = s[s1];
								ans[1] = s[s2];
								ans[2] = s[s3];
								ans[3] = s[s4];
								ans[4] = s[s5];
								flag = 1;
							}
						}
	if (flag)
		printf("%s\n", ans);
	else
		printf("no solution\n");
	}
	return 0;
}
