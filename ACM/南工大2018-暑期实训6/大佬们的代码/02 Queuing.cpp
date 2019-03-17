#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define size 4
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define LL long long

int i,j,k;
int l, MOD;
const int N=0;

struct mat{
	LL a[size][size];
	mat(){
		memset(a,0,sizeof(a));
	} //初始化矩阵元素为 0 
	void setmat(LL x)
	{
		FOR(i,0,size)
		  a[i][i]=x;
	} //初始化矩阵对角元素 
}; 

mat operator * (mat A, mat b)
{
	 mat c;
	 FOR(i,0,size)
	   FOR(j,0,size)
	   {	
	   	c.a[i][j] = 0;
	     FOR(k,0,size){
	     	c.a[i][j]+=(A.a[i][k]*b.a[k][j]) % MOD;
	     	c.a[i][j]%=MOD;
			 }
     }
     return c;
} 
mat powM(mat a, LL k){
	mat c;
	c.setmat(1);
	while(k){
		if(k&1) c=a*c;
		a=a*a;
		k>>1;  // k>>1;   Time Limit Exceeded !
	}
	return c;
}  
////<<<<快速幂矩阵模板 

int main()
{
	 ios::sync_with_stdio(false);
	 mat A, B, C;
	 A.a[0][0] = 9;    //f(4)
	 A.a[1][0] = 6;    //f(3)
	 A.a[2][0] = 4;    //f(2)
	 A.a[3][0] = 2;    //f(1) 
	 
	 B.a[0][0] = B.a[0][2] = B.a[0][3] 
	           = B.a[1][0] = B.a[2][1] 
						 = B.a[0][0] = B.a[3][2] = 1;
	 while(~scanf("%d%d",&l,&MOD))
	 {
	 	 if(l == 0) printf("0\n"); 
	 	 else
			 if(l <= 4) printf("%lld\n",A.a[4-l][0] % MOD);
	 	 else{
	 	 	  C = powM(B,l-4);
	 	 	  C = C * A;
	 	 	  printf("%lld\n",C.a[0][0] % MOD);
			}
	 }
	 return 0;
}

