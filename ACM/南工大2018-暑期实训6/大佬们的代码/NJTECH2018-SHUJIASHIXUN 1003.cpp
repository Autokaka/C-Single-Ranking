#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;


#define mod 1000000007


const int maxn = 100010;

typedef long long ll;
ll n;
#define A 4
struct Matrix{
	ll a[A][A];
};

Matrix mul(Matrix x, Matrix y){
	Matrix temp;ll sum;int i,j,k;
	for (i = 1; i < A; i++)
		for (j = 1; j < A; j++)
			temp.a[i][j] = 0;

	for (i = 1; i < A; i++){
		for (j = 1; j < A; j++){
			sum = 0;
			for (k = 1; k < A; k++){
				sum = (sum + x.a[i][k] * y.a[k][j] % mod) % mod;
			}
			temp.a[i][j] = sum;
		}
	}
	return temp;
}

/*
Matrix quickpow(Matrix M,ll k){
	Matrix res;
	res.a[1][1] = 1; res.a[1][2] = 0; res.a[1][3] = 0;
	res.a[2][1] = 0; res.a[2][2] = 1; res.a[2][3] = 0;
	res.a[3][1] = 0; res.a[3][2] = 0; res.a[3][3] = 1;

	while (k){
		if (k & 1) 
			res = mul(res, M);
			M = mul(M, M);
		k >>= 1;
	}
	return res;
}*/
Matrix quickpow(Matrix M,ll n){
	if(n==1) return M;
	Matrix tmp=quickpow(M,n>>1);
	
	if(n&1) return mul(mul(tmp,tmp),M);
	else return mul(tmp,tmp);
}


int main(){
	Matrix M;
		M.a[1][1] = 1; M.a[1][2] = 0; M.a[1][3] = 1;
		M.a[2][1] = 1; M.a[2][2] = 0; M.a[2][3] = 0;
		M.a[3][1] = 0; M.a[3][2] = 1; M.a[3][3] = 0;
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%lld", &n);
		if (n == 2){
			printf("3\n");
			continue;
		}
		if (n == 3){
			printf("4\n");
			continue;
		}

		
		Matrix res = quickpow(M,n-4);
		ll x = (6*res.a[1][1]%mod + 4*res.a[1][2]%mod+3*res.a[1][3]%mod) % mod;
		

		printf("%lld\n", x%mod);
	}
	return 0;
}
