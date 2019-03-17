//������
#include <iostream>
using namespace std;

#ifndef DBOPERATE
#define DBOPERATE

class DBoperate
{
public:
	DBoperate();

	//�γ� ������ ��ѯ
	bool AddSubject();							//���ӿγ̼�¼ ����trueΪ�ɹ�
	bool SearchSubject(string);					//��ѯ�γ̲���� ������Ϣ����Ĳ�ѯ
	bool UpdateSubject(string, string, string);	//�޸Ŀγ�����
	bool SubjectPrint(string);					//��ӡĳ�пγ���Ϣ
	bool DeleteSubject(string);					//ɾ��һ�м�¼
	
	//��ʦ�� �� �༭
	bool AddTeacher();							//��������ʦ
	bool UpdateTeacher(int, string, string);	//�޸���ʦ��Ϣ
	bool TeacherPrint(int);						//��ӡĳ�пν�ʦ��Ϣ
	bool DeleteTeacher(int);					//ɾ��

	//ѧ���� �� �༭
	bool AddStudent();							//������ѧ��
	bool UpdateStudent(int, string, string);	//�޸�ѧ����Ϣ
	bool StudentPrint(int);						//��ӡĳ��ѧ����Ϣ
	bool DeleteStudent(int);

	//���ұ� �� �༭
	bool AddNewClassroom();						//�½�����
	bool UpdateClassroom(int, string, string);	//����ѧϰ�޸�
	bool ClassroomPrint(int);					//��ӡĳ�н�����Ϣ
	bool DeleteClassroom(int);
};

#endif // !DBOPERATE
