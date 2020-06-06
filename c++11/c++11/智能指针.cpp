#if 1
#include<iostream>
#include<string>
#include<memory>
using namespace std;


/*
double Division(int a, int b)
{
	// ��b == 0ʱ�׳��쳣
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}
void Func()
{
	// ������Կ������������0�����׳��쳣�����������arrayû�еõ��ͷš�
	// �������ﲶ���쳣�󲢲������쳣���쳣���ǽ������洦�����ﲶ������
	// �����׳�ȥ��
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
		e.What(); //��̬
	}
	catch (...)
	{
		cout << "Unkown Exception" << endl;
	}
	return 0;

}
*/
//RAII ��Դ��ȡ����ʼ��  �Զ�
/*
void main()
{
	int  *tmp = new int(100);
	auto_ptr<int> ap(tmp); //����ָ��ap�ӹ�tmp��ap��ʵ��һ���������������ڶ�����������������Ҫ�û�����
	cout << *ap << endl;
	auto_ptr<string> ap1(new string("hello world!"));
	cout << ap1->size() << endl;
}
*/
//VC Դ��ģ��  ���й���Ȩ

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
		((my_auto_ptr<_Ty>*)this)->_Owns = false;  //ǿ��ת�� ��������
		return _Ptr;
	}
	_Ty* get()const
	{
		return _Ptr;
	}
private:
	bool _Owns;//����Ȩ
	_Ty *_Ptr;  //ָ������ַ��ָ��
};





#endif