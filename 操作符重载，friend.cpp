#if 1
#include <iostream>
using namespace std;
/*
�����һ�³�Աʱ��������ڳ��Ի��б���г�ʼ��
���ñ�����Ա��
const��Ա����
�����ͳ�Ա������û��Ĭ�Ϲ��캯����
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
//	int& _ref;  //����
//	const int _n; //const��Ա����
//	Base base;//�����ͳ�Ա
//};
//void main()
//{
//	Test t1(2, 5);
//}
/*
explicit �ؼ���
���캯���������Թ�����Ի����󣬶��ڵ��������Ĺ��캯��������������ת��������
explicit �ؼ���  �޶����캯��ֻ�ǳ��Ի����󣬲�������ת��
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
//	d1 = (Test)2019;   //�������explicit,2019���ȱ�ת��ΪTest���ͣ��ڵ��ø�ֵ��������غ���
//	Test d2(1);
//	int value = d1;	//����
//}

/*
static
����static�����Ա��Ϊ��ľ�̬��Ա����static���εĳ�Ա��������Ϊ��̬��Ա��������static���εĳ�Ա��������֮Ϊ
��̬��Ա��������̬�ĳ�Ա����һ��Ҫ��������г��Ի�
1����̬��ԱΪ���������������������ĳ�������ʵ��
2����̬��Ա�������������ⶨ�壬����ʱ�����static�ؼ���
3���ྲ̬��������������������̬��Ա����󣬾�̬��Ա������
4����̬��Ա����û�����ص�thisָ�룬���ܷ����κηǾ�̬��Ա
5����̬��Ա�������ͨ��Աһ������public,protected,private 3�ַ��ʼ���Ҳ���Ծ��з���ֵ
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
//	static int GetUseCount()  //��̬����û��thisָ��
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

//��Ԫ������Ԫ��
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
//	d << cout;   //��û�ж�����Ԫ����뷴��д
//	return 0;
//}
//��Ԫ�����������������Ԫ������Ҳ�������أ������ػ�������⣬�޷����Ʋ�����˳��thisָ��������������ռλ�ã���Ҫ
//����������ڵ�һ��λ�ã���ʵ����thisָ���ڵ�һ��λ�ã����������ʱ���ƽʱ�෴��
//class Data
//{
//	friend ostream &operator << (ostream & _cout, const Data& d);
//	friend istream& operator >> (istream & _cin, Data& d); //d���ܼ�const,��const�Ͳ��ܸı�d��
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
//һ�����������Ƕ�������Ԫ����
/*
��Ԫ��:
��Ԫ������г�Ա��������������һ�������Ԫ�����������Է�����һ����ķǹ��г�Ա

*/
//class Data;//ǰ������
//class Time
//{
//	friend ostream& operator <<( ostream&_cout, const Time& t);
//	friend class Data;  //������������ʱ�������Ԫ�࣬����������Է���ʱ����time��˽�г�Ա
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
//		// ֱ�ӷ���ʱ����˽�еĳ�Ա����
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

/*�ڲ���
���һ���ඨ������һ������ڲ��������ͽ����ڲ��࣬ע������ڲ�����һ���������࣬�������ⲿ�࣬������ͨ���ⲿ���
�Ķ���ȥ�����ڲ��࣬�ⲿ����ڲ���û�з���Ȩ��
�ڲ������ⲿ�����Ԫ�࣬�ڲ�����Է����ⲿ�࣬���ⲿ�಻�ܷ����ڲ���
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
//int A::count = 0;  //�ڲ������ֱ�ӷ����ⲿ���static��Ա  
//
//int main()
//{
//	A::B b;
//	A t(5);   //�����ඨ�������Σ�����count=2
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
//		int sum = m_i + x.m_i;  //return Int(m_i + x.m_i)  ������ʱ����
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
//	Int & operator++(int)  //i++   (int)ֻ��һ��α��������Ϊ������++i i++
//	{
//		Int tmp(*this);
//		++*this;//  *this++ ���� ���ʽ�����ǿ��޸ĵ���ֵ
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
//		--*this;//  *this++ ���� ���ʽ�����ǿ��޸ĵ���ֵ
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
//	int _year; // ��
//	int _month; // ��
//	int _day; // ��
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
