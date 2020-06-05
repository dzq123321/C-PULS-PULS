#if 0
#include<iostream>
#include<string>
using namespace std;

/*
我们首先按确定什么是右值：
 C++ 中一个被广泛认同的说法，那就是可以取地址的、 有名字的就是左值，反之，不能取地址的、没有名字的就是右值
 C++11对右值进行了严格的区分：
     C语言中的纯右值，比如：a+b, 100
     将亡值。比如：表达式的中间结果、函数按照值的方式进行返回。
*/
//引用，常引用和右值引用的区别
/*
int main()
{
	int a = 10;
	int &b = a;
	//int &b2 = 10;//不能编译  
	const int&c = a;
	const int&c2 = 10;
	//int &&d = a; //不能编译  右值引用只能引用右值
	int &&d2 = 10;
}*/
// 普通引用只能引用左值，不能引用右值，const引用既可引用左值，也可引用右值。右值引用只能引用右值，不能引用左值

//问题：既然C++98中的const类型引用左值和右值都可以引用，那为什么C++11还要复杂的提出右值引用呢？
/*
class String
{
public:
	String(char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}

	String operator+(const String& s)
	{
		char* pTemp = new char[strlen(_str) + strlen(s._str) + 1];
		strcpy(pTemp, _str);
		strcpy(pTemp + strlen(_str), s._str);
		String strRet(pTemp);
		delete[] pTemp;
		return strRet;
	}

	~String()
	{
		if (_str) delete[] _str;
	}
private:
	char* _str;
};
int main()
{
	String s1("hello");
	String s2("world");
	String s3(s1 + s2);
	return 0;
}*/
/*
在operator+中：strRet在按照值返回时，必须创建一个临时对象，临时对象创建好之后，strRet就被销毁
了，最后使用返回的临时对象构造s3，s3构造好之后，临时对象就被销毁了。仔细观察会发现：strRet、临
时对象、s3每个对象创建后，都有自己独立的空间，而空间中存放内容也都相同，相当于创建了三个内容完
全相同的对象，对于空间是一种浪费，程序的效率也会降低，而且临时对象确实作用不是很大，那能否对该
种情况进行优化呢？
C++11提出了移动语义概念，即：将一个对象中资源移动到另一个对象中的方式，可以有效缓解该问题。
String(String&& s)
 : _str(s._str)
{
 s._str = nullptr;
}
*/

class String
{
public:
	String(char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}
	String(String&& s): _str(s._str)
	{
		s._str = nullptr;
	}

	String operator+(const String& s)
	{
		char* pTemp = new char[strlen(_str) + strlen(s._str) + 1];
		strcpy(pTemp, _str);
		strcpy(pTemp + strlen(_str), s._str);
		String strRet(pTemp);
		delete[] pTemp;
		return strRet;
	}

	~String()
	{
		if (_str) delete[] _str;
	}
private:
	char* _str;
};

int main()
{
	String s1("hello");
	String s2("world");
	String s3(s1 + s2);
	return 0;
}
/*
因为strRet对象的生命周期在创建好临时对象后就结束了，即将亡值，C++11认为其为右值，在用strRet构造
临时对象时，就会采用移动构造，即将strRet中资源转移到临时对象中。而临时对象也是右值，因此在用临
时对象构造s3时，也采用移动构造，将临时对象中资源转移到s3中，整个过程，只需要创建一块堆内存即
可，既省了空间，又大大提高程序运行的效率。
注意：
1. 移动构造函数的参数千万不能设置成const类型的右值引用，因为资源无法转移而导致移动语义失效。
2. 在C++11中，编译器会为类默认生成一个移动构造，该移动构造为浅拷贝，因此当类中涉及到资源管理
时，用户必须显式定义自己的移动构造。

int main()
{
	String s1("hello");
	String s2("world");
	String s3(s1 + s2);
	return 0;
}
/*
int main()
{
	String s1("hello world");
	String s2(move(s1));
	return 0;
}*/
#endif