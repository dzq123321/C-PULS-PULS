#if 1
#include<iostream>
//#include<vld.h>
#include<assert.h>
//c++��c��Ҫ�����ǽṹ���ڲ������Զ�������������Զ��庯����Ϊ������class
//struct Ĭ�Ϲ���public�� classĬ��private
using namespace std;
//
//c++ʱ�����ڽṹ���ж��庯����c���� ,c++�����struct�����classһ����Ĭ����һ��thisָ�� 
//struct Student
//{
//	void SetStudentInfo(const char* name, const char* gender, int age)
//	{
//		strcpy(this->name, name);
//		strcpy(this->gender, gender);
//		this->age = age;   //����thisָ�룬c++����Ľṹ��ҲĬ�ϴ���thisָ��
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
//	s1.SetStudentInfo("Peter", "��", 18);
//	//s.PrintStudentInfo();
//	Student s2;
//	s2.SetStudentInfo("Alice", "Ů", 19);
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
//	G2.RegisterGoods("���ݽṹ", 8, 9.0);
//	cout << "GetName()= " << G1.GetName() << endl;
//	//G1.SetName("JAVA");
//}

/*
c++��struct��class������
(1) ��Ϊc++��Ҫ��c���ݵģ���c++��struct���Ե����ṹ�壬Ҳ���Ե�����
��2�� �ڵ������ʱ��struct�ĳ�ԱʱĬ�Ϲ����ģ�class��Ĭ��˽�еġ�
��3�� class ��Ϊ��ʱ��Ĭ�ϴ�СΪ1,����Ϳսṹ��Ĵ�С��Ϊ1
*/
//thisָ��ĸ���
//���캯�����������캯������������

/*
1�����캯����
��������������ͬ
�޷���ֵ
����ʵ����ʱ�������Զ����ö�Ӧ�Ĺ��캯��
���캯����������
2���������캯����
�������캯���ǹ��캯����һ��������ʽ
�������캯���Ĳ���ֻ��һ���ұ���ʹ�����ô��Σ�ʹ�ô�ֵ��ʽ����������ݹ����
3������������
������������ǰ���ַ�~
�޲��޷���ֵ
һ��������ֻ��һ����������
�����������ڽ���ʱϵͳ�Զ�����
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
//	Data(int month, int day) : _month(month), _day(day)//���캯��//����ֵ(�Ⱥ������ʼ������Ч�ʸ�)
//	{
//		cout << "Creat this object" << endl;
//	}
//	Data ()
//	{
//		cout << "Creat this object" << endl;
//	}
//	Data(const Data &d)  //Ĭ�ϵĿ������캯����ǳ������ֻ����ֵ�����Ὺ�ٿռ䣬����Ҫ���ٿռ䴫��ʱֻ�ᴫ��ָ��
//	{          //һ���const ϣ������ı䱻���ö���Ĳ���
//		cout << "copy this object" << endl;
//		_month = d._month;
//		_day = d._day;
//	}
//	~Data()  //���������޲��޷���ֵ
//	{
//		cout << "Free this object" << endl;
//	}
//private:
//	int _month;
//	int _day;
//};
//void main()
//{
//	Data d1;  //ͨ���޲ι��캯����������ʱ��������ø����ţ������Ϊ��������
//	Data d2(10, 20);
//	Data d3 = d2;
//}
//�޲ι��캯����ȫȱʡ�Ĺ��캯������Ϊ��Ĭ�Ϲ��캯��

//�������캯�������
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
//		cout << "���" << endl;
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
//	char ar[10] = { 'H','e','l','l','o' };  //֮��/0����
//	cout << strlen(ar) << endl;  // 5
//	cout << sizeof(ar) << endl;  // 10
//}
//void main()
//{
//	char ar[10] = { 'H','e','l','l','o','w','o','r','l','d' };
//	cout << strlen(ar) << endl;  // ���ֵû���ҵ�\0
//	cout << sizeof(ar) << endl;  // 10
//}
//char ar[10];  //ȫ�ֱ����;�̬����Ĭ�ϳ�ʼ��Ϊ0
//void main()
//{
//	static char ar[10];
//	cout << strlen(ar) << endl;  // 0
//	cout << sizeof(ar) << endl;  // 10
//}
//void main()
//{
//	char *ar = "Hellongfalflafl";
//	cout << strlen(ar) << endl;  // 15 �ַ�����ʵ�ʴ�С
//	cout << sizeof(ar) << endl;  // 4
//}

//void main()
//{
//	char ar[10];
//	for (int i = 0; i < 5; ++i)
//	{
//		ar[i] = 'a' + i;   //��Ϊһ��һ������ʱ��δ������ȫ��߲��Ჹ0������������ȫ����ֻҪû\0,�ͻ������ֵ
//	}
//	cout << strlen(ar) << endl;  //    ���ֵ
//	cout << sizeof(ar) << endl;  // 10  
//}

//void main()
//{
//	short* ar1[10][10];  //*�����ȼ�С��[]�����ȼ�������ar1�Ⱥ�[]��ϣ������ar1���վ�������,�����Ԫ����short*��ָ��
//	short(*ar2)[10][10];
//    cout << sizeof(ar1) << endl;  //ָ������ 400
//	cout << sizeof(ar2) << endl;  //����ָ�� 4	
//}
/*��ֵ���������

c++Ϊ����ǿ����Ŀɶ�����������������أ�����������Ǿ������⺯�����ĺ�����Ҳ�����䷵��ֵ���ͣ����������Լ�
�����б��䷵��ֵ����������б�����ͨ�ĺ�������
1����Ϊ���Ա�����غ��������βο������Ȳ�������һ����Ա����Ϊ�ǳ�Ա����������һ��Ĭ�ϵ�thisָ�����������������Ķ���
*/
//class Data
//{
//public:
//	Data()
//	{}  //���캯������
//	Data(int year,int month,int day) :  _day(day), _month(month),_year(year)//����ֵʱֻ�붨�����ʱ(private)��˳���йأ�
//	{
//		cout << "create the data" << endl;
//	}
//	Data(const Data& d)
//	{
//		this->_day=d._day ;//����this��ʾd2�ĵ�ַ
//		_month=d._month ;
//		_year=d._year ;
//	}
//	Data &operator=(const Data& d)
//	{
//		if (this != &d)  //1�����Ҹ�ֵ���  2���ͷŵ�ǰ����ռ� 3�����¿��ٿռ䲢��ֵ 4�����ص�ǰ����
//		{
//			this->_day = d._day;//����this��ʾd2�ĵ�ַ
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
//		cout << "���" << endl;
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
			cout << "��ֵ" << endl;
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
//һ�������Ĭ������6����Ա���� ���� ���� �������� ��ֵ���� 
//����ͨ����ȡ��ַ const����ȡ��ַ(������һ�㲻��Ҫ�������ñ��˻�ȡָ��������)��
#endif