#if 0
#include<iostream>
using namespace std;
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











#endif
