#if  0

#include<iostream>
#include<string>
using namespace std;
/*
class Person
{
protected:
	string _name; // ����
	string _sex; // �Ա�
	int _age; // ����
};
class Student : public Person
{
public:
	int _No; // ѧ��
};
int main()
{
	Student sobj;
	// 1.���������Ը�ֵ���������/ָ��/����
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj;
	//2.��������ܸ�ֵ�����������
	//sobj = pobj;
	// 3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ�룬��ֱ�Ӹ�ֵ�ǲ���ȫ�ģ����Ա��룩
	//���������Ǳ����ǻ����ָ����ָ�����������ʱ���ǰ�ȫ�ġ�
	Person* pp = &sobj;
	Person* p2=new Person;
	Student* ps1 = (Student*)p2; // �������ת���ǿ��Եġ�
	ps1->_No = 10;
	cout<< ps1->_No <<endl;

	pp = &pobj;
	//Student* ps2 = (Student*)pp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
	//ps2->_No = 10;
	return 0;
}*/
//ͬ������
// Student��_num��Person��_num�������ع�ϵ�����Կ�������������Ȼ���ܣ����Ƿǳ����׻���
/*
class Person
{
protected:
	string _name = "С����"; // ����
	int _num = 111; // ���֤��
};
class Student : public Person
{
public:
	void Print()
	{
		cout << " ����:" << _name << endl;
		cout << " ���֤��:" << Person::_num << endl;
		cout << " ѧ��:" << _num << endl;
	}
	void get()
	{
		cout << "<Person::_num <<  "<<Person::_num << endl;  //���޶����ɷ��ʸ���ͬ���ı���
		cout << "<Student::_num <<  " << _num << endl;

	}
protected:
	int _num = 999; // ѧ��
};
void main()
{
	Student s1;
	s1.Print();
	s1.get();
};*/
// B�е�fun��A�е�fun���ǹ������أ���Ϊ������ͬһ������
// B�е�fun��A�е�fun�������أ���Ա�������㺯������ͬ�͹������ء�
//�ȹ���A �ڹ���B ������B,������A
//ͬ�����أ�ֻҪ������һ���ͻ�����


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


//��Ԫ��ϵ���ܼ̳У�Ҳ����˵������Ԫ���ܷ�������˽�кͱ�����Ա
/*
class Student;
class Person
{
public:
	friend void Display(const Person& p, const Student& s);
	friend  Student;
protected:
	string _name; // ����
};
class Student : public Person
{
	friend  Person;
protected:
	int _stuNum; // ѧ��
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
//���ඨ����static��̬��Ա���������̳���ϵ����ֻ��һ�������ĳ�Ա���������������ٸ����࣬��ֻ��һ��static��Աʵ�� ��
/*
class Person
{
public:
	Person() { ++_count; }
protected:
	string _name; // ����
public:
	static int _count; // ͳ���˵ĸ�����
};
int Person::_count = 0;
class Student : public Person
{
protected:
	int _stuNum; // ѧ��
};
class Graduate : public Student
{
protected:
	string _seminarCourse; // �о���Ŀ
};
void main()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " ���� :" << Person::_count << endl;//4
	Student::_count = 0;
	cout << " ���� :" << Person::_count << endl;//0
}*/
/*
class Person
{
public:
	string _name; // ����
};
class Student : public Person
{
protected:
	int _num; //ѧ��
};
class Teacher : public Person
{
protected:
	int _id; // ְ�����
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // ���޿γ�
};
void main()
{
	// �������ж������޷���ȷ֪�����ʵ�����һ��
	Assistant a;
	//a._name = "peter";  ����
	// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
	a.Student::_name = "xxx";
	a.Teacher::_name = "yyy";
	cout << a.Student::_name << endl;//xxx
	cout << a.Teacher::_name << endl;//yyy
}*/
//����̳п��Խ�����μ̳еĶ����Ժ�������������⡣������ļ̳й�ϵ����Student��Teacher�ļ̳�
//Personʱʹ������̳У����ɽ�����⡣��Ҫע����ǣ�����̳в�Ҫ�������ط�ȥʹ�á�
/*
class Person
{
public:
	string _name; // ����
};
class Student : virtual public Person
{
protected:
	int _num; //ѧ��
};
class Teacher : virtual public Person
{
protected:
	int _id; // ְ�����
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // ���޿γ�
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
	pb->show();     // pb->fun ��Զ�����ܵ�������ķ���
				   // ��è��̫��
}
*/