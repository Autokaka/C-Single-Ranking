//ͨ���ҹ��ɣ���������Ϊ쳲��������е� 2*(k+1)+1���ֵ-1
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define mod 998244353
using namespace std;
//���������ṹ�� 
struct  matrix{
	long long a11,a12,a21,a22;
};

//����2*2������� 
matrix mulM(matrix m1,matrix m2){ 
	matrix ret;
	ret.a11=(m1.a11*m2.a11+m1.a12*m2.a21)%mod;
	ret.a12=(m1.a11*m2.a12+m1.a12*m2.a22)%mod;
	ret.a21=(m1.a21*m2.a11+m1.a22*m2.a21)%mod;
	ret.a22=(m1.a21*m2.a12+m1.a22*m2.a22)%mod;
	return ret;
}

//���������
matrix powM(matrix m,int n){
	if(n==1)
	return m;
	matrix tmp;
	tmp=powM(m,n>>1);
	if(n&1)
	return mulM(m,mulM(tmp,tmp));
	else
	return mulM(tmp,tmp); 
}

//���쳲���������F(n)��ֵ 
long long F(int n){
	matrix ma; 
	if(n==0) return 0;
	if(n==1) return 1;
	if(n>=2)
	{
		matrix m;
		m.a11=1,m.a12=1,m.a21=1,m.a22=0; 
		ma=powM(m,n-1);
		return ma.a11;
	}
}

int main()
{
 	int k;
 	while(scanf("%d",&k)!=EOF){
 		printf("%lld\n",(F(2*(k+1)+1)-1)%mod);
 	}
	return 0;
}
