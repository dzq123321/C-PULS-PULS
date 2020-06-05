#if 1
#include<iostream>
#include<string>
using namespace std;

double Division(int a, int b)
{
	// 当b == 0时抛出异常
	//if (b == 0)
		//throw "Division by zero condition!";
	if (b == 0)
		throw b;
	else
		return ((double)a / (double)b);
}
void Func()
{
	int len, time;
	cin >> len >> time;
	cout << Division(len, time) << endl;
}
int main()
{
	try
	{
		Func();
	}
	catch (int &b)
	{
		  cout << b << endl;
	}
	catch (const char* errmsg)
	{
		  cout << errmsg << endl;
	}
   catch (...)
	{
		cout << "unkown exception" << endl;
	}
		return 0;
}


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
// 服务器开发中通常使用的异常继承体系
class Exception
{
public:
	virtual void What()
	{
		cout << "Have a  Exception" << endl;
	}

};
class SqlException : public Exception
{};
class CacheException : public Exception
{};
class HttpServerException : public Exception
{};
void Start()
{
	throw SqlException();
}
int main()
{
	try {
		Start();
		// 抛出对象都是派生类对象
	}
	catch ( Exception& e) // 这里捕获父类对象就可以
	{
		e.What();
	}
	catch (...)
	{
		cout << "Unkown Exception" << endl;
	}
	return 0;
}

*/








#endif