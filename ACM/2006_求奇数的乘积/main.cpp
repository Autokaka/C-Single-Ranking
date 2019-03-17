#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int size,n,sum;
    while(scanf("%d", &size) != EOF)
    {
        sum = 1;
        for(int i = 0; i < size; i++)
        {
        	scanf("%d", &n);
        	(n % 2 == 1)? sum *= n : sum;
        }
        cout << sum << endl;
    }
    return 0;
}
