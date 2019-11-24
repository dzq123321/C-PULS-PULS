#if 0
#include<iostream>
using namespace std;
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











#endif
