#if 1
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<windows.h>
#include<stdlib.h>
using namespace std;

//Э�鴦����
class  HandleClientProtocol {
public:
	//���ӽ��
	void AddMoney()
	{
		cout << "��������ӽ��"<<endl;
	}
	//������ʯ
	void AddDiamond()
	{
		cout << "�����������ʯ" << endl;
	}
	//����
	void Update()
	{
		cout << "���������" << endl;
	}
};
//Э������ӿ�
class AbstractCommand{
public:
	virtual void handle() = 0;
};

//���ӽ������
class AddMoneyCommand :public AbstractCommand{
public:
	AddMoneyCommand(HandleClientProtocol* Protocol)
	{
		pProtocol = Protocol;
	}
	virtual void handle()
	{
		this->pProtocol->AddMoney();
	}
public:
	HandleClientProtocol* pProtocol;
};

//������ʯ����
class AddDiamondCommand :public AbstractCommand {
public:
	AddDiamondCommand(HandleClientProtocol* Protocol)
	{
		pProtocol = Protocol;
	}
	virtual void handle()
	{
		this->pProtocol->AddDiamond();
	}
public:
	HandleClientProtocol* pProtocol;
};

//��������
class AddUpdateCommand :public AbstractCommand {
public:
	AddUpdateCommand(HandleClientProtocol* Protocol)
	{
		pProtocol = Protocol;
	}
	virtual void handle()
	{
		this->pProtocol->Update();
	}
public:
	HandleClientProtocol* pProtocol;
};

//����������  ���һ����ʱ����������ӵ�����
//�����������ӵ������У������Ƕ���
class Server {
public:
	void addRequest(AbstractCommand* command)
	{
		mCommands.push(command);
	}
	void startHandle()
	{
		while (!mCommands.empty()) {
			Sleep(1000);
			AbstractCommand* command = mCommands.front();
			command->handle();
			mCommands.pop();
		}
	}
public:
	queue<AbstractCommand*> mCommands;
};
void test()
{
	HandleClientProtocol* protocol = new HandleClientProtocol;
	//���ӽ������
	AbstractCommand* addmoney = new AddMoneyCommand(protocol);
	//������ʯ����
	AbstractCommand* adddiamond = new AddDiamondCommand(protocol);
	//������������
	AbstractCommand* addupdate= new AddUpdateCommand(protocol);

	Server* svr = new Server;
	svr->addRequest(addmoney);
	svr->addRequest(adddiamond);
	svr->addRequest(addupdate);

	svr->startHandle();

}
int main()
{
	test();
	return 0;
}

#endif