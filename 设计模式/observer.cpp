#if 0
#include<iostream>
#include<list>
using namespace std;
///////////////////观察者抽象方法
class AbstractHero {
public:
	virtual void Update() = 0;
};

///////////////////具体的观察者
class HeroA :public AbstractHero {
public:
	HeroA() {
		cout << "英雄A正在打boss..." << endl;
	}
	virtual void HeroAUpdate() {
		cout << "英雄A停止打boss，待机..." << endl;
	}
};
class People :public AbstractHero {
public:
	People() {
		cout << "平民正在逃跑..." << endl;
	}
	virtual void Update() {
		cout << "平民停止逃跑，待机..." << endl;
	}
};
///////////////////被观察者抽象方法
class AbstractBoss {
public:
	AbstractBoss()
	{
		pHeroList = new list<AbstractHero*>;
	}
	//添加观察者
	//通知观察者
	virtual void notify() = 0;
	list<AbstractHero*> *pHeroList;
};
//////////////////具体地被观察者 BOSS
class BossA :public AbstractBoss {
public:
	//添加观察者
	virtual void addHero(AbstractHero* hero) {
		pHeroList->push_back(hero);
	}
	//删除观察者
	virtual void deleteHero(AbstractHero* hero) {
		pHeroList->remove(hero);
	}
	//通知观察者
	virtual void notify() {
		for (auto e : *pHeroList)
		{
			e->Update();
		}
	}
private:
};

void test() {
	//创建观察者
	AbstractHero* heroA = new HeroA;
	AbstractHero* peopleB = new People;
	//创建观察目标
	AbstractBoss* boosA = new BossA;
	boosA->addHero(heroA);
	boosA->addHero(peopleB);
	cout << "heroC阵亡..." << endl;
	boosA->notify();
}
int main()
{
	test();
}
#endif