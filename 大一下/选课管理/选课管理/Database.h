#ifndef DATABASE_H
#define DATABASE_H
#include <string>
using namespace std;

class Database
{
public:
	Database();

	void addLessonInfo(const char*, int, int, int, int, int, int, int, int);
	void delLessonInfo(int);
	void modLessonInfo(int, const char*);

	void addRoomInfo(int, int);
	void delRoomInfo(int);
	void modRoomInfo(int,const char*);


	void addTeacherInfo(const char*, int);
	void delTeacherInfo(int);
	void modTeacherInfo(int,const char*);


	void addStudentInfo(const char*, int, const char*, const char*, int);
	void delStudentInfo(int);
	void modStudentInfo(int, const char*);

	/*测试接口*/void printDatabase();
	/*测试接口*/void clearDatabase();
private:
	void initDatabase();//1.创建成功; 0.创建失败; -1.已经创建
};

#endif