#if 0
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*
����ģʽ���壺Ϊ���������ṩһ�ִ����Կ��ƶ��������ķ��ʣ���ĳЩ����£�һ�������ʺϻ��߲���ֱ��������һ������
�������������ڿͻ��˺�Ŀ�����֮�����н����á�
�������Ǽ���ͻ��˲���ֱ�ӷ���ϵͳ��ֻ��ͨ����������֤��������֮����ܷ���
*/

//�ṩһ�ִ��������ƶ���������ķ���
class AbstractCommonInterface {
public:
	virtual void run() = 0;
};
//��Ҫ���ʵ�ϵͳ  -->�����ϵͳ�����㿪��ԭ��
class MySystem :public AbstractCommonInterface {
public:
	virtual void run() {
		cout << "ϵͳ����..." << endl;
	}
};
//���д�����֤��ݺ�����
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
			cout << "��¼�ɹ�"<<endl;
		}
		else
		{
			cout << "�������" << endl;
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