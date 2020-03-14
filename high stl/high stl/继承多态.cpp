#if 0
#include<iostream>
#include<string>
using namespace std;

class Base
{
public:
	int m_base;
};
class A :  public Base
{
public:
	int m_a;
};
class B : public Base
{
public:
	int m_b;
};
class D : public A, public B
{
public:
	int m_d;
};
void main()
{
	D d;
	d.m_d = 0;
	d.m_a = 1;
	d.m_b = 2;
	//d.m_base = 3;
	d.A::m_base = 3;
	d.B::m_base = 4;
}


//class student;
//class person
//{
//public:
//	friend void Display(const person&p, const student& s);
//	void Showcount()
//	{
//		cout << _count << endl;
//	}
//public:
//	person(const char* name = "peter") :_name(name)
//	{
//		++_count;
//		cout << "person((const char* )" << endl;
//	}
//	person(const person& p) :_name(p._name)
//	{
//		cout << "person(const person& p)" << endl;
//	}
//	person& operator=(const person& p)
//	{
//		cout << "person operator=(const person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//			return *this;
//	}
//	~person()
//	{
//		cout << "~person" << endl;
//	}
//protected:
//	string _name;
//	static int _count;
//};
//int person::_count = 0;//静态变量类外初始化
//class student :public person
//{
//public:
//	friend void Display(const person&p, const student& s);
//public:
//	student(int num):person("duzhiqiang"),_num(num)
//	{
//		cout << "student()" << endl;
//	}
//	student(const student& s):person(s), _num(s._num)
//	{
//		cout << "student(const student& s)" << endl;
//	}
//	student& operator=(const student& s)
//	{
//		cout<<"student& operator=(const student& s)"<<endl;
//		if (this != &s)
//		{
//			person::operator=(s);
//			_num = s._num;
//		}
//		return *this;
//	}
//	~student()
//	{
//		cout << "~student()" << endl;
//	}
//
//protected:    
//	int _num;
//};
//void Display(const person&p, const student& s)
//{
//	cout << p._name << endl;
//	cout << s._num << endl;
//}
//void main()
//{
//	student s1( 18);
//	s1.Showcount();
//	person(p1);
//	p1.Showcount();
//	//Display(p1,s1);
//	//student s2(s1);
//	/*student s3(s1);
//	s3 = s1;*/
//	
//}
//class person {
//public:    
//void print(int)
//{ 
//	cout << "base of print" << endl;
//}
//protected:  
//	string _name = "peter"; // 姓名 
//	int _age = 18;  // 年龄 
//};
//
//class student :public person
//{
//public:
//	void print()
//	{
//		cout << "person of print" << endl;
//	}
//protected:
//	int _stuid;
//};
//class Teacher :public person
//{
//protected:
//	int  _jobid;
//};
////派生类成员在继承基类时会同名隐藏
//
//void main()
//{
//	student s;
//	s.person::print(1);//只要名字一样，就会同名隐藏，而不管参数是啥
//}
//int main()
//{
//	student s;
//	Teacher t;
//	Teacher t2;
//	s.print();
//	t.print();
//	person p;
//	//派生类可以给基类赋值/指针/引用
//	p = t;
//	person *p1=&t2;
//	person& p2 = s;
//	//基类的对象不能给派生类赋值
//	//student s2 = p;
//	//基类的指针可以强制类型转换赋值给派生类 ,但会越界访问
//	student *s3 = (student*) p1;
//
//}




#endif