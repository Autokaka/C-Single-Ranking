#ifndef LIBRARYCARD_H
#define LIBRARYCARD_H
#include <string>
using namespace std;

class LibraryCard
{
public:
	LibraryCard();
	void regist();//注册
	void login();//登录
	int getNumber();//获取当前登录的读者编号
	void withdraw(int);//注销
	void modify(int);//修改账户信息
	void borrowTag(int, string);//借书
	void returnTag(int, string);//还书
	void printID(int);
	/*测试接口*/void refreshDatabase();
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

