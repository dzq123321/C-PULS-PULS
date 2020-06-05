#if 0
#include<iostream>
#include<string>
using namespace std;

/*
�������Ȱ�ȷ��ʲô����ֵ��
 C++ ��һ�����㷺��ͬ��˵�����Ǿ��ǿ���ȡ��ַ�ġ� �����ֵľ�����ֵ����֮������ȡ��ַ�ġ�û�����ֵľ�����ֵ
 C++11����ֵ�������ϸ�����֣�
     C�����еĴ���ֵ�����磺a+b, 100
     ����ֵ�����磺���ʽ���м�������������ֵ�ķ�ʽ���з��ء�
*/
//���ã������ú���ֵ���õ�����
/*
int main()
{
	int a = 10;
	int &b = a;
	//int &b2 = 10;//���ܱ���  
	const int&c = a;
	const int&c2 = 10;
	//int &&d = a; //���ܱ���  ��ֵ����ֻ��������ֵ
	int &&d2 = 10;
}*/
// ��ͨ����ֻ��������ֵ������������ֵ��const���üȿ�������ֵ��Ҳ��������ֵ����ֵ����ֻ��������ֵ������������ֵ

//���⣺��ȻC++98�е�const����������ֵ����ֵ���������ã���ΪʲôC++11��Ҫ���ӵ������ֵ�����أ�
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
��operator+�У�strRet�ڰ���ֵ����ʱ�����봴��һ����ʱ������ʱ���󴴽���֮��strRet�ͱ�����
�ˣ����ʹ�÷��ص���ʱ������s3��s3�����֮����ʱ����ͱ������ˡ���ϸ�۲�ᷢ�֣�strRet����
ʱ����s3ÿ�����󴴽��󣬶����Լ������Ŀռ䣬���ռ��д������Ҳ����ͬ���൱�ڴ���������������
ȫ��ͬ�Ķ��󣬶��ڿռ���һ���˷ѣ������Ч��Ҳ�ή�ͣ�������ʱ����ȷʵ���ò��Ǻܴ����ܷ�Ը�
����������Ż��أ�
C++11������ƶ�������������һ����������Դ�ƶ�����һ�������еķ�ʽ��������Ч��������⡣
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
��ΪstrRet��������������ڴ�������ʱ�����ͽ����ˣ�������ֵ��C++11��Ϊ��Ϊ��ֵ������strRet����
��ʱ����ʱ���ͻ�����ƶ����죬����strRet����Դת�Ƶ���ʱ�����С�����ʱ����Ҳ����ֵ�����������
ʱ������s3ʱ��Ҳ�����ƶ����죬����ʱ��������Դת�Ƶ�s3�У��������̣�ֻ��Ҫ����һ����ڴ漴
�ɣ���ʡ�˿ռ䣬�ִ����߳������е�Ч�ʡ�
ע�⣺
1. �ƶ����캯���Ĳ���ǧ�������ó�const���͵���ֵ���ã���Ϊ��Դ�޷�ת�ƶ������ƶ�����ʧЧ��
2. ��C++11�У���������Ϊ��Ĭ������һ���ƶ����죬���ƶ�����Ϊǳ��������˵������漰����Դ����
ʱ���û�������ʽ�����Լ����ƶ����졣

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