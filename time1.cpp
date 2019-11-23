#include<iostream>
using namespace std;  //命名空间
//namespace N1
//{
//	int a=9;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	namespace N2
//	{
//		int MUL(int left, double right)  //命名空间可以嵌套
//		{
//			return left * right;
//		}
//	}
//}
//using namespace N1;
//using namespace N1::N2;
//int Add(int a, int b)//缺省参数(提前定义参数)必须从右到左给出
//{
//	return a + b;
//}
//int Add(int c,int a , int b )
//{
//	return c+a + b;
//}
//char Add(char c, char a)
//{
//	return c + a ;
//}
//int main()
//{
//	int a;   //c++在定义变量时必须赋值
//	double b;
//	/*cout << a << endl;
//	cout << a << endl;*/
//	cout << Add(5,6) << endl;
//	cout << Add(10,20,30) << endl;
//	cout << Add('A','B') << endl;
//}
//函数重载：是函数的一种特殊情况，c++允许在同一作用域中声明几个功能类似的同名函数，要求是这些同名函数的形参列表
//（参数个数或类型或顺序）必须不同
//返回值为什么不能作为重载的一个条件
//编译器在编译时，不会去判断函数的返回类型(意思是编译的时候函数名是同名的）
//也就是在编译的时候会根据函数名和形参重命名，与返回值无关，保证其名字的唯一性，保证link时不会多重定义。
/*  VS2017 下 编译过程编辑器会把重载函数进行重命名（c会命名为——   _MAX，名字都相同，所以无法重载）
例如  int MAX (int a,int b)  --> (?MAX@@YAHHH@Z)  int代表H
char MAX (char a,char b)  --> (?MAX@@YADDD@Z)    char代表D
 double MAX (double a,double b)  --> (?MAX@@YANNN@Z)  double代表N
 如果只是返回值不同，参数列表相同的话函数会被编译为相同的名字
*/
// 引用   是给已存在的变量取一个别名，不会为引用变量开辟空间，和引用变量公用一块空间
void main()
{
	int a = 10;
	int& ra = a;
	cout << "&a=" << &a << endl << "&ra=" << &ra << endl; //引用类型必须和引用实体是同种类型
	int* p = &a;
	int*& q = p;
	cout << "p=" << p << endl;
	cout<< "q=" << q << endl;

}
//1、引用在定义时必须初始化 2、一个变量可以有多个引用 3、引用一旦引用一个实体，再不能引用其他实体
//4.指针和引用的区别总结
//指针有自己的一块空间，而引用只是一个别名；
//使用sizeof看一个指针的大小是4，而引用则是被引用对象的大小；
//指针可以被初始化为NULL，而引用必须被初始化且必须是一个已有对象的引用；
//作为参数传递时，指针需要被解引用才可以对对象进行操作，而直接对引用的修改都会改变引用所指向的对象；
//可以有const指针，但是没有const引用；
//指针在使用中可以指向其它对象，但是引用只能是一个对象的引用，不能被改变；
//指针可以有多级指针（**p），而引用至于一级；
//指针和引用使用++运算符的意义不一样；
//如果返回动态内存分配的对象或者内存，必须使用指针，引用可能引起内存泄露(引用后内存不能修改)



