#if 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
将一个类的接口转换为客户希望的另一个接口，使得原本由于接口不兼容
而不能在一起工作的那些类可以一起工作
*/

//本来需要传入的仿函数
class MyPrint {
public:
	void operator()(int v1, int v2){
		cout << v1 + v2 << endl;
	}
};

//要适配成什么样子
class Target {
public:
	virtual void operator()(int v) = 0;
};
//定义目标接口，将接收两个参数的仿函数MyPrint转换为一个参数

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