#if 0
#include<iostream>
using namespace std;
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
template <class T1>
class Data<T1, int> {
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};
template <class T1>
class Data {
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};
//两个参数偏特化为引用类型
template <typename T1, typename T2>
class Data <T1&, T2&>
{
public:
	Data(const T1& d1, const T2& d2)
		: _d1(d1)
		, _d2(d2)
	{
		cout << "Data<T1&, T2&>" << endl;
	}
private:
	const T1 & _d1;
	const T2 & _d2;
};
template<class T1,class T2>
class Data {
public:
	Data() { cout << "Data<int, char>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
void TestVector()
{
	Data<int, int> d1;
	Data<int, char> d2;
}
#endif