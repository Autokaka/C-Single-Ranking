#include "DBoperate.h"
#include <iostream> 
#include "sqlite3.h"
#pragma comment(lib, "sqlite3.lib") 

static int callback(void *data, int argc, char **argv, char **azColName) 
{
	int i;
	fprintf(stderr, "%s: ", (const char*)data);
	for (i = 0; i<argc; i++) 
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

DBoperate::DBoperate()
{
	sqlite3 * db;
	int res = sqlite3_open("DataBase.db", &db);

	if (res != SQLITE_OK)
	{
		cout << "fail!" << sqlite3_errmsg(db) << endl;
	}
	else
	{
		cout << "success" << endl;
	}


	//创建 课程 表
	const char * sq1 = "CREATE TABLE SUBJECT("	\
		"NO              INT        NOT NULL,"
		"CODE			 TEXT    	NOT NULL,"  \
		"NAME			 TEXT       NOT NULL,"	\
		"TEACHER         INT        NOT NULL,"  \
		"TYPE            INT        NOT NULL,"  \
		"OPENMAJOR		 INT        NOT NULL,"  \
		"OPENTERM		 TEXT       NOT NULL,"  \
		"CREDIT          INT        NOT NULL,"  \
		"CREDITHOUR      INT        NOT NULL,"  \
		"CAPACITY        INT	            ,"	\
		"TIME            INT        NOT NULL,"  \
		"CLASSROOM       INT        NOT NULL);";
	/* 
	type  1-必修  2-选修  3-体育  4英语
	openmajor  1-文科 2-理科 0兼修
	capacity 若为-1表示为必修课无限报人数
	*/

	char * zErrMsg = 0;

	res = sqlite3_exec(db, sq1, 0, 0, &zErrMsg);

	if (res == SQLITE_OK) {
		cout << "CREATE TABLE SUBJECT success" << endl;
	}
	else {
		cout << "CREATE TABLE SUBJECT fail:" << zErrMsg << endl;
		sqlite3_free(zErrMsg);
	}


	//创建 老师 表
	const char * sq2 = "CREATE TABLE TEACHER("	\
		"No  INT PRIMARY KEY    	NOT NULL,"	\
		"NAME			 TEXT       NOT NULL,"	\
		"POSITION        TEXT       NOT NULL);";

	zErrMsg = 0;

	res = sqlite3_exec(db, sq2, 0, 0, &zErrMsg);

	if (res == SQLITE_OK)
		cout << "CREATE TABLE TEACHER success" << endl;
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
		"MAJORTYPE       INT        NOT NULL,"  \
		"CLASS           TEXT       NOT NULL);";


	zErrMsg = 0;

	res = sqlite3_exec(db, sq3, 0, 0, &zErrMsg);

	if (res == SQLITE_OK)
		cout << "CREATE TABLE STUDENT success" << endl;
	else
	{
		cout << "CREATE TABLE STUDENT fail:" << zErrMsg << endl;
		sqlite3_free(zErrMsg);
	}


	//创建 教室 表
	const char * sq4 = "CREATE TABLE CLASSROOM("	\
		"No  INT PRIMARY KEY    	NOT NULL,"   	\
		"CAPACITY        INT       NOT NULL);";


	zErrMsg = 0;

	res = sqlite3_exec(db, sq4, 0, 0, &zErrMsg);

	if (res == SQLITE_OK)
		cout << "CREATE TABLE CLASSROOM success" << endl;
	else
	{
		cout << "CREATE TABLE CLASSROOM fail:" << zErrMsg << endl;
		sqlite3_free(zErrMsg);
	}

	sqlite3_close(db);
}

bool DBoperate::AddSubject()
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;

	rc = sqlite3_open("DataBase.db", &db);
	if (rc) 
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return false;
	}

	int cnt;
	int flag=0;

	char * code = new char[20];
	char * name = new char[20];
	char * teacher = new char[20];
	int type;
	int openmajor;				//开课专业 1-文科 2-理科 0文理兼修
	char * openterm = new char[20];
	int credit;
	int credithour;
	int capacity = 0;
	int time;
	int classroom;

	cout << "请输入课程编码号（例：GS001 表示 由001号老师教授的高数课）:";
	cin >> code;
	cout << "请输入课程名称:";
	cin >> name;
	cout << "请输入授课教师编号:";
	cin >> teacher;
	cout << "请输入课程性质编号（1-必修  2-选修  3-体育  4-英语）:";
	cin >> type;
	cout << "请输入开课专业代号（1-文科 2-理科 0兼修）:";
	cin >> openmajor;
	cout << "请输入开课学期:";
	cin >> openterm;
	cout << "请输入该科学分:";
	cin >> credit;
	if (type != 1)
	{
		cout << "请输入选修课容量:";
		cin >> capacity;
	}
	else capacity = -1;
	cout << "请输入上课时间(由一个两位数表示，11表示周一第一节课，54表示周五第四节课):";
	cin >> time;
	cout << "请输入上课教室编号:";
	cin >> classroom;

	const char * CODE = code;
	const char * NAME = name;
	const char * TEACHER = teacher;
	const char * OPENTERM = openterm;
	
	credithour = 16 * credit;

	//判断时间教室是否同时冲突
	for (cnt = 1;; cnt++)
	{
		sql = sqlite3_mprintf("SELECT * FROM SUBJECT WHERE TIME = '%d' AND CLASSROOM = '%d'", \
		                       time, teacher);
		if (rc = SQLITE_OK)
			flag++;
	}

	if (flag > 0)
	{
		cout << "该时段教室已被占用，录入课程失败。";
		return false;
	}

	//若时间教室不冲突，则在表中添加记录。
	for (cnt = 1;;cnt++)
	{
		sql = sqlite3_mprintf("INSERT INTO SUBJECT(No,NAME,TYPE,OPENMAJOR,OPENTERM,CREDIT,CREDITHOUR,) \
                           VALUES('%d','%s','%s','%d','%d','%d','%s','%d','%d','%d','%d','%d')", \
			cnt, CODE, NAME, TEACHER, type, openmajor, OPENTERM, credit, credithour, capacity, time, classroom);

		rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
		if (rc != SQLITE_OK)
			continue;
		else
			break;
	}

	sqlite3_close(db);
	return true;
}

bool DBoperate::SearchSubject(string No)
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;
	const char* data = "Callback function called";

	rc = sqlite3_open("DataBase.db", &db);
	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return false;
	}
	
	int len = No.length();
	char *p = new char[len + 1];
	No.copy(p, len, 0);
	*(p + len) = '\0';

	const char * key = p;

	sql = sqlite3_mprintf("SELECT * FROM SUBJECT WHERE No IN (    \
						   SELECT No FROM SUBJECT  \
		                   WHERE No = '%s' OR NAME = '%s' OR TYPE = '%s' OR OPENMAJOR = '%s' OR OPENTERM = '%s' );", key, key, key, key, key);

	rc = sqlite3_exec(db, sql, callback, (char*)data, &zErrMsg);
	if (rc != SQLITE_OK) 
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		sqlite3_close(db);
		return false;
	}
	else 
	{	
		sqlite3_close(db);
		return true;
	}
}

bool DBoperate::UpdateSubject(string No, string column, string newdata)
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;

	rc = sqlite3_open("DataBase.db", &db);
	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return false;
	}

	int len = No.length();
	char *o = new char[len + 1];
	No.copy(o, len, 0);
	*(o + len) = '\0';

	len = column.length();
	char *p = new char[len + 1];
	column.copy(p, len, 0);
	*(p + len) = '\0';

	len = newdata.length();
	char *q = new char[len + 1];
	newdata.copy(q, len, 0);
	*(q + len) = '\0';

	const char * NO = o;
	const char * COLUMN = p;
	const char * NEWDATA = q;

	sql = sqlite3_mprintf("UPDATE SUBJECT set '%s' = '%s' where No = '%s';", COLUMN, NEWDATA, NO);

	rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		sqlite3_close(db);
		return false;
	}
	else
	{
		sqlite3_close(db);
		return true;
	}
}

bool DBoperate::SubjectPrint(string No)
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;
	const char* data = "Callback function called";

	int len = No.length();
	char *p = new char[len + 1];
	No.copy(p, len, 0);
	*(p + len) = '\0';

	const char * NO = p;

	rc = sqlite3_open("DataBase.db", &db);
	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return false;
	}

	sql = sqlite3_mprintf("SELECT * FROM SUBJECT WHERE No = '%s'", NO);
	
	rc = sqlite3_exec(db, sql, callback, (char*)data, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		sqlite3_close(db);
		return false;
	}
	else
	{
		sqlite3_close(db);
		return true;
	}
}

bool DBoperate::DeleteSubject(string n)
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;

	int len = n.length();
	char *p = new char[len + 1];
	n.copy(p, len, 0);
	*(p + len) = '\0';

	const char * N = p;

	rc = sqlite3_open("DataBase.db", &db);
	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return false;
	}

	sql = sqlite3_mprintf("DELETE FROM SUBJECT WHERE No = '%s'", N);

	rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		sqlite3_close(db);
		return false;
	}
	else
	{
		sqlite3_close(db);
		return true;
	}
}

bool DBoperate::AddTeacher()
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;

	rc = sqlite3_open("DataBase.db", &db);
	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return false;
	}

	int cnt = 1;
	char * name = new char[20];
	char * position = new char[20];

	cout << "请输入教师姓名:";
	cin >> name;
	cout << "请输入教师职位:";
	cin >> position;
	
	const char * NAME = name;
	const char * POSITION = position;

	for (cnt = 1; ; cnt++)
	{
		sql = sqlite3_mprintf("INSERT INTO TEACHER(No,NAME,POSITION) \
		                   VALUES('%d','%s','%s')", cnt, NAME, POSITION);

		rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
		if (rc != SQLITE_OK)
			continue;
		else
			break;
	}

	sqlite3_close(db);
	return true;

}

bool DBoperate::UpdateTeacher(int n, string column, string newdata)
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;

	rc = sqlite3_open("DataBase.db", &db);
	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return false;
	}

	int len = column.length();
	char *p = new char[len + 1];
	column.copy(p, len, 0);
	*(p + len) = '\0';

	len = newdata.length();
	char *q = new char[len + 1];
	newdata.copy(q, len, 0);
	*(q + len) = '\0';

	const char * COLUMN = p;
	const char * NEWDATA = q;

	sql = sqlite3_mprintf("UPDATE TEACHER set '%s' = '%s' where No = '%d';", COLUMN, NEWDATA, n);

	rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		sqlite3_close(db);
		return false;
	}
	else
	{
		sqlite3_close(db);
		return true;
	}
}

bool DBoperate::TeacherPrint(int n)
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;
	const char* data = "Callback function called";

	rc = sqlite3_open("DataBase.db", &db);
	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return false;
	}

	sql =sqlite3_mprintf("SELECT * FROM TEACHER WHERE No = '%d'", n);

	rc = sqlite3_exec(db, sql, callback, (char*)data, &zErrMsg);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		sqlite3_close(db);
		return false;
	}
	else
	{
		sqlite3_close(db);
		return true;
	}
}

bool DBoperate::DeleteTeacher(int n)
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;

	rc = sqlite3_open("DataBase.db", &db);
	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return false;
	}

	sql = sqlite3_mprintf("DELETE FROM TEACHER WHERE No = '%d'", n);

	rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		sqlite3_close(db);
		return false;
	}
	else
	{
		sqlite3_close(db);
		return true;
	}
}

bool DBoperate::AddStudent()
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;

	rc = sqlite3_open("DataBase.db", &db);
	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return false;
	}

	int cnt = 1;

	char * name = new char[20];
	char * sex = new char[20];
	char * school = new char[20];	//学院
	int majortype;
	char * xlass = new char[20];	//班级


	cout << "请输入学生姓名:";
	cin >> name;
	cout << "请输入学生性别(男性/女性）:";
	cin >> sex;
	cout << "请输入学生所在学院:";
	cin >> school;
	cout << "请输入学生专业类型代号（1-文科 2-理科）:";
	cin >> majortype;
	cout << "请输入学生所在班级:";
	cin >> xlass;

	const char * NAME = name;
	const char * SEX = sex;
	const char * SCHOOL = school;
	const char * CLASS = xlass;

	for (cnt = 1; ; cnt++)
	{
		sql = sqlite3_mprintf("INSERT INTO STUDENT(No,NAME,SEX,SCHOOL,MAJORTYPE,CLASS) \
		                   VALUES('%d','%s','%s','%s','%d','%s')", cnt, NAME, SEX, SCHOOL, majortype, CLASS);

		rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
		if (rc != SQLITE_OK)
			continue;
		else
			break;
	}
	sqlite3_close(db);
	return true;
}

bool DBoperate::UpdateStudent(int n, string column, string newdata)
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;

	rc = sqlite3_open("DataBase.db", &db);
	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return false;
	}

	int len = column.length();
	char *p = new char[len + 1];
	column.copy(p, len, 0);
	*(p + len) = '\0';

	len = newdata.length();
	char *q = new char[len + 1];
	newdata.copy(q, len, 0);
	*(q + len) = '\0';

	const char * COLUMN = p;
	const char * NEWDATA = q;

	sql = sqlite3_mprintf("UPDATE STUDENT set '%s' = '%s' where No = '%d';", COLUMN, NEWDATA, n);

	rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		sqlite3_close(db);
		return false;
	}
	else
	{
		sqlite3_close(db);
		return true;
	}
}

bool DBoperate::StudentPrint(int n)
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;
	const char* data = "Callback function called";

	rc = sqlite3_open("DataBase.db", &db);
	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return false;
	}

	sql = sqlite3_mprintf("SELECT * FROM STUDENT WHERE No = '%d'", n);

	rc = sqlite3_exec(db, sql, callback, (char*)data, &zErrMsg);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		sqlite3_close(db);
		return false;
	}
	else
	{
		sqlite3_close(db);
		return true;
	}
}

bool DBoperate::DeleteStudent(int n)
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;

	rc = sqlite3_open("DataBase.db", &db);
	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return false;
	}

	sql = sqlite3_mprintf("DELETE FROM STUDENT WHERE No = '%d'", n);

	rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		sqlite3_close(db);
		return false;
	}
	else
	{
		sqlite3_close(db);
		return true;
	}
}

bool DBoperate::AddNewClassroom()
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;

	rc = sqlite3_open("DataBase.db", &db);
	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return false;
	}

	int cnt = 1;
	int capacity;
	
	cout << "请输入教室容量:";
	cin >> capacity;

	for (cnt = 1;; cnt++)
	{
		sql = sqlite3_mprintf("INSERT INTO CLASSROOM(No,CAPACITY) \
		                   VALUES('%d','%d')", cnt, capacity);

		rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
		if (rc != SQLITE_OK)
			continue;
		else
			break;
	}

	sqlite3_close(db);
	return true;

}

bool DBoperate::UpdateClassroom(int n, string column, string newdata)
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;

	rc = sqlite3_open("DataBase.db", &db);
	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return false;
	}

	int len = column.length();
	char *p = new char[len + 1];
	column.copy(p, len, 0);
	*(p + len) = '\0';

	len = newdata.length();
	char *q = new char[len + 1];
	newdata.copy(q, len, 0);
	*(q + len) = '\0';

	const char * COLUMN = p;
	const char * NEWDATA = q;

	sql = sqlite3_mprintf("UPDATE CLASSROOM set '%s' = '%s' where No = '%d';", COLUMN, NEWDATA, n);

	rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		sqlite3_close(db);
		return false;
	}
	else
	{
		sqlite3_close(db);
		return true;
	}
}

bool DBoperate::ClassroomPrint(int n)
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;
	const char* data = "Callback function called";

	rc = sqlite3_open("DataBase.db", &db);
	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return false;
	}

	sql = sqlite3_mprintf("SELECT * FROM CLASSROOM WHERE No = '%d'", n);

	rc = sqlite3_exec(db, sql, callback, (char*)data, &zErrMsg);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		sqlite3_close(db);
		return false;
	}
	else
	{
		sqlite3_close(db);
		return true;
	}
}

bool DBoperate::DeleteClassroom(int n)
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;

	rc = sqlite3_open("DataBase.db", &db);
	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return false;
	}

	sql = sqlite3_mprintf("DELETE FROM CLASSROOM WHERE No = '%d'", n);

	rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		sqlite3_close(db);
		return false;
	}
	else
	{
		sqlite3_close(db);
		return true;
	}
}