#if 1
#include<iostream>
using namespace std;

//函数模板  不支持分离编译。编译器不支持
//整个过程模板被编译两次  1、实例化之前  2、实例化之后
//不允许自动类型转化
//int Add(const int left, const int right)
//{
//	return left + right;
//}
//template <typename Type>
//Type Add(const Type left, const Type right)
//{
//	cout << typeid(left).name() << endl;
//	return left + right;
//}
//int main()
//{
//	cout << Add(3 ,4) << endl;   //优先调用非函数模板  
//	cout << Add<int>(3, 4) << endl;   //调用函数模板
//	cout << Add(3.5,4.3) << endl;
//	cout << Add('2', '1') << endl;
//	cout <<(int)Add(3.5, 4.3) << endl;
//	cout << Add<int>('2', '1') << endl;   // 字符1的ascii码值是49 ，2ascii码值是50  ‘1’+‘2’=‘99’而c的ascii码值是99
//	char a = 2;
//	cout << (int)a << endl;
//}
//int Add(const int left, const int right)
//{
//	return left + right;
//} 
//template <typename Type1, typename Type2>
//Type1 Add(Type1 left, Type2 right)
//{
//	return left + right;
//}
//int main()
//{
//	cout << Add(3.5, 5) << endl; //会优先调用模板函数
//	cout << ::Add(5.3, 6.3) << endl;  //前面加:: 只是为了确认调用的是全局的模板函数，防止标准库里也有产生二义性
//}

//模板类
//template <class T>
//class vector
//{
//public:
//	vector(size_t capacity = 10)
//		: _pdata(new T[capacity])
//		, _size(0);
//	    ,_capacity(capacity)
//		{}
//		~vector();
//public:
//	T& operator[] (size_t pos)
//	{
//		assert(pos < _size)
//			return _pdata[pos];	
//	}
//private:
//	T* _pdata;
//	size_t _size;
//	size_t _capacity;
//};
//template <class T>
//vector<T>::~vector()
//{
//	if (pdata)
//		delete[] _pdata;
//	_size = _capacity = 0;
//}
//class Test
//{
//public:
//	Test(int d = 0) :m_data(d)
//	{}
//	~Test(){}
//public:
//	bool operator >(const Test& t)
//	{
//		return m_data > t.m_data;
//	}
//private:
//	int m_data;
//};
//
//template<typename Type>
//Type Max(Type a, Type b)
//{
//	cout << typeid(a).name() << endl;
//	return a > b ? a : b;
//}
//void main()
//{
//	cout << Max("a", "b") << endl;
//	Test t(10), t2(20);
//	cout << (t>t2) << endl;
//}
//动态向量数组
#pragma once
#include <assert.h>
template <typename Type = int, size_t SIZE = 100>
class Array
{
public:
	Array(size_t sz = SIZE);
	~Array();
public:
	Type& operator[](int pos);
	Type& at(int pos);
public:
	Type front()const;
	Type back()const;
public:
	Type* operator+(int offset);
	Type& operator*();
private:
	Type *base;
	int size;
	size_t capacity;
};
template <typename Type, size_t SIZE>
Array<Type, SIZE>::Array(size_t sz) :base(nullptr)
{
	base = new Type[sz];
	memset(base, 0, sizeof(Type)*sz);
	size = 0;
	capacity = sz;
}
template <typename Type, size_t SIZE>
Array<Type, SIZE>::~Array()
{
	delete[] base;
	base = nullptr;
	size = capacity = 0;
}
template <typename Type, size_t SIZE>
Type& Array<Type, SIZE>::operator[](int pos)
{
	assert (pos>-1 || pos <size+1);
	return base[pos];
}
template <typename Type,size_t SIZE>
Type& Array<Type, SIZE>:: operator*()
{
	assert(base != nullptr);
	return *base;
}
template <typename Type, size_t SIZE>
Type* Array<Type,SIZE>:: operator+(int offset)
{
	assert(base != nullptr);
	return (base+offset);
}
void main()
{
	Array <int> ar(100);
	/*for (int i = 0; i < 100; i++)
	{
		ar[i - 1] = i;
	}*/
	for (int i = 0; i < 100; i++)
	{
		*(ar + i) = i;
	}
	for (int i = 0; i < 100; ++i)
	{
		cout << ar[i] << " ";
		if (i!=0 &&i % 10 == 0)
			cout << endl;
	}
	
}



//内置类型的零初始化
//class Test
//{
//public:
//	Test(int d = 0) :_mdata(d)
//	{}
//	~Test()
//	{};
//public:
//	bool operator >(const Test &t)
//	{
//		return _mdata > t._mdata;
//	}
//private:
//	int _mdata;
//};
//void main()
//{
//	int a = int();
//	cout << a << endl;
//	double b = double();  //相当于内置类型的默认构造函数
//	cout << b << endl;
//	Test t = Test();  //调用默认构造函数
//}
//template <typename Type>   
//class BintreeNode
//{
//public:
//	//Type d=Type() 零初始化
//	BintreeNode(Type d=Type(),BintreeNode<Type>* left=nullptr,BintreeNode<Type>*right=nullptr)
//		: data(d), leftchild(left), rightchild(right)
//	{}
//private:
//	Type data;
//	BintreeNode<Type>* leftchild;
//	BintreeNode<Type>* rightchild;
//};
//
//void main()
//{
//	BintreeNode<int> node;
//}


#endif
