#if 1
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<windows.h>
#include<stdlib.h>
using namespace std;

//协议处理类
class  HandleClientProtocol {
public:
	//增加金币
	void AddMoney()
	{
		cout << "给玩家增加金币"<<endl;
	}
	//增加钻石
	void AddDiamond()
	{
		cout << "给玩家增加钻石" << endl;
	}
	//升级
	void Update()
	{
		cout << "给玩家升级" << endl;
	}
};
//协议命令接口
class AbstractCommand{
public:
	virtual void handle() = 0;
};

//增加金币请求
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

//增加钻石请求
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

//增加升级
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

//服务器程序  命令不一定及时处理，将请求加到队列
//函数不能增加到队列中，可以是对象
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
	//增加金币请求
	AbstractCommand* addmoney = new AddMoneyCommand(protocol);
	//增加钻石请求
	AbstractCommand* adddiamond = new AddDiamondCommand(protocol);
	//增加升级请求
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