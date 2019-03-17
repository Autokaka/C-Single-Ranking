#ifndef LIBRARYCARD_H
#define LIBRARYCARD_H
#include <string>
using namespace std;

class LibraryCard
{
public:
	LibraryCard();
	void regist();//ע��
	void login();//��¼
	int getNumber();//��ȡ��ǰ��¼�Ķ��߱��
	void withdraw(int);//ע��
	void modify(int);//�޸��˻���Ϣ
	void borrowTag(int, string);//����
	void returnTag(int, string);//����
	void printID(int);
	/*���Խӿ�*/void refreshDatabase();
private:
	void setName(string);
	void setPassword(string);
	int Number;
	string Name;
	string Password;
	int Level;
	int Limit;
	string Bookcode;
};

#endif

