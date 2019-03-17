#include "Schedule.h"
#include <iostream>
#include "sqlite3.h"
#pragma comment(lib, "sqlite3.lib")
using namespace std;

Schedule::Schedule()
	:db()
{
	sqlite3 *db;
	sqlite3_stmt * stmt = NULL;
	const char *zTail;
	int res = sqlite3_open("DataBase.db", &db);
	if (sqlite3_prepare_v2(db, "SELECT SCHOOL, MAJORTYPE, CLASS, COUNT from STUDENT;", -1, &stmt, &zTail) == SQLITE_OK)
	{
		while (sqlite3_step(stmt) == SQLITE_ROW)
		{
			const char *Major = 0;
			if (sqlite3_column_int(stmt, 1) == 1)
				Major = "ScienceSchedule.db";
			else
				if (sqlite3_column_int(stmt, 1) == 0)
					Major = "ArtSchedule.db";
			string School = string((const char *)sqlite3_column_text(stmt, 0));
			string Classnum = to_string(sqlite3_column_int(stmt, 2));
			initMainSchedulebyClass(Major, School + "Class" + Classnum, sqlite3_column_int(stmt, 2));
		}
	}
	sqlite3_finalize(stmt);
	sqlite3_close(db);
}

void Schedule::initMainSchedulebyClass(const char *zhuxiu, string banji, int renshu)
{
	//依照班级初始化每个班级的统一主课表(空课表)
	sqlite3 * db;
	sqlite3_open(zhuxiu, &db);
	string line1 = "CREATE TABLE ";
	string line2 = " (" \
		"ClassDay            INT PRIMARY KEY        NOT NULL," \
		"Mon                 TEXT                   ," \
		"Tue                 TEXT                   ," \
		"Wed                 TEXT                   ," \
		"Thu                 TEXT                   ," \
		"Fri                 TEXT                   );";
	string line3 = line1 + banji + line2;
	const char *sql= const_cast<char*>(line3.c_str());
	sqlite3_exec(db, sql, 0, 0, 0);
	sqlite3_close(db);
	for (int i = 1; i <= 5; i++)
	{
		sqlite3_open(zhuxiu, &db);
		string line1 = "INSERT INTO ";
		string line2 = " VALUES('%d','%s','%s','%s','%s','%s')";
		string line3 = line1 + banji + line2;
		const char *sql = sqlite3_mprintf(const_cast<char*>(line3.c_str()), i, NULL, NULL, NULL, NULL, NULL);
		sqlite3_exec(db, sql, 0, 0, 0);
		sqlite3_close(db);
	}
	//把每个班级的主课表按照规则录入课程信息
	sqlite3 *db;
	sqlite3_stmt * stmt = NULL;
	const char *zTail;
	int res = sqlite3_open("DataBase.db", &db);
	if (sqlite3_prepare_v2(db, "SELECT CODE, TYPE, CAPACITY, TIME, CLASSROOM from SUBJECT;", -1, &stmt, &zTail) == SQLITE_OK)
	{
		while (sqlite3_step(stmt) == SQLITE_ROW)
		{
			if (sqlite3_column_int(stmt, 1) == 1)//是理科，存入理科课表
			{
				if (sqlite3_column_int(stmt, 2) - renshu >= 0)
				{
					const unsigned char *name = sqlite3_column_text(stmt, 0);
					int time = sqlite3_column_int(stmt, 1);
					int classroom = sqlite3_column_int(stmt, 2);
					int num = time % 10;
					const char *day = 0;
					switch (time / 10)
					{
					case 1:
					{day = "Mon"; break; }
					case 2:
					{day = "Tue"; break; }
					case 3:
					{day = "Wed"; break; }
					case 4:
					{day = "Thu"; break; }
					case 5:
					{day = "Fri"; break; }
					}
					sqlite3 *db1;
					sqlite3_open("Schedules.db", &db1);
					const char *sql = sqlite3_mprintf("UPDATE Schedule set ('%s') = ('%s') where ClassDay = ('%d');", day, code, num);
					char *zErrMsg = 0;
					int res = sqlite3_exec(db1, sql, 0, 0, &zErrMsg);
					if (res != SQLITE_OK)
					{
						cout << "\n * Failed: " << zErrMsg << endl << endl;
						sqlite3_free(zErrMsg);
					}
					sqlite3_close(db1);
				}
			}
			else
				if (sqlite3_column_int(stmt, 3) == 0)//是文科，存入文科课表
				{

				}
			
		}
	}
	sqlite3_finalize(stmt);
	sqlite3_close(db);
}