#if 0
#include<iostream>
using namespace std;
//////////////产品等级
//抽象苹果
class AbstractApple {
public:
	virtual void ShowName() = 0;
};

//中国苹果
class ChineseApple :public AbstractApple {
public:
	virtual void ShowName()
	{
		cout << "中国苹果"<<endl;
	}
};
//美国苹果
class USAApple :public AbstractApple {
public:
	virtual void ShowName()
	{
		cout << "美国苹果" << endl;
	}
};
//日本苹果
class JapanApple :public AbstractApple {
public:
	virtual void ShowName()
	{
		cout << "日本苹果" << endl;
	}
};

//抽象香蕉
class AbstractBanana {
public:
	virtual void ShowName() = 0;
};

//中国香蕉
class ChineseBanana :public AbstractBanana {
public:
	virtual void ShowName()
	{
		cout << "中国香蕉" << endl;
	}
};
//美国香蕉
class USABanana :public AbstractBanana {
public:
	virtual void ShowName()
	{
		cout << "美国香蕉" << endl;
	}
};
//日本香蕉
class JapanBanana :public AbstractBanana {
public:
	virtual void ShowName()
	{
		cout << "日本香蕉" << endl;
	}
};
//抽象鸭梨
class AbstractPear {
public:
	virtual void ShowName() = 0;
};

//中国鸭梨
class ChinesePear :public AbstractPear {
public:
	virtual void ShowName()
	{
		cout << "中国鸭梨" << endl;
	}
};
//美国鸭梨
class USAPear :public AbstractPear {
public:
	virtual void ShowName()
	{
		cout << "美国鸭梨" << endl;
	}
};
//日本鸭梨
class JapanPear :public AbstractPear {
public:
	virtual void ShowName()
	{
		cout << "日本鸭梨" << endl;
	}
};
//////抽象工厂 针对产品族
class AbstractFactory {
public:
	virtual AbstractApple* CreateApple() = 0;
	virtual AbstractBanana* CreateBanana() = 0;
	virtual AbstractPear* CreatePear() = 0;
};
//中国工厂
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
//美国工厂
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
//日本工厂
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
	//中国工厂生产的产品
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