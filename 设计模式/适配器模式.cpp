#if 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
��һ����Ľӿ�ת��Ϊ�ͻ�ϣ������һ���ӿڣ�ʹ��ԭ�����ڽӿڲ�����
��������һ��������Щ�����һ����
*/

//������Ҫ����ķº���
class MyPrint {
public:
	void operator()(int v1, int v2){
		cout << v1 + v2 << endl;
	}
};

//Ҫ�����ʲô����
class Target {
public:
	virtual void operator()(int v) = 0;
};
//����Ŀ��ӿڣ����������������ķº���MyPrintת��Ϊһ������

class Adapter :public Target {
public:
	Adapter(int v) :_para(v)
	{}
	virtual void operator()(int v) {
		print(v, _para);
	}
public:
	MyPrint print;
	int _para;
};
//Mybind
Adapter Mybind(int v)
{
	return Adapter(v);
}
int main()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	for_each(v.begin(), v.end(), Mybind(10));
}
#endif