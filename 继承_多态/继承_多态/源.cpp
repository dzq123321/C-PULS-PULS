#if  0

#include<iostream>
#include<string>
using namespace std;
/*
class Person
{
protected:
	string _name; // 姓名
	string _sex; // 性别
	int _age; // 年龄
};
class Student : public Person
{
public:
	int _No; // 学号
};
int main()
{
	Student sobj;
	// 1.子类对象可以赋值给父类对象/指针/引用
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj;
	//2.基类对象不能赋值给派生类对象
	//sobj = pobj;
	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针，但直接赋值是不安全的（可以编译）
	//，必须是是必须是基类的指针是指向派生类对象时才是安全的。
	Person* pp = &sobj;
	Person* p2=new Person;
	Student* ps1 = (Student*)p2; // 这种情况转换是可以的。
	ps1->_No = 10;
	cout<< ps1->_No <<endl;

	pp = &pobj;
	//Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
	//ps2->_No = 10;
	return 0;
}*/
//同名隐藏
// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
/*
class Person
{
protected:
	string _name = "小李子"; // 姓名
	int _num = 111; // 身份证号
};
class Student : public Person
{
public:
	void Print()
	{
		cout << " 姓名:" << _name << endl;
		cout << " 身份证号:" << Person::_num << endl;
		cout << " 学号:" << _num << endl;
	}
	void get()
	{
		cout << "<Person::_num <<  "<<Person::_num << endl;  //加限定符可访问父类同名的变量
		cout << "<Student::_num <<  " << _num << endl;

	}
protected:
	int _num = 999; // 学号
};
void main()
{
	Student s1;
	s1.Print();
	s1.get();
};*/
// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
//先构造A 在构造B 先析构B,在析构A
//同名隐藏，只要函数名一样就会隐藏


class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
	void fun()
	{
		cout << "A::func()" << endl;
	}
	~A() { cout << "~A" << endl; }
};
class B : public A
{
public:
	B()
	{
		cout << "B()" << endl;
	}
	void fun()
	{
		cout << "B::func()" << endl;
	}
	int fun(int i)
	{
		A::fun();
		cout << "func(int i)->" << i << endl;
		return 0;
	}
	~B() {
		cout << "~B" << endl;
	}
};
void main()
{
	B b;
	b.fun();
};


//友元关系不能继承，也就是说基类友元不能访问子类私有和保护成员
/*
class Student;
class Person
{
public:
	friend void Display(const Person& p, const Student& s);
	friend  Student;
protected:
	string _name; // 姓名
};
class Student : public Person
{
	friend  Person;
protected:
	int _stuNum; // 学号
};
void Display(const Person& p, const Student& s)
{
	cout << p._name << endl;
	cout << s._stuNum << endl;
}
void main()
{
	Person p;
	Student s;
	Display(p, s);
}
*/
//基类定义了static静态成员，则整个继承体系里面只有一个这样的成员。无论派生出多少个子类，都只有一个static成员实例 。
/*
class Person
{
public:
	Person() { ++_count; }
protected:
	string _name; // 姓名
public:
	static int _count; // 统计人的个数。
};
int Person::_count = 0;
class Student : public Person
{
protected:
	int _stuNum; // 学号
};
class Graduate : public Student
{
protected:
	string _seminarCourse; // 研究科目
};
void main()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " 人数 :" << Person::_count << endl;//4
	Student::_count = 0;
	cout << " 人数 :" << Person::_count << endl;//0
}*/
/*
class Person
{
public:
	string _name; // 姓名
};
class Student : public Person
{
protected:
	int _num; //学号
};
class Teacher : public Person
{
protected:
	int _id; // 职工编号
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // 主修课程
};
void main()
{
	// 这样会有二义性无法明确知道访问的是哪一个
	Assistant a;
	//a._name = "peter";  错误
	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
	a.Student::_name = "xxx";
	a.Teacher::_name = "yyy";
	cout << a.Student::_name << endl;//xxx
	cout << a.Teacher::_name << endl;//yyy
}*/
//虚拟继承可以解决菱形继承的二义性和数据冗余的问题。如上面的继承关系，在Student和Teacher的继承
//Person时使用虚拟继承，即可解决问题。需要注意的是，虚拟继承不要在其他地方去使用。
/*
class Person
{
public:
	string _name; // 姓名
};
class Student : virtual public Person
{
protected:
	int _num; //学号
};
class Teacher : virtual public Person
{
protected:
	int _id; // 职工编号
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // 主修课程
};
void main()
{
	Assistant a;
	
	a.Student::_name = "xxx";
	a.Teacher::_name = "yyy";
	a._name = "peter";
	cout << a.Student::_name << endl;//xxx
	cout << a.Teacher::_name << endl;//yyy
	cout << a._name << endl;//xxx
}

*/


#endif
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