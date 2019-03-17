//操作类
#include <iostream>
using namespace std;

#ifndef DBOPERATE
#define DBOPERATE

class DBoperate
{
public:
	DBoperate();

	//课程 的增加 查询
	bool AddSubject();							//增加课程记录 返回true为成功
	bool SearchSubject(string);					//查询课程并输出 五种信息种类的查询
	bool UpdateSubject(string, string, string);	//修改课程数据
	bool SubjectPrint(string);					//打印某行课程信息
	bool DeleteSubject(string);					//删除一行记录
	
	//教师表 的 编辑
	bool AddTeacher();							//增加新老师
	bool UpdateTeacher(int, string, string);	//修改老师信息
	bool TeacherPrint(int);						//打印某行课教师信息
	bool DeleteTeacher(int);					//删除

	//学生表 的 编辑
	bool AddStudent();							//增加新学生
	bool UpdateStudent(int, string, string);	//修改学生信息
	bool StudentPrint(int);						//打印某行学生信息
	bool DeleteStudent(int);

	//教室表 的 编辑
	bool AddNewClassroom();						//新建教室
	bool UpdateClassroom(int, string, string);	//教室学习修改
	bool ClassroomPrint(int);					//打印某行教室信息
	bool DeleteClassroom(int);
};

#endif // !DBOPERATE
