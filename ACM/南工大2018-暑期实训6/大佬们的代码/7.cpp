#include<iostream>
#include<math.h>
#include<cmath>
#include<iomanip>
#include<string.h>
#include<stdio.h>
#include <algorithm>
using namespace std;
const int M = 1e3+5;
using namespace std;
struct node
{
    char name[25], type[25];
    int price, quality;
}s[M];
int n, b;
bool jud(int x){
    int i, j, sum = 0, pos, Min;
    for(i = 0; i < n;)
    {
        pos = -1; Min = 1e7;
        for(j = i; j < n&&strcmp(s[i].name, s[j].name)==0; ++ j)
        {
            if(Min > s[j].price&&s[j].quality >= x)
            {
                Min = s[j].price; pos = j;
            }
        }
        if(pos == -1)
            return 0;
       sum += Min;
        i = j;
    }
    if(sum > b) return 0;
    return 1;
}
int f(int left, int right)
{
    while(left <= right)
    {
        int mid = (left+right)>>1;  
        if(jud(mid)) left = mid+1; //这里如果满足就让left = mid+1（因为是要求的最大值）
        else right = mid-1;
    }
    return right;
}
int main()
{
    int t;
    cin>>t;
    while(t --)
    {
        cin>>n>>b;
        int Min = 1e7, Max = 1e-7;
        for(int i = 0; i < n; ++ i)
        {
            cin>>s[i].name>>s[i].type>>s[i].price>>s[i].quality;  //这里的name与题意的type反了，不过不影响做题。。。
            Min = min(Min, s[i].quality);
            Max = max(Max, s[i].quality);
        }
        int ans = f(Min, Max);
       cout<<ans<<endl;
    }
    return 0;
}

