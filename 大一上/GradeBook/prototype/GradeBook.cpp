//原本是main后面的 函数的实现细节的一览表 
#include <iostream>
#include <iomanip>
using namespace std ;
#include "GradeBook.h"

GradeBook :: GradeBook ( string name )
{
	setCourseName ( name ) ;
	maximumGrade = 0 ;
}

void GradeBook :: setCourseName ( string name ) //name是形参，这里不叫name，叫任何合理的变量名都是可以的。相当于给输入的数据一个用于复刻并进行相应处理的空间罢了。 需要注意的是name本身的变化并不在原数值的基础上处理，而是先复制输入的值，在对复制的值进行处理。 
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
	return courseName ;//coureName是私有的类似于全局变量的变量，在后面getCourseName()被调用 
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
	
	maximumGrade = maximum ( grade1 , grade2 , grade3) ;//maximumGrade是私有类似于全局变量的变量，在后面displayGradeReport()被调用。 
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
