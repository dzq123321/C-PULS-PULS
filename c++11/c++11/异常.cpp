#if 1
#include<iostream>
#include<string>
using namespace std;

double Division(int a, int b)
{
	// ��b == 0ʱ�׳��쳣
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
// ������������ͨ��ʹ�õ��쳣�̳���ϵ
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
		// �׳����������������
	}
	catch ( Exception& e) // ���ﲶ�������Ϳ���
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