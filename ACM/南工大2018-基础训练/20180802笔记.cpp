#include <iostream>
//#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct node
{
	int x;
	string y;
};

bool cmp(const node n1, const node n2)
{
	if (n1.x == n2.x)
		return n1.y < n2.y;
	return n1.x < n2.x;
}

int main()
{
	//ios::sync_with_stdio(false);
	string str = "Hello World!";
	cout << str << endl;
	printf("%s\n", str.c_str());
	
	node no[3];
	no[0].x = 1;
	no[1].x = 4;
	no[2].x = 1;
	no[0].y = "ccc";
	no[1].y = "bbb";
	no[2].y = "aaa";
	sort(no, no + 3, cmp);
	for (int i = 0; i < 3; i++)
		cout << no[i].x << ' ' << no[i].y << endl;
	
	vector<int> ve;
	int i;
	ve.push_back(3);
	ve.push_back(1);
	ve.push_back(4);
	ve.push_back(6);
	ve.push_back(2);
	sort(ve.begin(), ve.end());//开始位置，最后一个元素的下一位置
	for (i = 0; i < 5; i++)
		cout << ve[i] << ' ';
	cout << endl;
	
	vector<int> ve2(100);
	ve2[100] = 6;
	ve2.push_back(3);
	ve2.push_back(1);
	ve2.push_back(4);
	ve2.push_back(6);
	ve2.push_back(2);
	for (i = 100; i < 105; i++)
		cout << ve2[i] << ' ';
	cout << endl;
	
	int a[] = {1, 3, 4, 6, 7, 2};
	sort(a, a + sizeof(a) / sizeof(int), greater<int>());//从大到小，默认less<int>()从小到大 
	for (i = 0; i < 6; i++)
		cout << a[i] << ' ';
	cout << endl;
	
	
	
	return 0;
}

