#include <iostream>
#include <algorithm>
using namespace std;
const int M = 100005;
int a,b;
int father[M];       //记录父节点 
bool circle;         //判断是否存在环 
bool visit[M];       //用来记录顶点数  
int edgenum,vnum;    //分别表示边数，顶点数 

void initial( ){
    for( int i=0 ; i<M ; i++ )
        father[i] = i,visit[i]=false;
    circle = false;  
    edgenum = vnum = 0;      
}
 
int find(  int x ){
    return x == father[x] ? x : father[x] = find(father[x]);     //找祖先节点 + 路径压缩 
}
 
void merge( int a ,int b ){
    if( a == b )
        circle = true;
    int x , y;
    x = find(a);
    y = find(b);
    if( x != y ){
        father[x] = y;
        edgenum++;       //引出一条边 
    }
    else
        circle = true;   //x==y，说明他们是同一个祖先，一旦连通便与祖先3者成环 
}
 
int main(){
    while( true ){
        initial( );
        scanf("%d%d",&a,&b);
        if( a==0 && b==0 ){     //为空树 
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
        if(!circle&&edgenum+1 == vnum )//为什么还要判断是否edgenum+1==vnum ,不是已经成环了吗 
            printf("Yes\n");				//知道了，还要保证每两两个要连载一起，所以要有这个判断条件 
        else
            printf("No\n");
    }     
    return 0;
}
