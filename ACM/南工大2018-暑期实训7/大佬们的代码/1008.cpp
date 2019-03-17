#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
#define N 200010 
int a[N],sum[N];

map<string,int>m;

int find(int t){
    if(t!=a[t])
        a[t]=find(a[t]);
    return a[t];
}
void Union(int x,int y){
	x=find(x);
    y=find(y);
    if(x==y){
        cout<<sum[x]<<endl;  			//��������Ѿ��������ˣ�    
        return;					  		//ֱ���������һ���������������� 
    }else{
        cout<<sum[x]+sum[y]<<endl;
	    a[x]=y;							//������˲������ѣ��������������֮�ͣ�
	    sum[y]+=sum[x];					//Ȼ����ʹ���˳�Ϊ���ѣ��������ݡ�
	    sum[x]+=sum[y];
	}
}
int main()
{
    int t;
    while(cin>>t){
		while(t--){
	        char c1[30],c2[30];
	        int n;
	        cin>>n;
	        for(int i=1;i<=2*n;i++){	//��ʼ����ÿ����ֻ���Լ������ѣ���������Ϊ 1 
	            a[i]=i;
	            sum[i]=1;
	        }
	        int cnt=1;					 //����->��� ��ÿ��һ�����˳���ʱ +1 
	        m.clear();
	        while(n--){
	            cin>>c1>>c2;
	            if(!m[c1])
	                m[c1]=cnt++;
	            if(!m[c2])
	                m[c2]=cnt++; 
	            Union(m[c1],m[c2]);
	        }
	    }
	}
	return 0;
}
