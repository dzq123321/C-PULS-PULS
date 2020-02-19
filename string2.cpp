#if 1
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

 //模拟string 类的实现
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
			_size = _capacity = strlen(str) ;
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
		~string()
		{
			if (m_str)
			{
				delete[] m_str;
				m_str = nullptr; 
			}
		}
	public:
		const char* c_str()const{return m_str;}
		iterator begin(){return m_str;}
		iterator end(){return m_str+_size;}
		int size(){	return _size;}
		char& operator [] (int i){return m_str[i];}
		const char& operator[](size_t i)const
		{
			assert(i < _size &&i >= 0);
			return m_str[i];
		}
		int capacity() {return _capacity;}
	public:
		void push_back(char x)
		{
			if (_size >= _capacity)
				reserve(_capacity * 2);
				m_str[_size++] = x;
				m_str[_size] = '\0';
		}
		void reserve(size_t newcap)
		{
			if (newcap > _capacity)
			{
				char* newp = new char[newcap+1 ];
				assert(newp != nullptr);
				_capacity = newcap;  
				memset(newp, 0, newcap + 1);
				memcpy(newp, m_str, _size);
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
		void resize(size_t newSize, char c = '\0')
		{
			if (newSize > _size)
			{
				if (newSize > _capacity)
				{
					reserve(newSize * 2);
				}
				memset(m_str + _size, c, newSize - _size);
			}
			_size = newSize;
			m_str[newSize] = '\0';
		}
		void append(const char* str)
		{
			size_t str_len = strlen(str);
			if (str_len + _size >= _capacity)
			{
				reserve((str_len + _size) * 2);
			}
			strcpy(m_str + _size, str);
		}
	public:
		string& operator +=(char c)
		{
			 push_back(c);
			return *this;
		}
		bool operator<(const string& s){return (strcmp(m_str, s.m_str) < 0);}
		bool operator<=(const string& s) { return !(m_str > s.m_str); }
		bool operator>(const string& s) { return (strcmp(m_str, s.m_str) > 0); }
		bool operator>=(const string& s) { return !(m_str < s.m_str); }
		bool operator==(const string& s) { return (m_str ==s.m_str); }
		bool operator!=(const string& s) { return !(m_str == s.m_str); }
		
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
	Mystring::string s1("Hello");
	Mystring::string s2("Linux");
	if (s1 > s2)
		cout << "s1 > s2" << endl;
	else
		cout << "s1 <= s2" << endl;


}
//void main()
//{
//	Mystring::string s1 = "hello C++";
//	cout << s1 << endl;
//	cout << "size= " << s1.size() << endl;
//	cout << "capacity= " << s1.capacity() << endl;
//	s1.append(" LInux");
//	cout << s1 << endl;
//	cout << "size= " << s1.size() << endl;
//	cout << "capacity= " << s1.capacity() << endl;
//	s1.reserve(20);
//	s1.resize(15, '*');
//	cout << s1 << endl;
//	cout << "size= " << s1.size() << endl;
//	cout << "capacity= " << s1.capacity() << endl;
//	/*s1.push_back('5');
//	cout << s1 << endl;
//	cout << "size= " << s1.size() << endl;
//	cout << "capacity= " << s1.capacity() << endl;
//	s1 += '5';
//	cout << s1 << endl;
//	cout << "size= " << s1.size() << endl;
//	cout << "capacity= " << s1.capacity() << endl;*/
//	/*s1.reserve(15);
//	cout << "size= "<<s1.size() << endl;
//	cout << "capacity= "<<s1.capacity() << endl;
//	cout << s1 << endl;*/
//
//	/*Mystring::string s2(s1);
//	Mystring::string s3;
//	s3 = s2;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	Mystring::string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it;
//		it++;
//	}
//	cout << endl;
//	cout<<s1.c_str() << endl;
//	cout << endl;*/
//	
//}
#endif