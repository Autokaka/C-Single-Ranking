//����ԭ�͵��б��ļ���ԭ���� �����������У�main����֮ǰ������ 
#include <iostream>
using namespace std ;

class GradeBook
{
	public ://����ԭ��������ȫ������ 
		GradeBook ( string ) ;

		void setCourseName ( string ) ;
		string getCourseName () ;

		void displayMessage () ;

		void inputGrades () ;
		void displayGradeReport () ; 
		
		int maximum ( int , int , int ) ;
	private ://���ڿ纯����֮�����ݽ���ֵ�Ĵ���� ˽�б��� ����ʵ������һ�� ȫ�ֱ��� ��һ������ֻ�����������ڳ��˱�����֮�⡣���Ⲣ����ȫ�ֱ����ſ���ʵ�ֺ�����֮������ݴ��䣬����int����������return������ֵ���κε��ù���int�����ĺ����塣 
		string courseName ;
		int maximumGrade ;
} ;

