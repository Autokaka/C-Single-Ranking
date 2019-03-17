#ifndef LIBRARYCARD_H
#define LIBRARYCARD_H
#include <string>
using namespace std;

class LibraryCard
{
public:
	LibraryCard();
	void regist();
	void login();
	void printID();
	/*²âÊÔ½Ó¿Ú*/void refreshDatabase();
private:
	void setName(string);
	void setPassword(string);
	int Number;
	string Password;
	string Name;
	int Level;
	int Limit;
};

#endif

