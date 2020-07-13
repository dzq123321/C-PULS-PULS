#if 0
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//Ӣ��  ---addװ����
//ͨ���̳�ʵ����Ĺ��ܵ���չ
//����Ӣ��
class AbstractHero {
public:
	virtual void ShowStatus() = 0;
public:
	int mHp;
	int mMp;
	int mAt;
	int mDf;
};

//����Ӣ��
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
		cout << "Ѫ���� " << mHp << endl;
		cout << "ħ���� " << mMp << endl;
		cout << "������ " << mAt << endl;
		cout << "������ " << mDf << endl;
	}
};

//Ӣ�۴���ĳ��װ�����ô������Ӣ�ۣ�������ԭ����Ӣ��

class AbstractEquipment :public AbstractHero {
public:
	AbstractEquipment(AbstractHero* hero) {
		this->pHero = hero;
	}
	virtual void ShowStatus() {}
public:
	AbstractHero* pHero;
};

//��ͽ
class KuangTuEquipment :public AbstractEquipment {
public:
	KuangTuEquipment(AbstractHero* hero) :AbstractEquipment(hero) {}
	//���Ӷ��⹦��
	void AddKuangTu() {
		cout << "װ�����...." << endl;
		mHp = pHero->mHp+  80;
		mMp = pHero->mMp;
		mAt = pHero->mAt;
		mDf = pHero->mDf + 20;
		delete this->pHero;
	}
	virtual void ShowStatus() {
		AddKuangTu();
		cout << "Ѫ���� " << mHp << endl;
		cout << "ħ���� " << mMp << endl;
		cout << "������ " << mAt << endl;
		cout << "������ " << mDf << endl;
	}
};

void test()
{
	AbstractHero* hero = new HeroA;
	hero->ShowStatus();

	cout << "----------" << endl;
	//װ����ͽ
	hero = new KuangTuEquipment(hero);
	hero->ShowStatus();
}
int main()
{
	test();
}
#endif