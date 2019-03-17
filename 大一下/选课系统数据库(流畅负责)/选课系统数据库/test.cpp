//数据库操作类的测试函数

#include <iostream>
#include <string>
using namespace std;

#include "DBoperate.h"

int main()
{
	DBoperate NJtech;
	
	int flag = 1;
	int a;
	string key1;
	string key2;
	string key3;
	int x;

	while (flag)
	{
		cout << "1.对课程的操作;\n"
			<< "2.对教师的操作;\n"
			<< "3.对学生的操作;\n"
			<< "4.对教室的操作;\n"
			<< "0.停止操作:";
		cin >> flag;

		switch (flag)
		{
		case 1:
			cout << "\n1.增加新课程;\n"
				<< "2.查询课程;\n"
				<< "3.打印课程信息;\n"
				<< "4.删除某行记录;\n"
				<< "5.修改课程数据:";
			cin >> a;
			switch (a)
			{
			case 1:
				NJtech.AddSubject();
				break;
				
			case 2:
				cout << "请输入搜索关键词:";
				cin >> key1;
				if (!NJtech.SearchSubject(key1))
					cout << "fail";
				break;
			
			case 3:
				cout << "请输入要打印的课程代码:";
				cin >> key1;
				if (!NJtech.SubjectPrint(key1))
					cout << "fail";
				break;

			case 4:
				cout << "请输入要删除的课程代码:";
				cin >> key1;
				if (!NJtech.DeleteSubject(key1))
					cout << "fail";
				break;

			case 5:
				cout << "请输入要修改的课程代码:";
				cin >> key1;
				cout << "请输入修改栏目:";
				cin >> key2;
				cout << "请输入修改内容:";
				cin >> key3;
				if (!NJtech.UpdateSubject(key1, key2, key3))
					cout << "fail";
				break;
			}
			break;

		case 2:
			cout << "\n1.增加新教师;\n"
				<< "2.修改教师信息;\n"
				<< "3.打印教师信息;\n"
				<< "4.删除某行记录;\n";
			cin >> a;
			switch (a)
			{
			case 1:
				NJtech.AddTeacher();
				break;

			case 2:
				cout << "请输入要修改的教师编号:";
				cin >> x;
				cout << "请输入修改栏目:";
				cin >> key2;
				cout << "请输入修改内容:";
				cin >> key3;
				if (!NJtech.UpdateTeacher(x, key2, key3))
					cout << "fail";
				break;

			case 3:
				cout << "请输入教师编号:";
				cin >> x;
				if (!NJtech.TeacherPrint(x))
					cout << "fail";
				break;

			case 4:
				cout << "请输入教师编号:";
				cin >> x;
				if (!NJtech.DeleteTeacher(x))
					cout << "fail";
				break;
			}
			break;

		case 3:
			cout << "\n1.增加新学生;\n"
				<< "2.修改学生信息;\n"
				<< "3.打印学生信息;\n"
				<< "4.删除某行记录;\n";
			cin >> a;
			switch (a)
			{
			case 1:
				NJtech.AddStudent();
				break;

			case 2:
				cout << "请输入要修改的学生编号:";
				cin >> x;
				cout << "请输入修改栏目:";
				cin >> key2;
				cout << "请输入修改内容:";
				cin >> key3;
				if (!NJtech.UpdateStudent(x, key2, key3))
					cout << "fail";
				break;

			case 3:
				cout << "请输入学生编号:";
				cin >> x;
				if (!NJtech.StudentPrint(x))
					cout << "fail";
				break;

			case 4:
				cout << "请输入学生编号:";
				cin >> x;
				if (!NJtech.DeleteStudent(x))
					cout << "fail";
				break;
			}
			break;

		case 4:
			cout << "\n1.增加新教室;\n"
				<< "2.修改教室信息;\n"
				<< "3.打印教室信息;\n"
				<< "4.删除某行记录;\n";
			cin >> a;
			switch (a)
			{
			case 1:
				NJtech.AddNewClassroom();
				break;

			case 2:
				cout << "请输入要修改的教室编号:";
				cin >> x;
				cout << "请输入修改栏目:";
				cin >> key2;
				cout << "请输入修改内容:";
				cin >> key3;
				if (!NJtech.UpdateClassroom(x, key2, key3))
					cout << "fail";
				break;

			case 3:
				cout << "请输入教室编号:";
				cin >> x;
				if (!NJtech.ClassroomPrint(x))
					cout << "fail";
				break;

			case 4:
				cout << "请输入教室编号:";
				cin >> x;
				if (!NJtech.DeleteClassroom(x))
					cout << "fail";
				break;
			}
			break;

		case 0:
			break;
		}

	}

	system("pause");
}