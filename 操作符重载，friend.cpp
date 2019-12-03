#if 1
#include <iostream>
using namespace std;
/*
类包括一下成员时，必须放在初试化列表进行初始化
引用变量成员‘
const成员变量
类类型成员（该类没有默认构造函数）
*/
//class Base
//{
//public:
//	Base(int data1,int data2):_data1(data1),_data2(data2)
//	{}
//private:
//	int _data1;
//	int _data2;
//};
//class Test
//{
//public:
//	Test(int data,int ref) :_ref(ref),_n(data),base(1,2)
//	{
//	}
//private:
//	int& _ref;  //引用
//	const int _n; //const成员变量
//	Base base;//类类型成员
//};
//void main()
//{
//	Test t1(2, 5);
//}
/*
explicit 关键字
构造函数不仅可以构造初试化对象，对于单个参数的构造函数，还具有类型转换的作用
explicit 关键字  限定构造函数只是初试化对象，不能类型转化
*/
//class Test
//{
//public:
//	Test()
//	{}
//	 Test(int data):_mdata(data)
//	{}
//	Test(const Test& d)
//	{
//		cout << "copy" << endl;
//		_mdata = d._mdata;
//	}
//	Test& operator=(const Test & d)
//	{
//		cout << "fuzhi" << endl;
//		if (this != &d)
//		{
//           _mdata = d._mdata;
//		}	
//		return *this;
//	}
//private:
//	int _mdata;
//};
//void main()
//{
//	Test d1;
//	d1 = (Test)2019;   //如果不加explicit,2019会先被转换为Test类型，在调用赋值运算符重载函数
//	Test d2(1);
//	int value = d1;	//不行
//}

/*
static
声明static的类成员称为类的静态成员，用static修饰的成员变量，称为静态成员变量，用static修饰的成员函数，称之为
静态成员函数。静态的成员变量一定要在类外进行初试化
*/



//class Int
//{
//	friend void Print(const Int &x);
//public:
//	Int(int i = 0):m_i(i)
//	{}
//	~Int()
//	{}
//	friend ostream& operator <<(ostream& out, const Int& x);
//public:
//	Int operator+(const Int &x)
//	{
//		int sum = m_i + x.m_i;  //return Int(m_i + x.m_i)  无名临时变量
//		Int tmp(sum);
//		return tmp;
//	}
//	Int operator-(const Int &x)
//	{
//		int sum = m_i -x.m_i;
//		Int tmp(sum);
//		return tmp;
//	}
//	Int operator*(const Int &x)
//		{
//			int sum = m_i * x.m_i;
//			Int tmp(sum);
//			return tmp;
//		}
//	Int operator/(const Int &x)
//	{
//			int sum = m_i / x.m_i;
//			Int tmp(sum);
//			return tmp;
//		}
//	Int operator%(const Int &x)
//	{
//		int sum = m_i % x.m_i;
//		Int tmp(sum);
//		return tmp;
//	}
//public:
//	Int& operator +=(const Int &x)
//	{
//	    m_i = m_i + x.m_i;
//		return *this;
//	}
//	Int& operator -=(const Int &x)
//	{
//		m_i = m_i - x.m_i;
//		return *this;
//	}
//	Int& operator *=(const Int &x)
//	{
//		m_i = m_i * x.m_i;
//		return *this;
//	}
//	Int& operator /=(const Int &x)
//	{
//		m_i = m_i / x.m_i;
//		return *this;
//	}
//	Int& operator %=(const Int &x)
//	{
//		m_i = m_i % x.m_i;
//		return *this;
//	}
////public :
////	Int  operator++()
////	{
////		m_i = m_i +1;
////		return m_i;
////	}
////	Int operator--()
////	{
////		m_i = m_i - 1;
////		return m_i;
////	}
//
//private:
//	int m_i;
//};
//void Print(const Int &x)
//{
//	cout << x.m_i << endl;
//}
//ostream& operator <<(ostream& out, const Int& x)
//{
//	 out<<x.m_i;
//	 return out;
//}
//int main()
//{
//	Int a(8);
//	Int b(4);
//	Int c=a+b;
//	cout << c << endl;
//	Print(c);
//	Int d = a / b;
//	Print(d);
//	a += 2;
//	Print(a);
//	b %= 4;
//	Print(b);
//	cout << b << endl;
//	/*c++;
//	Print(c);
//	c--;
//	Print(c);*/
//}
//class Date
//{
//public:
//	void Display()
//	{
//		cout << "Display ()" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl << endl;
//	}
//	void Display() const
//	{
//		cout << "Display () const" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl << endl;
//	}
//private:
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};
//void Test()
//{
//	Date d1;
//	d1.Display();
//
//	const Date d2;
//	d2.Display();
//}
//void  main()
//{
//}



#endif
