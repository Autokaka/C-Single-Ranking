//ԭ����main����� ������ʵ��ϸ�ڵ�һ���� 
#include <iostream>
#include <iomanip>
using namespace std ;
#include "GradeBook.h"

GradeBook :: GradeBook ( string name )
{
	setCourseName ( name ) ;
	maximumGrade = 0 ;
}

void GradeBook :: setCourseName ( string name ) //name���βΣ����ﲻ��name�����κκ���ı��������ǿ��Եġ��൱�ڸ����������һ�����ڸ��̲�������Ӧ����Ŀռ���ˡ� ��Ҫע�����name����ı仯������ԭ��ֵ�Ļ����ϴ��������ȸ��������ֵ���ڶԸ��Ƶ�ֵ���д��� 
{
	if ( name.length() <= 25 )
	courseName = name ;
	else 
	{
		courseName = name.substr( 0 , 25 ) ;
		cout << "Name \"" << name << "\" exceeds maximum length (25).\n"
		     << "Limiting courseName to first 25 characters.\n" << endl ;
	}
}

string GradeBook :: getCourseName ()
{
	return courseName ;//coureName��˽�е�������ȫ�ֱ����ı������ں���getCourseName()������ 
}

void GradeBook :: displayMessage ()
{
	cout << "Welcome to the grade book for\n" << getCourseName () << "!\n" << endl ;
}

void GradeBook :: inputGrades ()
{
	int grade1 , grade2 , grade3 ;
	
	cout << "Enter 3 integer grades ..." ;
	cin >> grade1 >> grade2 >> grade3 ;
	
	maximumGrade = maximum ( grade1 , grade2 , grade3) ;//maximumGrade��˽��������ȫ�ֱ����ı������ں���displayGradeReport()�����á� 
}

int GradeBook :: maximum ( int x , int y , int z )
{
	int maximumValue = x ;
	
	if ( y > maximumValue )
	maximumValue = y ; 
	
	if ( z > maximumValue )
	maximumValue = z ;
	
	return maximumValue ;
} 

void GradeBook :: displayGradeReport ()
{
	cout << "Maximum of grades entered: " << maximumGrade << endl ;
} 
