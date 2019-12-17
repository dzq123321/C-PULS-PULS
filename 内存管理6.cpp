#if 1
#include<iostream>
#include<assert.h>
using namespace std;
/**
设计一个类，该类只能生成一个实例 类似于只能在堆上创建
将类的构造，拷贝构造私有或保护 定义一个静态的类类型生成方法
唯一要加的一点是将类的私有成员定义为静态成员（静态指针成员）
*/
class Singobj
{
public:
	static Singobj* SingobjCreate()
	{
		if (pSingobj == nullptr)
		{
			pSingobj = new Singobj;
		}
		return pSingobj;
	}
private:
	Singobj()
	{}
	Singobj(const Singobj& t)
	{
		_mdata = t._mdata;
	}
	static Singobj* pSingobj;
	static int  _mdata;
};
int Singobj::_mdata = 1;
Singobj* Singobj::pSingobj = nullptr;
void main()
{
	Singobj *p1 = Singobj::SingobjCreate();
	Singobj *p2 = Singobj::SingobjCreate();
}

/*设计一个类，只能

在栈上开辟空间  
1、将类的构造函数，拷贝构造声明，公有
2、即把new屏蔽 设置为保护或私有 只需屏蔽operator new 就相当于屏蔽了palcement new
通过new实现在堆上创建
*/
//class ObjectByStact
//{
//public:
//	ObjectByStact()
//	{}
//	ObjectByStact(const ObjectByStact& t)
//	{
//		_data = t._data;
//	}
//protected:
//	void * operator new(size_t sz)
//	{
//		void *p = malloc(sz);
//	 }
//	void operator delete(void *p)
//	{
//		free(p);
//	 }
//private:
//	int _data;
//};

/*设计一个类，只能在堆上开辟空间
1、将类的构造函数私有，拷贝构造声明私有，防止别人调用拷贝在栈上生成对象
2、提供一个静态的成员函数，在该静态的成员函数中完成堆对象的创建
通过new实现在堆上创建
*/
//class ObjectByHeap
//{
//public:
//	static ObjectByHeap* CreateObject()
//	{
//		return new ObjectByHeap;
//	}
//private:
//	ObjectByHeap()
//	{}
//	ObjectByHeap(const ObjectByHeap& t)
//	{
//		_data = t._data;
//	}
//	int _data;
//};
//void main()
//{
//	ObjectByHeap* p1=ObjectByHeap::CreateObject();
//	ObjectByHeap* p2 = ObjectByHeap::CreateObject();
//}

//c++ new开辟空间失败会抛异常 malloc 会返回null
//void handle_out_of_memory()
//{
//	cout << " out of Memory." << endl;
//	exit(1);
//}
//int main()
//{
//	set_new_handler(handle_out_of_memory);
//	/* 当new申请不成功时，如果没有设置set_new_handler 直接抛异常 bad_alloc
//	如果设置了set_new_handler  则执行设置的函数*/
//	int *p = new int[536870911];
//	cout << "OK " << endl;         
//}


/*
一    、new operator 
1、开辟空间   2、调用构造函数        
delete operator   
1、调用析构函数   2、释放空间
new在申请空间失败后会抛出异常  而malloc会返回null
二、      operator  new   只负责开辟空间   相当于malloc  当operator时，也就必须operator delete 
操作符new存在的必要性：  当构造和析构是深拷贝深析构时(字符串)，有必要使用operator new
 三、 palcement new 定位new  
 是在已分配的的原始空间中调用构造函数初始化一个对象
 */
//class Test
//{
//	friend ostream & operator <<(ostream& out, const Test& t);
//public:
//	Test():_data(0)
//	{
//		cout << "Test()" << this << endl;
//	}
//	Test(int data)
//	{
//		_data = data;
//		cout << "Test(int data)" << this << endl;
//	}
//	~Test()
//	{
//		cout << "~Test()" << this << endl;
//	}
//private:
//	int _data;
//};
//ostream & operator <<(ostream& out, const Test& t)
//{
//	out << t._data;
//	return out;
//}
//void* operator new(size_t sz, int *ptr, int pos) //new 会自动计算参数大小，所以传参的时候不用传大小
//{
//	return &ptr[pos];   //定位new
//}
//void main()
//{
//	Test* pt = (Test*)malloc(sizeof(Test));
//	new(pt) Test;
//	cout << pt << endl;
//	cout << *pt << endl;
//	new(pt) Test(5);
//	cout << pt << endl;
//	cout << *pt << endl;
//	int ar[10] = { 0 };
//	new(ar) int(1);
//	new(ar) int(2);  //默认只初始化ar[0]的位置
//	new(ar,1) int(2);
//}
//class String
//{
//public:
//	String(const char* str = "")
//	{
//		mstr = new char[strlen(str) + 1];
//		strcpy(mstr, str);
//		cout << "1111" << endl;
//	}
//	~String()
//	{
//		if (nullptr != mstr)
//		{
//			delete[] mstr;
//			mstr = nullptr;
//		}
//	}
//	String(const String& str)
//	{
//		if (str.mstr)
//		{
//			mstr = new char[strlen(str.mstr) + 1];
//			strcpy(mstr, str.mstr);
//			cout << "1111" << endl;
//		}
//
//	}
//	String& operator =(const String& str)  //接受引用，返回引用
//	{
//		if (this != &str)   //自我赋值检测
//		{
//			delete[] mstr;   //删除原有空间
//			mstr = new char[strlen(str.mstr) + 1];   //开辟空间并重新赋值
//			strcpy(mstr, str.mstr);
//			cout << "222" << endl;
//		}
//		return *this;    //返回当前对象
//	}
//private:
//	char *mstr;
//};
//void* operator new(size_t sz)
//{
//	void *p = malloc(sz);
//	cout << "operator new" << endl;
//	return p;
//}
//void operator delete(void *p)
//{
//	free(p);
//	p = nullptr;
//	cout << "operator delete" << endl;
//}
//void main()
//{
//	String s1("hello");
//	String s2(s1);
//	String s3("world");
//	s2 = s3;
//}
//class Test
//{
//public:
//	Test(int data = 0) : m_data(data)
//	{
//		cout << "create Test object: " << this << endl;
//	}
//	Test(const Test &t)
//	{
//		cout << "copy create Test object: " << this << endl;
//	}
//	~Test()
//	{
//		cout << "destory Test object" << endl;
//	}
//private:
//	int m_data;
//};
//void* operator new(size_t(sz))//操作符重载 操作符new
//{                             //就近原则，若将operator new 放在类中，系统优先调用类中的操作符new
//	cout << "1111" << endl;
//	void *p = malloc(sz);
//	return p;
//}
//void operator delete(void *p)
//{
//	cout << "2222" << endl;
//	free(p);
//}void* operator new[](size_t(sz))//操作符重载 操作符new[]
//{                             //
//	cout << "3333" << endl;
//	void *p = malloc(sz);
//  assert(p != nullptr);
//	return p;
//}
//void operator delete[](void *p)
//{
//	cout << "4444" << endl;
//	free(p);
//}
//void main()
//{
//	Test *p1 = new Test(5);   //重载后相当于malloc，无法调用析构函数
//	delete p1; //重载后相当于free，无法调用析构函数
//	Test *p2 = new Test[5];  //sz=24 大小为24   4*5 + 4(cookie信息 一个作用是可以记录申请数组的大小)
//	delete[] p2;
// }
//new operator

//class Test
//{
//public:
//	Test(int data = 0) : m_data(data)
//	{
//		cout << "create Test object: " << this << endl;
//	}
//	Test(const Test &t)
//	{
//		cout << "copy create Test object: " << this << endl;
//	}
//	Test& operator=(const Test &t)
//	{
//		cout << "Assign " << this << "=" << &t << endl;
//		if (this != &t)
//		{
//			m_data = t.m_data;
//		}
//		return *this;
//	}
//	~Test()
//	{
//		cout << "Free Test object: " << this << endl;
//	}
//public:
//	int GetData()const
//	{
//		return m_data;
//	}
//private:
//	int m_data;
//};
//void * operator new(size_t sz)   //operator new 和operator delete用法
//{
//	void *p = malloc(sz);
//	return p;
//}
//void operator delete(void* p)
//{
//	free(p);
//}
//void main()
//{
//	Test* p = new Test[10];
//	cout << sizeof(Test) << endl;
//	cout << sizeof(p) << endl;
//	cout << sizeof(*p) << endl;
//	delete[] p;
//}

//c++的内存管理   new delete
//class Test
//{
//public:
//	Test() : _data(0)
//	{
//		cout << "Test()" << endl;
//	}
//	~Test()
//	{
//		cout << "~Test()" << endl;
//	}
//private:
//	int _data;
//};
////在申请自定义类型的空间时，new会调用构造函数，delete会调用析构函数，而malloc和free不会
//int main()
//{
//	Test* ptr1 = (Test*)malloc(sizeof(Test));
//	Test* ptr2 = (Test*)malloc(sizeof(Test)*10);
//	free(ptr1);
//	free(ptr2);
//	Test* ptr3 = new Test;
//	delete(ptr3);
//	Test* ptr4 = new Test[10];
//	delete[] ptr4;
//}
//int main()
//{
	//int *ptr1 = new int;
	//int *ptr2 = new int(5);//开辟一个int大小的空间并初始化为3
	//int *ptr3 = new int[3];//开辟3个int类型的空间	
	//delete ptr1;
	//delete ptr2;
	//delete[] ptr3;
//}


//void main()
//{
//	char ch2[7] = "abcdef";
//	cout << "sizeof(ch2)=" << sizeof(ch2) << endl;  //5 有\0
//	cout << "strlen(ch2)=" << strlen(ch2) << endl;   //4
//	int* p1 = (int*)malloc(sizeof(int) * 20);
//	cout << sizeof(p1) << endl;
//	cout << sizeof(*p1) << endl;
//}


//class Date
//{
//	friend ostream& operator <<(ostream& _cout, const Date& d);
//public:
//	Date(int year = 1900, int month = 1, int day = 1): _year(year), _month(month), _day(day)
//	{}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//	Date operator+(int days);
//	Date operator-(int days);
//	int operator-(const Date& d);
//	Date& operator++();
//	Date operator++(int);
//	Date& operator--();
//	Date operator--(int);
//	bool operator>(const Date& d)const;
//	bool operator>=(const Date& d)const;
//	bool operator<(const Date& d)const;
//	
//	bool operator<=(const Date& d)const;
//	bool operator==(const Date& d)const;
//	bool operator!=(const Date& d)const;
//public:
//	int GetWeek();
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//bool IsLeapYear(int year){ return(year % 4 == 0 && year % 100 != 0) || year % 400 == 0;}
//int GetDay(int year, int mouth)
//{
//	int _mouth[] = { 29,31,28,31,30,31,30,31,31,30,31,30,31 };
//	if (mouth == 2)
//	{
//		if (IsLeapYear(year))
//			return 29;	
//	}
//			return _mouth[mouth];
//}
//Date Date:: operator+(int days)  //判断一个时间+天数=什么时间
//{
//	Date tmp = *this;
//	int SearchDays = GetDay(tmp._year, tmp._month);
//	while (tmp._day + days > SearchDays)
//	{
//		tmp._month++;
//		if (tmp._month > 12)
//		{
//			tmp._year++;
//			tmp._month = 1;
//		}
//		days -= SearchDays;
//		SearchDays = GetDay(tmp._year, tmp._month);
//	}
//	tmp._day += days;
//	return tmp;
//}
//Date Date:: operator-(int days)
//{
//	Date tmp = *this;
//	while (tmp._day - days <1)
//	{
//		tmp._month--;
//		if (tmp._month == 0)
//		{
//			tmp._year--;
//			tmp._month = 12;
//		}
//		int SearchDays = GetDay(tmp._year, tmp._month);
//		days = days - SearchDays;
//	}
//	tmp._day -= days;
//	return tmp;
//}
//Date& Date:: operator++()
//{
//	*this=*this+1;
//	return *this;
//}
//Date Date::operator++(int)
//{
//	Date tmp = *this;
//	++*this;
//	return tmp;
//}
//Date& Date::operator--()
//{
//	*this = *this - 1;
//	return *this;
//}
//Date Date::operator--(int)
//{
//	Date tmp = *this;
//	--*this;
//	return tmp;
//}
//bool Date::operator>(const Date& d)const
//{
//	/*if (_year > d._year)
//		return true;
//	else if (_year < d._year)
//		return false;
//	else if (_month > d._month)
//		return true;
//	else if (_month < d._month)
//		return false;
//	else if (_day > d._day)
//		return true;
//	else if (_day < d._day)
//		return false;*/
//	return (_year > d._year) || ((_year > d._year) && (_month > d._month))
//		|| ((_year > d._year) && (_month > d._month) && (_day > d._day));
//}
//bool Date::operator<=(const Date& d)const
//{
//	return !(*this > d);
//}
////  w=（ (y-1)+(y-1)/4-(y-1)/100+(y-1)/400+d  ）%7 蔡勒公式求星期
//int Date::GetWeek()
//{
//	int D = 0;
//	for (int i = 1; i < _month; i++)
//	{
//		D= D+GetDay(_year, _month);
//	}
//	D += _day;
//	return ((_year - 1) + (_year - 1) / 4 - (_year - 1) / 100 + (_year - 1) / 400 + D) % 7;
//}
//
//ostream& operator <<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//void main()
//{
//	Date t1(2019, 12, 16);
//	cout << t1 << endl;
//	Date t2 = t1 + 32;
//	cout << t2 << endl;
//	Date t3 = t1 - 6;
//	cout << t3 << endl;
//    cout << t1.GetWeek() << endl;
//	Date t4(2013, 10, 16);
//	if (t1 > t4)
//		cout << "t1>t4" << endl;
//	if (t4 <= t1)
//		cout << "t4 <= t1" << endl;
//}
#endif