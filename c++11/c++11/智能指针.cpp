#if 1
#include<iostream>
#include<string>
#include<memory>
using namespace std;


/*
double Division(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}
void Func()
{
	// 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再
	// 重新抛出去。
	int* array = new int[10];
	try {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)
	{
		cout << "delete1 []" << array << endl;
		delete[] array;
		throw;
	}

	cout << "delete2 []" << array << endl;
	delete[] array;
}
int main()
{
	try
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	return 0;
}
*/


/*
class Exception
{
public:
	virtual void What() = 0;

public:
	string _errmsg = "Have a Exception.";
};
class SqlException : public Exception

{
public:
	virtual void What()
	{
		cout << "SqlException Exception" << endl;
	}
};

class CacheException : public Exception
{
public:
	virtual void What()
	{
		cout << "CacheException Exception" << endl;
	}
};

class HttpServerException : public Exception
{
public:
	virtual void What()
	{
		cout << "HttpServerException Exception" << endl;
	}
};

void Startup()
{

	//throw SqlException();	
	throw HttpServerException();
}
int main()
{
	try
	{
		Startup();
	}
	catch (Exception& e)
	{
		e.What(); //多态
	}
	catch (...)
	{
		cout << "Unkown Exception" << endl;
	}
	return 0;

}
*/
//RAII 资源获取及初始化  自动
/*
void main()
{
	int  *tmp = new int(100);
	auto_ptr<int> ap(tmp); //智能指针ap接管tmp，ap其实是一个对象，智能体现在对象由析构方法，不要用户析构
	cout << *ap << endl;
	auto_ptr<string> ap1(new string("hello world!"));
	cout << ap1->size() << endl;
}
*/
//VC 源码模拟  带有管理权

template<class _Ty>

class my_auto_ptr
{
public:
	my_auto_ptr(_Ty *_P = 0) : _Owns(_P != 0), _Ptr(_P)
	{}
	my_auto_ptr(const my_auto_ptr<_Ty> &_Y) : _Owns(_Y._Owns), _Ptr(_Y.release())
	{}
	my_auto_ptr<_Ty>& operator=(const  auto_ptr<_Ty>& _Y)
	{
		if (this != &_Y)
		{
		if (_Ptr != _Y.get())
			{
				if (_Owns)
					delete _Ptr;
				_Owns = _Y._Owns;
			}
			else if (_Y._Owns)   //false
				_Owns = true;
			_Ptr = _Y.release();
		}
		return (*this);
	}
	~auto_ptr()
	{
		if (_Owns)
			delete _Ptr;
	}
public:
	_Ty& operator*()const
	{
		return *_Ptr;
	}
	_Ty* operator->()const

	{
		return _Ptr;
	}
public:
	_Ty* release()const
	{
		//_Owns = false;
		//*((bool*)&_Owns) = false;
		((my_auto_ptr<_Ty>*)this)->_Owns = false;  //强制转换 忽略类型
		return _Ptr;
	}
	_Ty* get()const
	{
		return _Ptr;
	}
private:
	bool _Owns;//管理权
	_Ty *_Ptr;  //指向这块地址的指针
};





#endif