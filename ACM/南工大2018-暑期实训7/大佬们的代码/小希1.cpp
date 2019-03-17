#include <iostream>
#include <algorithm>
using namespace std;
const int M = 100005;
int a,b;
int father[M];       //��¼���ڵ� 
bool circle;         //�ж��Ƿ���ڻ� 
bool visit[M];       //������¼������  
int edgenum,vnum;    //�ֱ��ʾ������������ 

void initial( ){
    for( int i=0 ; i<M ; i++ )
        father[i] = i,visit[i]=false;
    circle = false;  
    edgenum = vnum = 0;      
}
 
int find(  int x ){
    return x == father[x] ? x : father[x] = find(father[x]);     //�����Ƚڵ� + ·��ѹ�� 
}
 
void merge( int a ,int b ){
    if( a == b )
        circle = true;
    int x , y;
    x = find(a);
    y = find(b);
    if( x != y ){
        father[x] = y;
        edgenum++;       //����һ���� 
    }
    else
        circle = true;   //x==y��˵��������ͬһ�����ȣ�һ����ͨ��������3�߳ɻ� 
}
 
int main(){
    while( true ){
        initial( );
        scanf("%d%d",&a,&b);
        if( a==0 && b==0 ){     //Ϊ���� 
            printf("Yes\n");       
            continue;
        }
        if( a==-1 && b==-1 )
            break;
        visit[a] = true;
        visit[b] = true;
        merge( a,b );
        while( true ){
            scanf("%d%d",&a,&b);
            if( a==0 && b==0 )
                break;
            visit[a] = true;
            visit[b] = true;
            merge( a , b );      
        }
        for( int i=0 ; i<M ; i++ )
            if( visit[i] )
                vnum++;  
        if(!circle&&edgenum+1 == vnum )//Ϊʲô��Ҫ�ж��Ƿ�edgenum+1==vnum ,�����Ѿ��ɻ����� 
            printf("Yes\n");				//֪���ˣ���Ҫ��֤ÿ������Ҫ����һ������Ҫ������ж����� 
        else
            printf("No\n");
    }     
    return 0;
}
