#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
//传统的string类的写法
//class String
//{
//	friend ostream & operator <<(ostream& out, const String& str);
//public:
//	String(const char* str = "")  //构造函数
//	{
//		m_str = new char[strlen(str) + 1];
//		strcpy(m_str, str);
//	}
//	String(const String &s)  //拷贝构造函数
//	{
//
//		m_str = new char[strlen(s.m_str) + 1];
//		strcpy(m_str, s.m_str);
//	}
//	String& operator =(const String& s)  //复制运算符重载
//	{
//		if (this != &s)
//		{
//			delete[]m_str;
//			m_str = new char[strlen(s.m_str) + 1];
//			strcpy(m_str, s.m_str);
//		}
//		return *this;
//	}
//private:
//	char* m_str;
//};
//ostream & operator <<(ostream& out, const String& str)
//{
//	out << str.m_str;
//	return out;
//}

//现代的string类的写法  主要改变的是拷贝构造和赋值运算符重载。利用系统的swap函数
//class String
//{
//public:
//	friend ostream& operator <<(ostream& out, const String &str);
//	String(const char* str = " ")
//	{
//		m_str = new char[strlen(str) + 1];
//		strcpy(m_str, str);
//	}
//	String(const String& str) :m_str(nullptr)
//	{
//		String tmp(str.m_str);
//		std::swap(this->m_str, tmp.m_str);
//	}
//	String & operator=(const String& str)
//	{
//		if (this != &str)
//		{
//			String tmp(str.m_str);
//			std::swap(this->m_str, tmp.m_str);
//		}
//		return *this;
//	}
//	~String()
//	{
//		if (m_str)
//		{
//			delete[] m_str;
//			m_str = nullptr;
//		}
//
//	}
//private:
//	char *m_str;
//};
//ostream& operator <<(ostream& out, const String &str)
//{
//	out << str.m_str;
//	return out;
//}
//int main()
//{
//	String s;
//	String s1("adsd");
//	String s2 = s1;
//	String s3;
//	s3 = s2;
//	cout << s3 << endl;
//}

// 模拟string 类的实现
namespace Mystring
{
	class string
	{
	public:
		typedef  char* iterator;
		friend ostream& operator << (ostream& out, const string& str);

		string(const char* str = "") :m_str(nullptr), _size(0), _capacity(0)
		{
			m_str = new char[strlen(str) + 1];
			strcpy(m_str, str);
			_size = _capacity = strlen(str) + 1;
		}
		string(const string& str) :m_str(nullptr)
		{
			string tmp(str.m_str);
			_swap(*this, tmp);
		}
		string& operator =(const string& str)
		{
			if (this != &str)
			{
				string tmp(str.m_str);
				_swap(*this, tmp);
			}
			return *this;
		}
	public:
		char* c_str()
		{
			char* newstr = new char[_size];
			strcpy(newstr, m_str);
			return newstr;
		}
		iterator begin()
		{
			return m_str;
		}
		iterator end()
		{
			return m_str+_size;
		}
		int size()
		{
			return _size;
		}
		char& operator [] (int i)
		{
			return m_str[i];
		}

	public:
		string& push_back(char x)
		{
			if (_size == _capacity)
			{
				reverse(_capacity * 2);
				m_str[size()] = x;
				_size++;
			}
			return *this;
		}
		void reverse(size_t newcap)
		{
			if (newcap > _capacity)
			{
				char* newp = new char[newcap];
				assert(newp != nullptr);
				_capacity = newcap;
				strcpy(newp, m_str);
				delete[] m_str;
				m_str = newp;
				newp = nullptr;
			};
		}
		void clear()
		{
			_size = 0;
			m_str[0] = '\0';
		}
	protected:
		static  void _swap(string& s1, string& s2)
		{
			swap(s1.m_str, s2.m_str);
			swap(s1._capacity, s2._capacity);
			swap(s1._size, s2._size);

		}
	private:
		char *m_str;
		int _size;
		int _capacity;
	};
	ostream& operator<< (ostream& out, const string& str)
	{
		out << str.m_str;
		return out;
	}


}
void main()
{
	Mystring::string s1 = "hello C";
	Mystring::string s2(s1);
	Mystring::string s3;
	s3 = s2;
	cout << s2 << endl;
	cout << s3 << endl;
	Mystring::string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it;
		it++;
	}
	cout << endl;
	cout<<s1.c_str() << endl;
	cout << endl;
	s1.push_back('+');
	s1.push_back('+');
	cout << s1 << endl;
}
