#if 1
#include<iostream>
using namespace std;

//����ģ��  ��֧�ַ�����롣��������֧��
//��������ģ�屻��������  1��ʵ����֮ǰ  2��ʵ����֮��
//�������Զ�����ת��
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
//	cout << Add(3 ,4) << endl;   //���ȵ��÷Ǻ���ģ��  
//	cout << Add<int>(3, 4) << endl;   //���ú���ģ��
//	cout << Add(3.5,4.3) << endl;
//	cout << Add('2', '1') << endl;
//	cout <<(int)Add(3.5, 4.3) << endl;
//	cout << Add<int>('2', '1') << endl;   // �ַ�1��ascii��ֵ��49 ��2ascii��ֵ��50  ��1��+��2��=��99����c��ascii��ֵ��99
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
//	cout << Add(3.5, 5) << endl; //�����ȵ���ģ�庯��
//	cout << ::Add(5.3, 6.3) << endl;  //ǰ���:: ֻ��Ϊ��ȷ�ϵ��õ���ȫ�ֵ�ģ�庯������ֹ��׼����Ҳ�в���������
//}

//ģ����
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
//��̬��������
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



//�������͵����ʼ��
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
//	double b = double();  //�൱���������͵�Ĭ�Ϲ��캯��
//	cout << b << endl;
//	Test t = Test();  //����Ĭ�Ϲ��캯��
//}
//template <typename Type>   
//class BintreeNode
//{
//public:
//	//Type d=Type() ���ʼ��
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
