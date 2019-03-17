#include <iostream>
using namespace std;
#define maxlen 100
/*Lalist�����list�ӵ�һλ��ʼ���棬����λ���á���list��Ԫ��ʱ��list.lastΪ0������Ԫ�غ�Ӵ���Ԫ�صĸ�����ʼ��������*/

class Lalist
{
	public:
		Lalist()
		{
			makeNull();
		}
		
		int Locate(double x)
		{
			for (int i = 1; i <= l.last; i++) if (l.element[i] == x) return i;
			return End();
		}
		
		double Retrieve(int pos)
		{
			if (pos > l.last || pos <= 0) cout << "Sorry, position out of bounds. Aborting...\n";
			else return l.element[pos];
		}
		
		void Delete(int pos)
		{
			if (pos > l.last || pos <= 0) cout << "Sorry, position out of bounds. Aborting...\n";
			else
			{
				for (int i = pos; i < l.last; i++) l.element[i] = l.element[i + 1];
				l.last--;
			}
		}
		
		int Previous(int pos)
		{
			if (pos > l.last || pos <= 0) cout << "Sorry, position out of bounds. Aborting...\n";
			else if (pos == 1) cout << "Sorry, this position has no former position. Aborting...\n";
			else return (pos - 1);
		}
		
		int Next(int pos)
		{
			if (pos > l.last || pos <= 0) cout << "Sorry, position out of bounds. Aborting...\n";
			else if (pos == l.last) cout << "Sorry, this position has no latter position. Aborting...\n";
			else return (pos + 1);
		}
		
		int End()
		{
			return l.last;
		}
		
		double First()
		{
			if (isEmpty()) return End();
			return 1;
		}
		
	    void Insert(double x, int pos)
	    {
	    	if (isFull())
			{
				cout << "Sorry, list is full. Aborting...\n";
				return;
			}
	    	for (int i = l.last; i >= pos; i--) l.element[i + 1] = l.element[i];
	    	l.element[pos] = x;
	    	l.last++;
		}
		
		void Append(double x)
		{
			if (isFull())
			{
				cout << "Sorry, list is full. Aborting...";
				return;
			}
			l.element[l.last++] = x;
		}
		
		void print()
		{
			if (isEmpty())
			{
				cout << "List is empty. Aborting...\n";
				return;
			}
			for (int i = 1; i <= l.last; i++) cout << l.element[i] << " ";
			cout << endl;
		}
		
		void makeNull()
		{
			memset(l.element, 0, sizeof(l.element));
			l.last = 0;
		}
		
	private:
		struct LIST
		{
			double element[maxlen];
			int last;
		}l;
		
		bool isEmpty()
		{
			return (l.last == 0); 
		}
		
		bool isFull()
		{
			return (l.last == maxlen - 1);
		}
		
};

int main()
{
	cout << "Testing... Generating list...\n";
	Lalist l;
	for (int i = 1; i <= 10; i++) l.Insert(double(i), i);
	l.print();
}
