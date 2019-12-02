#if 1
#include<iostream>
//#include<vld.h>
#include<assert.h>
//c++和c主要区别是结构体内不仅可以定义变量，还可以定义函数，为此引入class
//struct 默认共有public， class默认private
using namespace std;
//
//c++时可以在结构体中定义函数，c不行 ,c++情况下struct情况和class一样，默认有一个this指针 
//struct Student
//{
//	void SetStudentInfo(const char* name, const char* gender, int age)
//	{
//		strcpy(this->name, name);
//		strcpy(this->gender, gender);
//		this->age = age;   //对于this指针，c++定义的结构体也默认存在this指针
//	}
//	void PrintStudentInfo()
//	{
//		cout << name << " " << gender << " " << age << endl;
//	}
//	char name[20];
//	char gender[3];
//	int age;
//};
//int main()
//{
//	Student s1; 
//	s1.SetStudentInfo("Peter", "男", 18);
//	//s.PrintStudentInfo();
//	Student s2;
//	s2.SetStudentInfo("Alice", "女", 19);
//	//s.PrintStudentInfo();
//	return 0;
//}
//class CGoods
//{
//public:
//	void RegisterGoods(char* name, int count, float price)
//	{
//		
//		strcpy(this->name, name);
//		this->count = count;
//		this->price = price;
//	}
//	void SetName(char* name)
//	{
//		strcpy(this->name, name);
//	}
//	void SetCount(int count);
//	void SetPrice(float price);
//public:
//	char* GetName()
//	{
//		return name;
//	}
//	int GetCount();
//	float GetPrice();
//	float GetTotalPrice();
//private:
//	char name[10];
//	int count;
//	float price;
//	float total_price;
//};
//int main()
//{
//	CGoods G1;
//	CGoods G2;
//	G1.RegisterGoods("c++", 5, 3.0);
//	G2.RegisterGoods("数据结构", 8, 9.0);
//	cout << "GetName()= " << G1.GetName() << endl;
//	//G1.SetName("JAVA");
//}

/*
c++中struct和class的区别
(1) 因为c++是要和c兼容的，在c++中struct可以当作结构体，也可以当作类
（2） 在当作类的时候，struct的成员时默认公共的，class是默认私有的。
（3） class 类为空时，默认大小为1,空类和空结构体的大小都为1
*/
//this指针的概念
//构造函数，拷贝构造函数，析构函数

/*
1、构造函数：
函数名与类名相同
无返回值
对象实例化时编译器自动调用对应的构造函数
构造函数可以重载
2、拷贝构造函数：
拷贝构造函数是构造函数的一种重载形式
拷贝构造函数的参数只有一个且必须使用引用传参，使用传值方式会引发无穷递归调用
3、析构函数：
函数名是类名前加字符~
无参无返回值
一个类有且只有一个析构函数
对象生命周期结束时系统自动定义
*/
//
//class SeqList
//{
//public:
//	SeqList(int capacity = 10)
//	{
//		_pData = (int*)malloc(sizeof(int)*capacity);
//		assert(_pData);
//		_size = 0;
//		_capacity = capacity;
//	}
//	//~SeqList()
//	//{
//	//	if (_pData)
//	//	{
//	//		free(_pData);
//	//		_pData = NULL;
//	//		_capacity = 0;
//	//		_size = 0;
//	//	}
//	//}
//private:
//	int * _pData;
//	size_t _size;
//	size_t _capacity;
//
//};
//void main()
//{
//	SeqList L1;
//}
//class Data
//{
//public:
//	Data(int month, int day) : _month(month), _day(day)//构造函数//赋初值(比函数里初始化定义效率高)
//	{
//		cout << "Creat this object" << endl;
//	}
//	Data ()
//	{
//		cout << "Creat this object" << endl;
//	}
//	Data(const Data &d)  //默认的拷贝构造函数是浅拷贝，只拷贝值，不会开辟空间，当需要开辟空间传递时只会传递指针
//	{          //一般加const 希望不会改变被引用对象的参数
//		cout << "copy this object" << endl;
//		_month = d._month;
//		_day = d._day;
//	}
//	~Data()  //析构函数无参无返回值
//	{
//		cout << "Free this object" << endl;
//	}
//private:
//	int _month;
//	int _day;
//};
//void main()
//{
//	Data d1;  //通过无参构造函数创建对象时，对象后不用跟括号，否则成为函数声明
//	Data d2(10, 20);
//	Data d3 = d2;
//}
//无参构造函数和全缺省的构造函数都认为是默认构造函数

//拷贝构造函数的深拷贝
//class String
//{
//public:
//	String(const char* str = "")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//			strcpy(_str, str);
//			cout << this << endl;
//	}
//	String( const String& s)
//	{
//		cout << this << endl;
//		cout << "深拷贝" << endl;
//		_str = (char*)malloc(strlen(s._str) + 1);
//		strcpy(_str, s._str);
//	}
//	~String()
//	{
//		cout << "~string" << endl;
//		cout << this << endl;
//		free(_str);
//	}
//private:
//	char *_str;
//};
//int main()
//{
//	String s1("hello");
//	String s2(s1);	
//}



//void main()
//{
//	char ar[10] = "Hello";  // \0
//	cout << strlen(ar) << endl;  //  5
//	cout << sizeof(ar) << endl;  //  10
//}

//void main()
//{
//	char ar[10] = { 'H','e','l','l','o' };  //之后/0补齐
//	cout << strlen(ar) << endl;  // 5
//	cout << sizeof(ar) << endl;  // 10
//}
//void main()
//{
//	char ar[10] = { 'H','e','l','l','o','w','o','r','l','d' };
//	cout << strlen(ar) << endl;  // 随机值没有找到\0
//	cout << sizeof(ar) << endl;  // 10
//}
//char ar[10];  //全局变量和静态变量默认初始化为0
//void main()
//{
//	static char ar[10];
//	cout << strlen(ar) << endl;  // 0
//	cout << sizeof(ar) << endl;  // 10
//}
//void main()
//{
//	char *ar = "Hellongfalflafl";
//	cout << strlen(ar) << endl;  // 15 字符串的实际大小
//	cout << sizeof(ar) << endl;  // 4
//}

//void main()
//{
//	char ar[10];
//	for (int i = 0; i < 5; ++i)
//	{
//		ar[i] = 'a' + i;   //若为一个一个输入时，未输入完全后边不会补0，就算输入完全，但只要没\0,就还是随机值
//	}
//	cout << strlen(ar) << endl;  //    随机值
//	cout << sizeof(ar) << endl;  // 10  
//}

//void main()
//{
//	short* ar1[10][10];  //*的优先级小于[]的优先级，所以ar1先和[]结合，定义的ar1最终就是数组,里面的元素是short*的指针
//	short(*ar2)[10][10];
//    cout << sizeof(ar1) << endl;  //指针数组 400
//	cout << sizeof(ar2) << endl;  //数组指针 4	
//}
/*赋值运算符重载

c++为了增强代码的可读性引入了运算符重载，运算符重载是具有特殊函数名的函数，也具有其返回值类型，函数名字以及
参数列表，其返回值类型与参数列表与普通的函数类似
1、作为类成员的重载函数，其形参看起来比操作数少一个成员（因为是成员函数，存在一个默认的this指针代表驱动这个函数的对象）
*/
//class Data
//{
//public:
//	Data()
//	{}  //构造函数重载
//	Data(int year,int month,int day) :  _day(day), _month(month),_year(year)//赋初值时只与定义变量时(private)的顺序有关，
//	{
//		cout << "create the data" << endl;
//	}
//	Data(const Data& d)
//	{
//		this->_day=d._day ;//隐含this表示d2的地址
//		_month=d._month ;
//		_year=d._year ;
//	}
//	Data &operator=(const Data& d)
//	{
//		if (this != &d)  //1、自我赋值检测  2、释放当前对象空间 3、重新开辟空间并赋值 4、返回当前对象
//		{
//			this->_day = d._day;//隐含this表示d2的地址
//			_month = d._month;
//			_year = d._year;
//		}
//		return *this;
//	}
//	bool operator==(const Data& d)const
//	{
//		return _day == d._day&&_month == d._month&&_year == d._year;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void main()
//{
//	Data d1(1, 2, 3);
//	Data d2(d1);
//	Data d3;
//	d3 = d1;
//	if (d3 == d1)
//		cout << "相等" << endl;
//}
class String
{
public:
	String(const char *str = "")
	{
		_str = (char*)malloc(strlen(str)+1);
		strcpy(_str, str);
	}
	String(const String& str)
	{
		_str = (char*)malloc(strlen(str._str)+1);
		strcpy(_str, str._str);
		cout << "copy" << endl;
	}
	String& operator= (const String& str)
	{
		if (this != &str)
		{
			_str = (char*)malloc(strlen(str._str)+1);
			strcpy(_str, str._str);
			cout << "赋值" << endl;
			return *this;
		}
	}
	~String()
	{
		free(_str);
		_str = NULL;
	}
private:
	char* _str;
};

void main()
{
	String s1("hello");
	String s2(s1);
	String s3;
	s3 = s2;
	const String s4("hello");
	String *p = &s3;
	const String *q = &s4;
}
//一个空类会默认生成6个成员函数 构造 析构 拷贝构造 赋值重载 
//（普通对象取地址 const对象取地址(这两个一般不需要，当想让别人获取指定的内容)）
#endif