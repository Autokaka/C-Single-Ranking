#include <iostream> 
#include "Database.h"

using namespace std;

int main() 
{
	Database test;
	char exit;
	cout << " * 清空数据库吗？（y/n）：  ";
	cin >> exit;
	if (exit == 'y')
		test.clearDatabase();

	while (1)
	{
		cout << "\n * 即将列出当前所有数据库，"; system("pause");
		test.printDatabase();
		cout << "\n * 进入数据库添加模式，"; system("pause");
		cout << "\n * (0.退出该模式; 1.LessonInfo; 2.RoomInfo; 3.TeacherInfo; 4.StudentInfo)...你的选择是：  ";
		int choice;
		cin >> choice;
		if (choice == 0)
			break;
		switch (choice)
		{
		case 1:
		{
			char Name[100];
			int a, b, c, d, e, f, g, h;
			cout << "\n * 按顺序(课程名称>>课程性质(1.必修课 0.选修课)>>总学时>>理论学时>>实验或上机学时>>学分>>开课专业(1.文科 2.理科 0.文理兼修)>>开课学期>>课程容量)输入增加的信息：";
			cin >> Name >> a >> b >> c >> d >> e >> f >> g >> h;
			test.addLessonInfo(Name, a, b, c, d, e, f, g, h);
		}
		break;
		case 2:
		{
			int a, b;
			cout << "\n * 按顺序(班级号码>>班级容量)输入增加的信息：";
			cin >> a >> b;
			test.addRoomInfo(a, b);
		}
		break;
		case 3:
		{
			char Name[100];
			int a;
			cout << "\n * 按顺序(教师姓名>>教师职称)输入增加的信息：";
			cin >> Name >> a;
			test.addTeacherInfo(Name, a);
		}
		break;
		case 4:
		{
			char Institute[100];
			char Name[100];
			char Sex[100];
			int a, b, c, d, e, f, g, h;
			cout << "\n * 按顺序(学院名>>班级>>姓名>>性别>>专业(1.文科 2.理科 0.文理兼修))输入增加的信息：";
			cin >> Name >> a >> b;
			test.addStudentInfo(Institute, a, Name, Sex, b);
		}
		break;
		}
		
	}
	
	cout << " * 测试程序结束，"; system("pause");
	return 0;
}