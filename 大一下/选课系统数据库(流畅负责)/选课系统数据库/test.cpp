//���ݿ������Ĳ��Ժ���

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
		cout << "1.�Կγ̵Ĳ���;\n"
			<< "2.�Խ�ʦ�Ĳ���;\n"
			<< "3.��ѧ���Ĳ���;\n"
			<< "4.�Խ��ҵĲ���;\n"
			<< "0.ֹͣ����:";
		cin >> flag;

		switch (flag)
		{
		case 1:
			cout << "\n1.�����¿γ�;\n"
				<< "2.��ѯ�γ�;\n"
				<< "3.��ӡ�γ���Ϣ;\n"
				<< "4.ɾ��ĳ�м�¼;\n"
				<< "5.�޸Ŀγ�����:";
			cin >> a;
			switch (a)
			{
			case 1:
				NJtech.AddSubject();
				break;
				
			case 2:
				cout << "�����������ؼ���:";
				cin >> key1;
				if (!NJtech.SearchSubject(key1))
					cout << "fail";
				break;
			
			case 3:
				cout << "������Ҫ��ӡ�Ŀγ̴���:";
				cin >> key1;
				if (!NJtech.SubjectPrint(key1))
					cout << "fail";
				break;

			case 4:
				cout << "������Ҫɾ���Ŀγ̴���:";
				cin >> key1;
				if (!NJtech.DeleteSubject(key1))
					cout << "fail";
				break;

			case 5:
				cout << "������Ҫ�޸ĵĿγ̴���:";
				cin >> key1;
				cout << "�������޸���Ŀ:";
				cin >> key2;
				cout << "�������޸�����:";
				cin >> key3;
				if (!NJtech.UpdateSubject(key1, key2, key3))
					cout << "fail";
				break;
			}
			break;

		case 2:
			cout << "\n1.�����½�ʦ;\n"
				<< "2.�޸Ľ�ʦ��Ϣ;\n"
				<< "3.��ӡ��ʦ��Ϣ;\n"
				<< "4.ɾ��ĳ�м�¼;\n";
			cin >> a;
			switch (a)
			{
			case 1:
				NJtech.AddTeacher();
				break;

			case 2:
				cout << "������Ҫ�޸ĵĽ�ʦ���:";
				cin >> x;
				cout << "�������޸���Ŀ:";
				cin >> key2;
				cout << "�������޸�����:";
				cin >> key3;
				if (!NJtech.UpdateTeacher(x, key2, key3))
					cout << "fail";
				break;

			case 3:
				cout << "�������ʦ���:";
				cin >> x;
				if (!NJtech.TeacherPrint(x))
					cout << "fail";
				break;

			case 4:
				cout << "�������ʦ���:";
				cin >> x;
				if (!NJtech.DeleteTeacher(x))
					cout << "fail";
				break;
			}
			break;

		case 3:
			cout << "\n1.������ѧ��;\n"
				<< "2.�޸�ѧ����Ϣ;\n"
				<< "3.��ӡѧ����Ϣ;\n"
				<< "4.ɾ��ĳ�м�¼;\n";
			cin >> a;
			switch (a)
			{
			case 1:
				NJtech.AddStudent();
				break;

			case 2:
				cout << "������Ҫ�޸ĵ�ѧ�����:";
				cin >> x;
				cout << "�������޸���Ŀ:";
				cin >> key2;
				cout << "�������޸�����:";
				cin >> key3;
				if (!NJtech.UpdateStudent(x, key2, key3))
					cout << "fail";
				break;

			case 3:
				cout << "������ѧ�����:";
				cin >> x;
				if (!NJtech.StudentPrint(x))
					cout << "fail";
				break;

			case 4:
				cout << "������ѧ�����:";
				cin >> x;
				if (!NJtech.DeleteStudent(x))
					cout << "fail";
				break;
			}
			break;

		case 4:
			cout << "\n1.�����½���;\n"
				<< "2.�޸Ľ�����Ϣ;\n"
				<< "3.��ӡ������Ϣ;\n"
				<< "4.ɾ��ĳ�м�¼;\n";
			cin >> a;
			switch (a)
			{
			case 1:
				NJtech.AddNewClassroom();
				break;

			case 2:
				cout << "������Ҫ�޸ĵĽ��ұ��:";
				cin >> x;
				cout << "�������޸���Ŀ:";
				cin >> key2;
				cout << "�������޸�����:";
				cin >> key3;
				if (!NJtech.UpdateClassroom(x, key2, key3))
					cout << "fail";
				break;

			case 3:
				cout << "��������ұ��:";
				cin >> x;
				if (!NJtech.ClassroomPrint(x))
					cout << "fail";
				break;

			case 4:
				cout << "��������ұ��:";
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