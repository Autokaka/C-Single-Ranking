#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>

#define PI 3.1415926535898
#define eps 1e-7
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		double r,R,H,V;
		cin>>r>>R>>H>>V;
		if(PI*(R*R + r*r + R*r)*H/3 < V)	//水体积比杯子大 
		{
			cout<<fixed<<setprecision(6)<<H<<endl;
			continue;
		}
		if(R == r)							//圆柱水杯情况 
		{
			cout<<fixed<<setprecision(6)<<V/PI/r/r<<endl;
			continue;	
		}
		/*二分查找*/
		double left = 0.0;
		double right = H;
		double mid;
		while(right-left > eps)
		{
			mid = (right + left) / 2;
            double rm = r+(R-r)*mid/H;
            double v = mid*(rm*rm+r*r+rm*r)*PI/3.0;
            if(V > v)
                left = mid;
            if(V < v)
                right = mid;

		}
		cout<<fixed<<setprecision(6)<<mid<<endl;
	}	
	return 0;
}

// V = PI*(1/3) * h * (R^2 + r^2 + R*r) 

