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
1、静态成员为所有类对象所共享，不属于某个具体的实例
2、静态成员变量必须在类外定义，定义时不添加static关键字
3、类静态变量即可用类名：：静态成员或对象，静态成员来访问
4、静态成员函数没有隐藏的this指针，不能访问任何非静态成员
5、静态成员和类的普通成员一样，有public,protected,private 3种访问级别，也可以具有返回值
*/

//class A
//{
//public:
//	A() { ++_scount; }
//	A(const A& t) { ++_scount; }
//	static int GetAcount()
//	{
//		return _scount;
//	}
//private:
//	static int _scount;
//};
//int A::_scount = 0;
//
//void TestA()
//{
//	cout << A::GetAcount() << endl;
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetAcount() << endl;
//}
//class Test
//{
//	//friend ostream& operator << (ostream &out, const Test &t);
//public:
//	void fun()
//	{
//		GetUseCount();
//	}
//	static int GetUseCount()  //静态方法没有this指针
//	{
//		return m_conut++;
//	}
//private:
//	int m_data;
//	static int m_conut;
//};
//int Test::m_conut = 0;
//void main()
//{
//	cout << Test::GetUseCount() << endl;
//	Test t1;
//	Test t2;
//	cout << Test::GetUseCount() << endl;
//	{
//		Test t3;
//		cout << Test::GetUseCount() << endl;
//	}
//	cout << t1.GetUseCount() << endl;
//}

//友元函数友元类
//
//class Data
//{
//public:
//	Data(int year,int month,int day):_year(year),_month(month),_day(day)
//	{}
//	ostream& operator << (ostream& _cout)
//	{
//		_cout << _year << " " << _month << " " << _day;
//		return _cout;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Data d(2017, 12, 24);
//	d << cout;   //若没有定义友元则必须反着写
//	return 0;
//}
//友元函数输入流输出流友元函数（也可以重载，但重载会出现问题，无法控制参数的顺序，this指针和输出流对象抢占位置，需要
//输出流对象在第一个位置，但实际上this指针在第一个位置，所以输出的时候和平时相反）
//class Data
//{
//	friend ostream &operator << (ostream & _cout, const Data& d);
//	friend istream& operator >> (istream & _cin, Data& d); //d不能加const,加const就不能改变d了
//public:
//	Data (int year,int month,int day):_year(year),_month(month),_day(day)
//	{}
//	Data()
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& _cout, const Data& d)
//{
//	_cout << d._year <<"-" << d._month << "-"  << d._day;
//	return _cout;
//}
//istream& operator >> (istream & _cin,  Data& d)
//{
//	_cin >> d._year;
//	_cin >> d._month;
//	_cin >> d._day;
//	return _cin;
//}
//
//int main()
//{
//	Data d;
//	cin >> d;
//	cout << d << endl;
//	return 0;
//}
//一个函数可以是多个类的友元函数
/*
友元类:
友元类的所有成员函数都可以是另一个类的友元函数，都可以返回另一个类的非公有成员

*/
//class Data;//前置声明
//class Time
//{
//	friend ostream& operator <<( ostream&_cout, const Time& t);
//	friend class Data;  //声明日期类是时间类的友元类，则日期类可以访问时间类time的私有成员
//public:
//	Time()
//	{}
//	Time(int hour,int minute,int second): _hour(hour),_minute(minute),_second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Data
//{
//	friend ostream& operator <<( ostream&_cout, const Data& d);
//public:
//	Data(int year = 1900, int month = 1, int day = 1) : _year(year), _month(month), _day(day)
//	{}
//	void SetTimeOfDate(int hour, int minute, int second)
//
//	{
//		// 直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//ostream& operator <<( ostream&_cout, const Data& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day ;
//	return _cout;
//}
//ostream& operator <<(ostream&_cout, const Time& t)
//{
//	_cout << t._hour << "-" << t._minute << "-" << t._minute;
//	return _cout;
//
//}
//int main()
//{
//	Data d1(2019, 12, 9);
//	d1.SetTimeOfDate(16, 34, 30);
//	cout << d1;
//	return 0;
//}

/*内部类
如果一个类定义在另一个类的内部，这个类就叫做内部类，注意这个内部类是一个独立的类，不属于外部类，更不能通过外部类的
的对象去调用内部类，外部类对内部类没有访问权限
内部类是外部类的友元类，内部类可以访问外部类，但外部类不能访问内部类
*/
//class A
//{
//public:
//	A(int th):h(th)
//	{
//		count++;
//	}
//	class B
//	{
//	public:
//		B() 
//		{
//			count++;
//		}
//		void foo(const A& a)
//		{
//			cout << count << endl;
//			cout << a.h << endl;
//		}
//	};
//private:
//	static int count;
//	int h;
//};
//int A::count = 0;  //内部类可以直接访问外部类的static成员  
//
//int main()
//{
//	A::B b;
//	A t(5);   //定义类定义了两次，所以count=2
//	b.foo(t);
//	return 0;
//}
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
//public :
//	Int & operator++()  //++i
//	{
//		m_i ++;
//		return *this;
//	}
//	Int & operator++(int)  //i++   (int)只是一个伪参数，是为了区分++i i++
//	{
//		Int tmp(*this);
//		++*this;//  *this++ 不行 表达式必须是可修改的左值
//		return tmp;
//	}
//	Int & operator--()  //++i
//	{
//		--m_i;
//		return *this;
//	}
//	Int & operator--(int)  //i++
//	{
//		Int tmp(*this);
//		--*this;//  *this++ 不行 表达式必须是可修改的左值
//		return tmp;
//	}
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
//	cout << "a=" << a << endl;
//	a++;
//	cout << "a++=" << a << endl;
//	++a;
//	cout << "++a=" << a << endl;
//	a--;
//	cout << "a--=" << a << endl;
//	--a;
//	cout << "--a=" << a << endl;
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
