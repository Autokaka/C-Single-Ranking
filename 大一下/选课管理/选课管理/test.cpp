#include <iostream> 
#include "Database.h"

using namespace std;

int main() 
{
	Database test;
	char exit;
	cout << " * ������ݿ��𣿣�y/n����  ";
	cin >> exit;
	if (exit == 'y')
		test.clearDatabase();

	while (1)
	{
		cout << "\n * �����г���ǰ�������ݿ⣬"; system("pause");
		test.printDatabase();
		cout << "\n * �������ݿ����ģʽ��"; system("pause");
		cout << "\n * (0.�˳���ģʽ; 1.LessonInfo; 2.RoomInfo; 3.TeacherInfo; 4.StudentInfo)...���ѡ���ǣ�  ";
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
			cout << "\n * ��˳��(�γ�����>>�γ�����(1.���޿� 0.ѡ�޿�)>>��ѧʱ>>����ѧʱ>>ʵ����ϻ�ѧʱ>>ѧ��>>����רҵ(1.�Ŀ� 2.��� 0.�������)>>����ѧ��>>�γ�����)�������ӵ���Ϣ��";
			cin >> Name >> a >> b >> c >> d >> e >> f >> g >> h;
			test.addLessonInfo(Name, a, b, c, d, e, f, g, h);
		}
		break;
		case 2:
		{
			int a, b;
			cout << "\n * ��˳��(�༶����>>�༶����)�������ӵ���Ϣ��";
			cin >> a >> b;
			test.addRoomInfo(a, b);
		}
		break;
		case 3:
		{
			char Name[100];
			int a;
			cout << "\n * ��˳��(��ʦ����>>��ʦְ��)�������ӵ���Ϣ��";
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
			cout << "\n * ��˳��(ѧԺ��>>�༶>>����>>�Ա�>>רҵ(1.�Ŀ� 2.��� 0.�������))�������ӵ���Ϣ��";
			cin >> Name >> a >> b;
			test.addStudentInfo(Institute, a, Name, Sex, b);
		}
		break;
		}
		
	}
	
	cout << " * ���Գ��������"; system("pause");
	return 0;
}