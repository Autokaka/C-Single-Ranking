#include <iostream>
using namespace std;

int main()
{
    int n;
    int f[31] = {0};
    f[0] = 1, f[2] = 3;
    for (int i = 4; i <= 30; i += 2)
        f[i] = 4 * f[i - 2] - f[i - 4];
    while (~scanf("%d", &n), n != -1)
        printf("%d\n", f[n]);
    return 0;
}
