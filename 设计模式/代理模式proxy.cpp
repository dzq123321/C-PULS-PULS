#if 0
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*
代理模式定义：为其他对象提供一种代理以控制对这个对象的访问，在某些情况下，一个对象不适合或者不能直接引用另一个对象，
而代理对象可以在客户端和目标对象之间起到中介作用。
这里我们假设客户端不能直接访问系统，只能通过代理，在验证密码和身份之后才能访问
*/

//提供一种代理来控制对其他对象的访问
class AbstractCommonInterface {
public:
	virtual void run() = 0;
};
//需要访问的系统  -->抽象出系统，满足开闭原则
class MySystem :public AbstractCommonInterface {
public:
	virtual void run() {
		cout << "系统启动..." << endl;
	}
};
//进行代理，验证身份和密码
class MySystemProxy :public AbstractCommonInterface {
public:
	MySystemProxy(string name, string password) {
		m_name = name;
		m_password = password;
		pSystem = new MySystem;
	}
	virtual void run() {
		if (check())
		{
			pSystem->run();
			cout << "登录成功"<<endl;
		}
		else
		{
			cout << "密码错误" << endl;
		}
	}
	~MySystemProxy()
	{
		if (pSystem)
			delete pSystem;
	}
protected:
	bool check()
	{
		if (m_name == "123"&&m_password == "456")
			return true;
		return false;
	}
private:
	MySystem* pSystem;
	string m_name;
	string m_password;
};

void main()
{
	MySystemProxy* proxy = new MySystemProxy("123", "458");
	proxy->run();
}


#endif