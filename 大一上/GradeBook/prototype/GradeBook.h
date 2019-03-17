//函数原型的列表文件，原本是 在声明过程中，main函数之前被调用 
#include <iostream>
using namespace std ;

class GradeBook
{
	public ://函数原型声明的全部内容 
		GradeBook ( string ) ;

		void setCourseName ( string ) ;
		string getCourseName () ;

		void displayMessage () ;

		void inputGrades () ;
		void displayGradeReport () ; 
		
		int maximum ( int , int , int ) ;
	private ://用于跨函数体之间数据进行值的传输的 私有变量 ，其实跟定义一个 全局变量 是一个道理，只不过不能用在除了本程序之外。另外并不是全局变量才可以实现函数体之间的数据传输，比如int函数可以用return返回数值给任何调用过该int函数的函数体。 
		string courseName ;
		int maximumGrade ;
} ;

