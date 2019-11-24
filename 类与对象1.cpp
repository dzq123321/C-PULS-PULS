#if 1
#include<iostream>
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
*/












#endif