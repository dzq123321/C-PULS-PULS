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
	int a;        //8�ֽڶ���
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
	test6 t6;//������Ľṹ�������Ϊ40 ��������Ϊ8 �������Ϊ����������һ���ṹ�����ʱ
	cout << sizeof(t6) << endl;  //����ֻ��struct()Ϊ40���������Ϊ8
	test t1;
	cout << sizeof(t1) << endl;  //1
	test2 t2;
	cout << sizeof(t2) << endl;  //1
	test3 t3;
	cout << sizeof(t3) << endl;  //1
	test4 t4;
	cout << sizeof(t4) << endl; //8
}
//NULL ��nullptr (c++����ʹ��nullptr,���Է�ֹ�������غ���������)
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
//	f(NULL);  //����f(NULL)�������f(int*)�ģ������ó���f(int)  cĬ��NULL Ϊ�궨��0
//	f((int*)NULL); //ǿ������ת��Ϊint*	
//	//ʹ��nullptr�����������  nullptr�������͵ģ�Ϊnullptr_t����
//	cout << typeid(nullptr).name() << endl;
//	f(nullptr);
//    return 0;
//}



//auto ��1��  �����ʼ��  (2)  ������Ϊ�β�  ��3������ֱ����������
//int main()
//{
//	int a = 3;
//	auto b = &a;  //����Ŀ����ʱ����ĳ����������˼ʱ������ֱ����auto���棬�༭��������Ƶ���auto��ʵ�ʺ���
//    auto *c= &a;    //auto*��autoû���κ�����
//	cout << typeid(b).name() << endl;//typeid(b).name()���������������
//	cout << typeid(c).name() << endl;
//	decltype(a) d ;   //����� int d ��Ϊauto�������ʱ���������г�ʼ�������Ե�����ֻ�趨��һ����
//	cout << typeid(d).name() << endl;  //aһ���ı���(��֪��a������)���ֲ����ʼ��ʱ�����ùؼ���decltype
//	auto &p = a;    //auto��������ʱ�����&
//	cout << "&a=" << &a << endl;
//	cout << "&p=" << &p << endl;
//	cout << typeid(p).name() << endl;
//
//}

//����������inline�� �ռ任ʱ�䣨�����������ѭ��/�ݹ�ʱ���ʺϣ�
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
//����    const�������÷�const    ��const ��������const
//int main()  //�������﷨����һ��������û�ж����ռ䣬������ʵ�幫��һ��ռ䡣���ڵײ�ʵ��ʱʵ�������пռ�ģ���Ϊ�����ǰ���
//{                       //ָ����ʽʵ�ֵ�
//	int a = 8;
//	const int& b = a;
//	cout << "b=" << b << endl;
//	const int c = 9;
//	int& d = c;    ������Ϊ�����ᵼ��d���޸�c��ֵ�����õ�ʱ���ܱ�����Ȩ������ԭ����Ȩ��
//	int p[10] = { 0 };
//	int(&q)[10] = p;  //���������
//	for (auto ele : q)
//		cout << ele << " ";   //c++��forѭ���ĸĽ�
//	for (auto& ele : q)
//		ele+=1 ;   //�����ı������ֵ�Ļ�����������
//	cout << endl;
//	for (auto ele : q)
//		cout << ele << " ";
//}

/*this ָ��
c++Ϊÿ����Ա��������һ��������thisָ��
1��thisָ�������� ������* const
2��ֻ���ڳ�Ա�����в���
3��thisָ�뱾������һ����Ա�������β����Ƕ�����ó�Ա����ʱ��������ĵ�ַ��Ϊʵ�δ��ݸ�this�βΣ����Զ�����
���洢thisָ��
4��this ָ���ǳ�Ա������һ��������ָ���βΣ�һ������ɱ�����ͨ��ecx�Ĵ����Զ����ݣ�����Ҫ�û�����
*/
// ��Ҫע�����thisָ���Ǵ����ecx(vs vc)�Ĵ�����     thisָ�����Ϊ��(��Ա�����ڲ�����Ҫthisָ��ʱ������ֻ�Ǵ�ӡһ���޹�ֵ)
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
////	p->Show();  // ����
//}


























#endif
