#include <iostream>
#include <algorithm>
using namespace std;
const int M = 100005;

int a,b;
bool visit[M];       //用来记录顶点数  
   
int main(){
    while( true ){
        int edgenum=0,vnum=0; 
        for( int i=0 ; i<M ; i++ )
        	visit[i]=false;
        
        scanf("%d%d",&a,&b);
        if( a==0 && b==0 ){     
            printf("Yes\n");       
            continue;
        }
        if( a==-1 && b==-1 )
            break;
        visit[a] = true;
        visit[b] = true;
        edgenum++;
	
        while( true ){
            scanf("%d%d",&a,&b);
            if( a==0 && b==0 )
                break;
            visit[a] = true;
            visit[b] = true;
            edgenum++;      
        }
        for( int i=0 ; i<M ; i++ )
            if( visit[i] )
                vnum++;  
                
        if(edgenum+1 == vnum ) 
            printf("Yes\n");		   
        else
            printf("No\n");
    }     
    return 0;
}
