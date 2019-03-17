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


	//���� �γ� ��
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
	type  1-����  2-ѡ��  3-����  4Ӣ��
	openmajor  1-�Ŀ� 2-��� 0����
	capacity ��Ϊ-1��ʾΪ���޿����ޱ�����
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


	//���� ��ʦ ��
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


	//���� ѧ�� ��
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


	//���� ���� ��
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
	int openmajor;				//����רҵ 1-�Ŀ� 2-��� 0�������
	char * openterm = new char[20];
	int credit;
	int credithour;
	int capacity = 0;
	int time;
	int classroom;

	cout << "������γ̱���ţ�����GS001 ��ʾ ��001����ʦ���ڵĸ����Σ�:";
	cin >> code;
	cout << "������γ�����:";
	cin >> name;
	cout << "�������ڿν�ʦ���:";
	cin >> teacher;
	cout << "������γ����ʱ�ţ�1-����  2-ѡ��  3-����  4-Ӣ�:";
	cin >> type;
	cout << "�����뿪��רҵ���ţ�1-�Ŀ� 2-��� 0���ޣ�:";
	cin >> openmajor;
	cout << "�����뿪��ѧ��:";
	cin >> openterm;
	cout << "������ÿ�ѧ��:";
	cin >> credit;
	if (type != 1)
	{
		cout << "������ѡ�޿�����:";
		cin >> capacity;
	}
	else capacity = -1;
	cout << "�������Ͽ�ʱ��(��һ����λ����ʾ��11��ʾ��һ��һ�ڿΣ�54��ʾ������Ľڿ�):";
	cin >> time;
	cout << "�������Ͽν��ұ��:";
	cin >> classroom;

	const char * CODE = code;
	const char * NAME = name;
	const char * TEACHER = teacher;
	const char * OPENTERM = openterm;
	
	credithour = 16 * credit;

	//�ж�ʱ������Ƿ�ͬʱ��ͻ
	for (cnt = 1;; cnt++)
	{
		sql = sqlite3_mprintf("SELECT * FROM SUBJECT WHERE TIME = '%d' AND CLASSROOM = '%d'", \
		                       time, teacher);
		if (rc = SQLITE_OK)
			flag++;
	}

	if (flag > 0)
	{
		cout << "��ʱ�ν����ѱ�ռ�ã�¼��γ�ʧ�ܡ�";
		return false;
	}

	//��ʱ����Ҳ���ͻ�����ڱ�����Ӽ�¼��
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

	cout << "�������ʦ����:";
	cin >> name;
	cout << "�������ʦְλ:";
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
	char * school = new char[20];	//ѧԺ
	int majortype;
	char * xlass = new char[20];	//�༶


	cout << "������ѧ������:";
	cin >> name;
	cout << "������ѧ���Ա�(����/Ů�ԣ�:";
	cin >> sex;
	cout << "������ѧ������ѧԺ:";
	cin >> school;
	cout << "������ѧ��רҵ���ʹ��ţ�1-�Ŀ� 2-��ƣ�:";
	cin >> majortype;
	cout << "������ѧ�����ڰ༶:";
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
	
	cout << "�������������:";
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