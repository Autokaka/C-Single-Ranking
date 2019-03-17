//选课系统数据库
#include <iostream> 
#include "sqlite3.h"
#pragma comment(lib, "sqlite3.lib") 

using namespace std;

int main()
{
	sqlite3 * db;
	int res = sqlite3_open("DataBase.db", &db);

	if (res != SQLITE_OK)
	{
		cout << "fail!" << sqlite3_errmsg(db) << endl;
		return 0;
	}
	else
	{
		cout << "success" << endl;
	}


	//创建 课程 表
	const char * sq1 = "CREATE TABLE SUBJECT("	 \
		"No  INT PRIMARY KEY    	NOT NULL,"	 \
		"NAME			 TEXT       NOT NULL,"	 \
		"TYPE            TEXT        NOT NULL,"  \
		"OPENMAJOR		 CHAR(256)  NOT NULL,"   \
		"OPENTERM		 CHAR(256)  NOT NULL);";

	char * zErrMsg = 0;

	res = sqlite3_exec(db, sq1, 0, 0, &zErrMsg);

	if (res == SQLITE_OK) {
		cout << "CREATE TABLE SUBJECT success"<<endl;
	}
	else {
		cout << "CREATE TABLE SUBJECT fail:" << zErrMsg << endl;
		sqlite3_free(zErrMsg);
	}


	//创建 老师 表
	const char * sq2 = "CREATE TABLE TEACHER("	\
		"No  INT PRIMARY KEY    	NOT NULL,"	\
		"NAME			 TEXT       NOT NULL,"	\
		"POSITION        CHAR(50)   NOT NULL);";

	zErrMsg = 0;

	res = sqlite3_exec(db, sq2, 0, 0, &zErrMsg);

	if (res == SQLITE_OK)
		cout << "CREATE TABLE TEACHER success"<<endl;
	else 
	{
		cout << "CREATE TABLE TEACHER fail:" << zErrMsg << endl;
		sqlite3_free(zErrMsg);
	}


	//创建 学生 表
	const char * sq3 = "CREATE TABLE STUDENT("	\
		"No  INT PRIMARY KEY    	NOT NULL,"	\
		"NAME			 TEXT       NOT NULL,"	\
		"SEX             TEXT       NOT NULL,"  \
		"SCHOOL          TEXT       NOT NULL,"  \
		"MAJORTYPE      INT        NOT NULL,"  \
		"CLASS           TEXT       NOT NULL);";


	zErrMsg = 0;

	res = sqlite3_exec(db, sq3, 0, 0, &zErrMsg);

	if (res == SQLITE_OK)
		cout << "CREATE TABLE STUDENT success"<<endl;
	else
	{
		cout << "CREATE TABLE STUDENT fail:" << zErrMsg << endl;
		sqlite3_free(zErrMsg);
	}


	//创建 教室 表
	const char * sq4 = "CREATE TABLE CLASSROOM("	\
		"No  INT PRIMARY KEY    	NOT NULL,"   	\
		"CAPACITY           INT       NOT NULL);";


	zErrMsg = 0;

	res = sqlite3_exec(db, sq4, 0, 0, &zErrMsg);

	if (res == SQLITE_OK)
		cout << "CREATE TABLE CLASSROOM success"<<endl;
	else
	{
		cout << "CREATE TABLE CLASSROOM fail:" << zErrMsg << endl;
		sqlite3_free(zErrMsg);
	}

	sqlite3_close(db);

	system("pause");
	return 0;
}
