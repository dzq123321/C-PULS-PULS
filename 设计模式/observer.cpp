#if 0
#include<iostream>
#include<list>
using namespace std;
///////////////////�۲��߳��󷽷�
class AbstractHero {
public:
	virtual void Update() = 0;
};

///////////////////����Ĺ۲���
class HeroA :public AbstractHero {
public:
	HeroA() {
		cout << "Ӣ��A���ڴ�boss..." << endl;
	}
	virtual void HeroAUpdate() {
		cout << "Ӣ��Aֹͣ��boss������..." << endl;
	}
};
class People :public AbstractHero {
public:
	People() {
		cout << "ƽ����������..." << endl;
	}
	virtual void Update() {
		cout << "ƽ��ֹͣ���ܣ�����..." << endl;
	}
};
///////////////////���۲��߳��󷽷�
class AbstractBoss {
public:
	AbstractBoss()
	{
		pHeroList = new list<AbstractHero*>;
	}
	//��ӹ۲���
	//֪ͨ�۲���
	virtual void notify() = 0;
	list<AbstractHero*> *pHeroList;
};
//////////////////����ر��۲��� BOSS
class BossA :public AbstractBoss {
public:
	//��ӹ۲���
	virtual void addHero(AbstractHero* hero) {
		pHeroList->push_back(hero);
	}
	//ɾ���۲���
	virtual void deleteHero(AbstractHero* hero) {
		pHeroList->remove(hero);
	}
	//֪ͨ�۲���
	virtual void notify() {
		for (auto e : *pHeroList)
		{
			e->Update();
		}
	}
private:
};

void test() {
	//�����۲���
	AbstractHero* heroA = new HeroA;
	AbstractHero* peopleB = new People;
	//�����۲�Ŀ��
	AbstractBoss* boosA = new BossA;
	boosA->addHero(heroA);
	boosA->addHero(peopleB);
	cout << "heroC����..." << endl;
	boosA->notify();
}
int main()
{
	test();
}
#endif