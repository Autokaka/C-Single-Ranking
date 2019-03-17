#include "Database.h"
#include <iostream>
#include "sqlite3.h"  
#pragma comment(lib, "sqlite3.lib")
using namespace std;

Database::Database()
{
	initDatabase();
}

void Database::addLessonInfo(const char *mingcheng, int xingzhi, int zongxueshi, int lilunxueshi, int shijianxueshi, int xuefen, int kaikezhuanye , int kaikexueqi, int kechengrongliang)
{
	sqlite3 * db;
	int res = sqlite3_open("LessonInfo.db", &db);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to open LessonInfo: " << sqlite3_errmsg(db) << endl;
		return;
	}
	int cnt = 1;
	while (1)
	{
		char *sql = sqlite3_mprintf("INSERT INTO LessonInfo VALUES(%d,'%s',%d,%d,%d,%d,%d,%d,%d,%d)", cnt, mingcheng, xingzhi, zongxueshi, lilunxueshi, shijianxueshi, xuefen, kaikezhuanye, kaikexueqi, kechengrongliang);
		res = sqlite3_exec(db, sql, 0, 0, 0);
		if (res == SQLITE_OK)
			break;
		else
			cnt++;
	} 
	sqlite3_close(db);
}
void Database::delLessonInfo(int ID)
{
	sqlite3 * db;
	int res = sqlite3_open("LessonInfo.db", &db);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to open LessonInfo: " << sqlite3_errmsg(db) << endl;
		return;
	}
	const char *sql = sqlite3_mprintf("DELETE from LessonInfo where ID=(%d)", ID);
	char *zErrMsg = 0;
	res = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to delete message of LessonInfo: " << zErrMsg << endl << endl;
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);
}
void Database::modLessonInfo(int ID, const char *target)
{
	cout << "\n * 输入要改成的值：  ";
	char modify_char[100];
	int modify_int;
	if (target == "Name")
		cin >> modify_char;
	else
		cin >> modify_int;
	
	sqlite3 * db;
	int res = sqlite3_open("LessonInfo.db", &db);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to open LessonInfo: " << sqlite3_errmsg(db) << endl;
		return;
	}
	char *sql;
	if (target == "Name")
		sql = sqlite3_mprintf("UPDATE LessonInfo set ('%s')=('%s') where ID=(%d)", target, modify_char, ID);
	else
		sql = sqlite3_mprintf("UPDATE LessonInfo set ('%s')=(%d) where ID=(%d)", target, modify_int, ID);
	res = sqlite3_exec(db, sql, 0, 0, 0);
	sqlite3_close(db);
}

void Database::addRoomInfo(int haoma, int rongliang)
{
	sqlite3 * db;
	int res = sqlite3_open("RoomInfo.db", &db);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to open RoomInfo: " << sqlite3_errmsg(db) << endl;
		return;
	}
	int cnt = 1;
	char *sql = sqlite3_mprintf("INSERT INTO RoomInfo VALUES(%d,%d)", haoma, rongliang);
	char *zErrMsg = 0;
	res = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to add new term into RoomnInfo: " << zErrMsg << endl << endl;
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);
}
void Database::delRoomInfo(int ID)
{
	sqlite3 * db;
	int res = sqlite3_open("RoomInfo.db", &db);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to open RoomInfo: " << sqlite3_errmsg(db) << endl;
		return;
	}
	const char *sql = sqlite3_mprintf("DELETE from RoomInfo where ID=(%d)", ID);
	char *zErrMsg = 0;
	res = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to delete message of RoomInfo: " << zErrMsg << endl << endl;
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);
}
void Database::modRoomInfo(int ID, const char *target)
{
	cout << "\n * 输入要改成的值：  ";
	int modify_int;
	cin >> modify_int;

	sqlite3 * db;
	int res = sqlite3_open("RoomInfo.db", &db);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to open RoomInfo: " << sqlite3_errmsg(db) << endl;
		return;
	}
	char *sql = sqlite3_mprintf("UPDATE RoomInfo set ('%s')=(%d) where ID=(%d)", target, modify_int, ID);
	res = sqlite3_exec(db, sql, 0, 0, 0);
	sqlite3_close(db);
}

void Database::addTeacherInfo(const char *xingming, int zhicheng)
{
	sqlite3 * db;
	int res = sqlite3_open("TeacherInfo.db", &db);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to open TeacherInfo: " << sqlite3_errmsg(db) << endl;
		return;
	}
	int cnt = 1;
	while (1)
	{
		char *sql = sqlite3_mprintf("INSERT INTO TeacherInfo VALUES(%d,%d,%d)", cnt, xingming, zhicheng);
		res = sqlite3_exec(db, sql, 0, 0, 0);
		if (res == SQLITE_OK)
			break;
		else
			cnt++;
	}
	sqlite3_close(db);
}
void Database::delTeacherInfo(int ID)
{
	sqlite3 * db;
	int res = sqlite3_open("TeacherInfo.db", &db);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to open TeacherInfo: " << sqlite3_errmsg(db) << endl;
		return;
	}
	const char *sql = sqlite3_mprintf("DELETE from TeacherInfo where ID=(%d)", ID);
	char *zErrMsg = 0;
	res = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to delete message of TeacherInfo: " << zErrMsg << endl << endl;
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);
}
void Database::modTeacherInfo(int ID, const char *target)
{
	cout << "\n * 输入要改成的值：  ";
	char modify_char[100];
	int modify_int;
	if (target == "Name")
		cin >> modify_char;
	else
		cin >> modify_int;
	sqlite3 * db;
	int res = sqlite3_open("TeacherInfo.db", &db);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to open TeacherInfo: " << sqlite3_errmsg(db) << endl;
		return;
	}
	char *sql;
	if (target == "Name")
		sql = sqlite3_mprintf("UPDATE TeacherInfo set ('%s')=('%s') where ID=(%d)", target, modify_char, ID);
	else
		sql = sqlite3_mprintf("UPDATE TeacherInfo set ('%s')=(%d) where ID=(%d)", target, modify_int, ID);
	res = sqlite3_exec(db, sql, 0, 0, 0);
	sqlite3_close(db);
}

void Database::addStudentInfo(const char *xueyuan, int banji, const char *xingming, const char *xingbie, int kaikezhuanye)
{
	sqlite3 * db;
	int res = sqlite3_open("StudentInfo.db", &db);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to open StudentInfo: " << sqlite3_errmsg(db) << endl;
		return;
	}
	int cnt = 1;
	while (1)
	{
		char *sql = sqlite3_mprintf("INSERT INTO StudentInfo VALUES(%d,'%s',%d,'%s','%s',%d", cnt, xingming, banji, xingming, xingbie, kaikezhuanye);
		res = sqlite3_exec(db, sql, 0, 0, 0);
		if (res == SQLITE_OK)
			break;
		else
			cnt++;
	}
	sqlite3_close(db);
}
void Database::delStudentInfo(int ID)
{
	sqlite3 * db;
	int res = sqlite3_open("StudentInfo.db", &db);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to open StudentInfo: " << sqlite3_errmsg(db) << endl;
		return;
	}
	const char *sql = sqlite3_mprintf("DELETE from StudentInfo where ID=(%d)", ID);
	char *zErrMsg = 0;
	res = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to delete message of StudentInfo: " << zErrMsg << endl << endl;
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);
}
void Database::modStudentInfo(int ID, const char *target)
{
	cout << "\n * 输入要改成的值：  ";
	char modify_char[100];
	int modify_int;
	if (target == "ID" || target == "Class" || target == "Profession")
		cin >> modify_int;
	else
		cin >> modify_char;
	sqlite3 * db;
	int res = sqlite3_open("TeacherInfo.db", &db);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to open TeacherInfo: " << sqlite3_errmsg(db) << endl;
		return;
	}
	char *sql;
	if (target == "ID" || target == "Class" || target == "Profession")
		sql = sqlite3_mprintf("UPDATE TeacherInfo set ('%s')=(%d) where ID=(%d)", target, modify_int, ID);
	else
		sql = sqlite3_mprintf("UPDATE TeacherInfo set ('%s')=('%s') where ID=(%d)", target, modify_char, ID);
	res = sqlite3_exec(db, sql, 0, 0, 0);
	sqlite3_close(db);
}

void Database::initDatabase()
{
	sqlite3 * db;
	int res = sqlite3_open("LessonInfo.db", &db);
	if (res != SQLITE_OK) 
	{
		cout << "\n * Failed to open LessonInfo: " << sqlite3_errmsg(db) << endl;
		return;
	}
	const char * sql = "CREATE TABLE LessonInfo(" \
		"ID INT PRIMARY KEY        NOT NULL," \
		"Name           TEXT       NOT NULL," \
		"Type           INT        NOT NULL," \
		"allHour        INT        NOT NULL," \
		"TheoryHour     INT        NOT NULL," \
		"PracticeHour   INT        NOT NULL," \
		"Score          INT        NOT NULL," \
		"Profession     INT        NOT NULL," \
		"OpeningTerm    INT        NOT NULL," \
		"Capacity       INT        NOT NULL);";
	char *zErrMsg = 0;
	res = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to create Table of LessonInfo: " << zErrMsg << endl <<endl;
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);



	res = sqlite3_open("RoomInfo.db", &db);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to open RoomInfo: " << sqlite3_errmsg(db) << endl << endl;
		return;
	}
	sql = "CREATE TABLE RoomInfo(" \
		"ID INT PRIMARY KEY     NOT NULL," \
		"Capacity       INT     NOT NULL);";
	res = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to create Table of RoomInfo: " << zErrMsg << endl << endl;
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);



	res = sqlite3_open("TeacherInfo.db", &db);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to open TeacherInfo: " << sqlite3_errmsg(db) << endl << endl;
		return;
	}
	sql = "CREATE TABLE TeacherInfo(" \
		"ID INT PRIMARY KEY     NOT NULL," \
		"Name           TEXT    NOT NULL," \
		"Rank           INT     NOT NULL);";
	res = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to create Table of TeacherInfo: " << zErrMsg << endl << endl;
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);



	res = sqlite3_open("StudentInfo.db", &db);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to open StudentInfo: " << sqlite3_errmsg(db) << endl << endl;
		return;
	}
	sql = "CREATE TABLE StudentInfo(" \
		"ID INT PRIMARY KEY     NOT NULL," \
		"Institute      TEXT    NOT NULL," \
		"Class          INT     NOT NULL," \
		"Name           TEXT    NOT NULL," \
		"Sex            TEXT    NOT NULL," \
		"Profession     INT     NOT NULL);";
	res = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to create Table of StudentInfo: " << zErrMsg << endl << endl;
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);
}
/*测试接口*/void Database::printDatabase()
{
	sqlite3 * db;
	int res = sqlite3_open("LessonInfo.db", &db);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to open LessonInfo: " << sqlite3_errmsg(db) << endl;
		return;
	}
	const char *sql = sqlite3_mprintf("SELECT * from LessonInfo");
	char *zErrMsg = 0;
	res = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to print LessonInfo: " << zErrMsg << endl << endl;
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);

	cout << "\n\n\n\n";

	res = sqlite3_open("RoomInfo.db", &db);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to open RoomInfo: " << sqlite3_errmsg(db) << endl;
		return;
	}
	sql = sqlite3_mprintf("SELECT * from RoomInfo");
	res = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to print RoomInfo: " << zErrMsg << endl << endl;
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);

	cout << "\n\n\n\n";

	res = sqlite3_open("TeacherInfo.db", &db);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to open TeacherInfo: " << sqlite3_errmsg(db) << endl;
		return;
	}
	sql = sqlite3_mprintf("SELECT * from TeacherInfo");
	res = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to print TeacherInfo: " << zErrMsg << endl << endl;
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);

	cout << "\n\n\n\n";

	res = sqlite3_open("StudentInfo.db", &db);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to open StudentInfo: " << sqlite3_errmsg(db) << endl;
		return;
	}
	sql = sqlite3_mprintf("SELECT * from StudentInfo");
	res = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to print StudentInfo: " << zErrMsg << endl << endl;
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);
}
/*测试接口*/void Database::clearDatabase()
{
	sqlite3 * db;
	int res = sqlite3_open("LessonInfo.db", &db);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to open LessonInfo: " << sqlite3_errmsg(db) << endl;
		return;
	}
	const char *sql = sqlite3_mprintf("DELETE from LessonInfo");
	char *zErrMsg = 0;
	res = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to clear LessonInfo: " << zErrMsg << endl << endl;
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);



	res = sqlite3_open("RoomInfo.db", &db);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to open RoomInfo: " << sqlite3_errmsg(db) << endl;
		return;
	}
	sql = sqlite3_mprintf("DELETE from RoomInfo");
	res = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to clear RoomInfo: " << zErrMsg << endl << endl;
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);



	res = sqlite3_open("TeacherInfo.db", &db);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to open TeacherInfo: " << sqlite3_errmsg(db) << endl;
		return;
	}
	sql = sqlite3_mprintf("DELETE from TeacherInfo");
	res = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to clear TeacherInfo: " << zErrMsg << endl << endl;
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);



	res = sqlite3_open("StudentInfo.db", &db);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to open StudentInfo: " << sqlite3_errmsg(db) << endl;
		return;
	}
	sql = sqlite3_mprintf("DELETE from StudentInfo");
	res = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (res != SQLITE_OK)
	{
		cout << "\n * Failed to clear StudentInfo: " << zErrMsg << endl << endl;
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);
}