#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define N 7
#define M 1000003
int a[] = {12, 34, 13, 8, 19, 22}, x[N];
const int n = 6, k = 3;//第i个元素的使用情况->0未用过1用过  
int vis[N];
long long prime[M], check[M];

//埃氏筛选素数  
void gprime()
{
	int i, j;
	for (i = 2; i < M; i++)
	{
		if (!prime[i])
			for (j = 2; i * j < M; j++)
				prime[i * j] = 1;	
	}
}

//欧拉筛法  
void gprime2()
{
	int i, j, tot = 0;
	for (i = 2; i < M; i++)
	{
		if (!check[i])
			prime[tot++] = i;
		for (j = 0; j < tot; j++)
		{
			if (prime[j] * i >= M)
				break;
			check[prime[j] * i] = 1;
			if (i % prime[i] == 0)
				break;
		}	
	}
}

long long qpow(long long a, long long n, long long p)
{
	if (n == 1)
		return a;
	long long tmp = qpow(a, n >> 1, p);
	if (n & 1)
		return a * tmp % p * tmp % p;
	else
		return tmp * tmp % p;
}

//随机测试法  
bool isPrime(int x)
{
	int i;
	long long a;
	srand(time(0));
	for (i = 0; i < 4; i++)
	{
		a = 2 + rand() % (x - 2);
		if(qpow(a, x - 1, x) % x != 1)
			return 0;
	}
	return 1;
}

void dfs(int st, int dep)
{
	int i, sum = 0, cnt = 0;
	if (dep >= k)
	{
		/*for (i = 0; i < k; i++)
			cout << x[i] << " ";
		cout << endl;*/
		for (i = 0; i< k; i++)
			sum += x[i];
		if (isPrime(sum))
			cnt++;
		return;
	}
	for (i = st; i < n; i++)
	{
		x[dep] = a[i];
		dfs(i + 1, dep + 1);
		vis[i] = 0;
	}
}

int main()
{
	int i; 
	for (i = 0; i < n - k + 1; i++)
	{
		x[0] = a[i];
		dfs(i + 1, 1);
	}
	return 0;
}

