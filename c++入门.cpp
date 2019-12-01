#if 0
#include<iostream>
using namespace std;
struct test
{

};
class test2
{};
class test3
{
public:
	void f2() {}
};
class test4
{
public:
	void f1() {}
private:
	int _data;
	int _data2;
};
typedef struct test5
{
	int a;
	struct temp
	{
		short b;
		double c;
		char d;
	} tt;
	long e;
}test5;
typedef struct test6
{
	int a;        //8字节对齐
	short b;
	double c;
	char d;
	long e;
}test6;
typedef struct test7
{
	int a;  //4
	short b;	//2
	double c; //8
	char d;  //1
}test7;
int main()
{
	test7 t7;
	cout << sizeof(t7) << endl;  //24
	test6 t6;//当里面的结构体加名字为40 不加名字为8 可以理解为完整定义了一个结构体对象时
	cout << sizeof(t6) << endl;  //或者只是struct()为40，其余情况为8
	test t1;
	cout << sizeof(t1) << endl;  //1
	test2 t2;
	cout << sizeof(t2) << endl;  //1
	test3 t3;
	cout << sizeof(t3) << endl;  //1
	test4 t4;
	cout << sizeof(t4) << endl; //8
}
//NULL 和nullptr (c++建议使用nullptr,可以防止调用重载函数的歧义)
//void f(int)
//{
//	cout << "int" << endl;
//}
//void f(int*)
//{
//	cout << "int*" << endl;
//}
//void f(nullptr_t)
//{
//	cout << "nullptr_t" << endl;
//}
//int main()
//{
//	f(0);
//	f(NULL);  //本来f(NULL)是想调用f(int*)的，但调用成了f(int)  c默认NULL 为宏定义0
//	f((int*)NULL); //强制类型转换为int*	
//	//使用nullptr不会产生歧义  nullptr是有类型的，为nullptr_t类型
//	cout << typeid(nullptr).name() << endl;
//	f(nullptr);
//    return 0;
//}



//auto （1）  必须初始化  (2)  不能作为形参  （3）不能直接声明数组
//int main()
//{
//	int a = 3;
//	auto b = &a;  //当项目过大时忘记某个变量的意思时，可以直接用auto代替，编辑器会给你推导出auto的实际含义
//    auto *c= &a;    //auto*和auto没有任何区别
//	cout << typeid(b).name() << endl;//typeid(b).name()是求变量的类型名
//	cout << typeid(c).name() << endl;
//	decltype(a) d ;   //相等于 int d 因为auto定义变量时必须对其进行初始化，所以当我们只需定义一个和
//	cout << typeid(d).name() << endl;  //a一样的变量(不知道a的类型)但又不想初始化时可以用关键字decltype
//	auto &p = a;    //auto声明引用时必须加&
//	cout << "&a=" << &a << endl;
//	cout << "&p=" << &p << endl;
//	cout << typeid(p).name() << endl;
//
//}

//内联函数（inline） 空间换时间（代码过长或有循环/递归时不适合）
//inline int Add(int left, int right)
//{
//	return left + right;
//}
//int main()
//{
//	int ret = 0;
//	ret = Add(1, 2);
//	return 0;
//}
//void main()
//{
//	int ar[5] = { 1,2,3,4,5 };
//	int(&br)[5] = ar; //3
//	int(*par)[5] = &ar;
//	cout << sizeof(br) << endl;  //20
//	cout << sizeof(par) << endl;  //4
//}
//引用    const可以引用非const    非const 不能引用const
//int main()  //引用在语法上是一个别名，没有独立空间，和其他实体公用一块空间。但在底层实现时实际上是有空间的，因为引用是按照
//{                       //指针形式实现的
//	int a = 8;
//	const int& b = a;
//	cout << "b=" << b << endl;
//	const int c = 9;
//	int& d = c;    错误，因为这样会导致d会修改c的值，引用的时候不能别名的权利大于原来的权力
//	int p[10] = { 0 };
//	int(&q)[10] = p;  //数组的引用
//	for (auto ele : q)
//		cout << ele << " ";   //c++中for循环的改进
//	for (auto& ele : q)
//		ele+=1 ;   //如果想改变数组的值的话必须引用他
//	cout << endl;
//	for (auto ele : q)
//		cout << ele << " ";
//}

/*this 指针
c++为每个成员函数增加一个隐含的this指针
1、this指针类型是 类类型* const
2、只会在成员函数中产生
3、this指针本质上是一个成员函数的形参吗，是对象调用成员函数时，将对象的地址作为实参传递给this形参，所以对象中
不存储this指针
4、this 指针是成员函数第一个隐含的指针形参，一般情况由编译器通过ecx寄存器自动传递，不需要用户传递
*/
// 需要注意的是this指针是存放在ecx(vs vc)寄存器上     this指针可以为空(成员函数内部不需要this指针时，例如只是打印一个无关值)
//class Test
//{
//public:
//	Test():_mdata (0)
//	{}
//	void Print()
//	{
//		cout << "this=nullptr" << endl;
//	}
//	void Show()
//	{
//		cout << _mdata << endl;
//	}
//private:
//	int _mdata;
//};
//void main()
//{
//	Test t1;
//	t1.Print();
//	t1.Show();
//	Test *p = nullptr;
//	p->Print();
////	p->Show();  // 错误
//}


























#endif
