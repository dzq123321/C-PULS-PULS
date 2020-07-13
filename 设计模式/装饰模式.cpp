#if 0
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//英雄  ---add装饰物
//通过继承实现类的功能的扩展
//抽象英雄
class AbstractHero {
public:
	virtual void ShowStatus() = 0;
public:
	int mHp;
	int mMp;
	int mAt;
	int mDf;
};

//具体英雄
class HeroA :public AbstractHero
{
public:
	HeroA()
	{
		mHp=0;
		mMp=0;
		mAt=0;
		mDf=0;
	}
	virtual void ShowStatus()
	{
		cout << "血量： " << mHp << endl;
		cout << "魔法： " << mMp << endl;
		cout << "攻击： " << mAt << endl;
		cout << "防御： " << mDf << endl;
	}
};

//英雄穿上某个装饰物，那么他还是英雄，但不是原来的英雄

class AbstractEquipment :public AbstractHero {
public:
	AbstractEquipment(AbstractHero* hero) {
		this->pHero = hero;
	}
	virtual void ShowStatus() {}
public:
	AbstractHero* pHero;
};

//狂徒
class KuangTuEquipment :public AbstractEquipment {
public:
	KuangTuEquipment(AbstractHero* hero) :AbstractEquipment(hero) {}
	//增加额外功能
	void AddKuangTu() {
		cout << "装备完成...." << endl;
		mHp = pHero->mHp+  80;
		mMp = pHero->mMp;
		mAt = pHero->mAt;
		mDf = pHero->mDf + 20;
		delete this->pHero;
	}
	virtual void ShowStatus() {
		AddKuangTu();
		cout << "血量： " << mHp << endl;
		cout << "魔法： " << mMp << endl;
		cout << "攻击： " << mAt << endl;
		cout << "防御： " << mDf << endl;
	}
};

void test()
{
	AbstractHero* hero = new HeroA;
	hero->ShowStatus();

	cout << "----------" << endl;
	//装备狂徒
	hero = new KuangTuEquipment(hero);
	hero->ShowStatus();
}
int main()
{
	test();
}
#endif