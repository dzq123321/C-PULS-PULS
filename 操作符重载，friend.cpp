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
