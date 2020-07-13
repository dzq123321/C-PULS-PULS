#if 0
#include<iostream>
using namespace std;
//////////////��Ʒ�ȼ�
//����ƻ��
class AbstractApple {
public:
	virtual void ShowName() = 0;
};

//�й�ƻ��
class ChineseApple :public AbstractApple {
public:
	virtual void ShowName()
	{
		cout << "�й�ƻ��"<<endl;
	}
};
//����ƻ��
class USAApple :public AbstractApple {
public:
	virtual void ShowName()
	{
		cout << "����ƻ��" << endl;
	}
};
//�ձ�ƻ��
class JapanApple :public AbstractApple {
public:
	virtual void ShowName()
	{
		cout << "�ձ�ƻ��" << endl;
	}
};

//�����㽶
class AbstractBanana {
public:
	virtual void ShowName() = 0;
};

//�й��㽶
class ChineseBanana :public AbstractBanana {
public:
	virtual void ShowName()
	{
		cout << "�й��㽶" << endl;
	}
};
//�����㽶
class USABanana :public AbstractBanana {
public:
	virtual void ShowName()
	{
		cout << "�����㽶" << endl;
	}
};
//�ձ��㽶
class JapanBanana :public AbstractBanana {
public:
	virtual void ShowName()
	{
		cout << "�ձ��㽶" << endl;
	}
};
//����Ѽ��
class AbstractPear {
public:
	virtual void ShowName() = 0;
};

//�й�Ѽ��
class ChinesePear :public AbstractPear {
public:
	virtual void ShowName()
	{
		cout << "�й�Ѽ��" << endl;
	}
};
//����Ѽ��
class USAPear :public AbstractPear {
public:
	virtual void ShowName()
	{
		cout << "����Ѽ��" << endl;
	}
};
//�ձ�Ѽ��
class JapanPear :public AbstractPear {
public:
	virtual void ShowName()
	{
		cout << "�ձ�Ѽ��" << endl;
	}
};
//////���󹤳� ��Բ�Ʒ��
class AbstractFactory {
public:
	virtual AbstractApple* CreateApple() = 0;
	virtual AbstractBanana* CreateBanana() = 0;
	virtual AbstractPear* CreatePear() = 0;
};
//�й�����
class ChineseFactory: public AbstractFactory {
public:
	virtual AbstractApple* CreateApple() {
		return new ChineseApple;
	}
	virtual AbstractBanana* CreateBanana() {
		return new ChineseBanana;
	}
	virtual AbstractPear* CreatePear() {
		return new ChinesePear;
	}
};
//��������
class USAFactory : public AbstractFactory {
public:
	virtual AbstractApple* CreateApple() {
		return new USAApple;
	}
	virtual AbstractBanana* CreateBanana() {
		return new USABanana;
	}
	virtual AbstractPear* CreatePear() {
		return new USAPear;
	}
};
//�ձ�����
class JapanFactory : public AbstractFactory {
public:
	virtual AbstractApple* CreateApple() {
		return new JapanApple;
	}
	virtual AbstractBanana* CreateBanana() {
		return new JapanBanana;
	}
	virtual AbstractPear* CreatePear() {
		return new JapanPear;
	}
};

void test() {
	AbstractFactory* factory = NULL;
	AbstractApple* apple = NULL;
	AbstractBanana* banana = NULL;
	AbstractPear* pear = NULL;
	//�й����������Ĳ�Ʒ
	factory = new ChineseFactory;
	apple = factory->CreateApple();
	banana = factory->CreateBanana();
	pear = factory->CreatePear();
	apple->ShowName();
	banana->ShowName();
	pear->ShowName();

	delete apple;
	delete banana;
	delete pear;
 	delete factory;
}

int main(void) {
	test();
	return 0;
}

#endif