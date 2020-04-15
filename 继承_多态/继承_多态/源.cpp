
/*
class Base
{
public:
	virtual void fun()
	{
		cout<<"Base::fun()"<<endl;
	}
public:
	virtual Base* show()
	{
		cout<<"Base::show()"<<endl;
		return this;
	}
};

class D : public Base
{
public:
	virtual void fun()
	{
		cout<<"D::fun()"<<endl;
	}
public:
	virtual D* show()  //
	{
		cout<<"D::show()"<<endl;
		return this;
	}
};
void main()
{
	D d;
	Base *pb = &d;
	pb->show();     // pb->fun 永远都不能调动子类的方法
				   // 狸猫换太子
}
*/