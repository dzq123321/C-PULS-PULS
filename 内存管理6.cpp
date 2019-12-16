#if 1
#include<iostream>
using namespace std;
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


class Date
{
	friend ostream& operator <<(ostream& _cout, const Date& d);
public:
	Date(int year = 1900, int month = 1, int day = 1): _year(year), _month(month), _day(day)
	{}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	Date operator+(int days);
	Date operator-(int days);
	int operator-(const Date& d);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	bool operator>(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator<(const Date& d)const;
	
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;
public:
	int GetWeek();
private:
	int _year;
	int _month;
	int _day;
};

bool IsLeapYear(int year){ return(year % 4 == 0 && year % 100 != 0) || year % 400 == 0;}
int GetDay(int year, int mouth)
{
	int _mouth[] = { 29,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (mouth == 2)
	{
		if (IsLeapYear(year))
			return 29;	
	}
			return _mouth[mouth];
}
Date Date:: operator+(int days)  //判断一个时间+天数=什么时间
{
	Date tmp = *this;
	int SearchDays = GetDay(tmp._year, tmp._month);
	while (tmp._day + days > SearchDays)
	{
		tmp._month++;
		if (tmp._month > 12)
		{
			tmp._year++;
			tmp._month = 1;
		}
		days -= SearchDays;
		SearchDays = GetDay(tmp._year, tmp._month);
	}
	tmp._day += days;
	return tmp;
}
Date Date:: operator-(int days)
{
	Date tmp = *this;
	while (tmp._day - days <1)
	{
		tmp._month--;
		if (tmp._month == 0)
		{
			tmp._year--;
			tmp._month = 12;
		}
		int SearchDays = GetDay(tmp._year, tmp._month);
		days = days - SearchDays;
	}
	tmp._day -= days;
	return tmp;
}
Date& Date:: operator++()
{
	*this=*this+1;
	return *this;
}
Date Date::operator++(int)
{
	Date tmp = *this;
	++*this;
	return tmp;
}
Date& Date::operator--()
{
	*this = *this - 1;
	return *this;
}
Date Date::operator--(int)
{
	Date tmp = *this;
	--*this;
	return tmp;
}
bool Date::operator>(const Date& d)const
{
	/*if (_year > d._year)
		return true;
	else if (_year < d._year)
		return false;
	else if (_month > d._month)
		return true;
	else if (_month < d._month)
		return false;
	else if (_day > d._day)
		return true;
	else if (_day < d._day)
		return false;*/
	return (_year > d._year) || ((_year > d._year) && (_month > d._month))
		|| ((_year > d._year) && (_month > d._month) && (_day > d._day));
}
bool Date::operator<=(const Date& d)const
{
	return !(*this > d);
}
//  w=（ (y-1)+(y-1)/4-(y-1)/100+(y-1)/400+d  ）%7 蔡勒公式求星期
int Date::GetWeek()
{
	int D = 0;
	for (int i = 1; i < _month; i++)
	{
		D= D+GetDay(_year, _month);
	}
	D += _day;
	return ((_year - 1) + (_year - 1) / 4 - (_year - 1) / 100 + (_year - 1) / 400 + D) % 7;
}

ostream& operator <<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
void main()
{
	Date t1(2019, 12, 16);
	cout << t1 << endl;
	Date t2 = t1 + 32;
	cout << t2 << endl;
	Date t3 = t1 - 6;
	cout << t3 << endl;
    cout << t1.GetWeek() << endl;
	Date t4(2013, 10, 16);
	if (t1 > t4)
		cout << "t1>t4" << endl;
	if (t4 <= t1)
		cout << "t4 <= t1" << endl;
}
#endif