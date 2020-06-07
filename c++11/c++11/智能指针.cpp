#if 1
#include<iostream>
#include<string>
#include<memory>
using namespace std;


/*
double Division(int a, int b)
{
	// ��b == 0ʱ�׳��쳣
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}
void Func()
{
	// ������Կ������������0�����׳��쳣�����������arrayû�еõ��ͷš�
	// �������ﲶ���쳣�󲢲������쳣���쳣���ǽ������洦�����ﲶ������
	// �����׳�ȥ��
	int* array = new int[10];
	try {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)
	{
		cout << "delete1 []" << array << endl;
		delete[] array;
		throw;
	}

	cout << "delete2 []" << array << endl;
	delete[] array;
}
int main()
{
	try
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	return 0;
}
*/


/*
class Exception
{
public:
	virtual void What() = 0;

public:
	string _errmsg = "Have a Exception.";
};
class SqlException : public Exception

{
public:
	virtual void What()
	{
		cout << "SqlException Exception" << endl;
	}
};

class CacheException : public Exception
{
public:
	virtual void What()
	{
		cout << "CacheException Exception" << endl;
	}
};

class HttpServerException : public Exception
{
public:
	virtual void What()
	{
		cout << "HttpServerException Exception" << endl;
	}
};

void Startup()
{

	//throw SqlException();	
	throw HttpServerException();
}
int main()
{
	try
	{
		Startup();
	}
	catch (Exception& e)
	{
		e.What(); //��̬
	}
	catch (...)
	{
		cout << "Unkown Exception" << endl;
	}
	return 0;

}
*/
//RAII ��Դ��ȡ����ʼ��  �Զ�
/*
void main()
{
	int  *tmp = new int(100);
	auto_ptr<int> ap(tmp); //����ָ��ap�ӹ�tmp��ap��ʵ��һ���������������ڶ�����������������Ҫ�û�����
	cout << *ap << endl;
	auto_ptr<string> ap1(new string("hello world!"));
	cout << ap1->size() << endl;

	ap1.reset(new string("good "));  //��������ap1����Ķ���
	cout << ap1->size() << endl;
	ap1.release();  //�ͷ�ָ��Ķ���ĵؿռ䣨vs c++11��/�ͷ�ָ����������Ȩ��vc c++98��
	auto_ptr<string>ap2 (new string ("bad"));
	ap1 = ap2;
	cout << *ap1 << endl;

}*/

//VC Դ��ģ��  ���й���Ȩ
/*
template<class _Ty>
class my_auto_ptr
{
public:
	my_auto_ptr(_Ty *_P = 0) : _Owns(_P != 0), _Ptr(_P)//��_P != 0ʱ��_Owns=1��_Ptr=_P
	{}
	my_auto_ptr(const my_auto_ptr<_Ty> &_Y) : _Owns(_Y._Owns), _Ptr(_Y.release())
	{}
	my_auto_ptr<_Ty>& operator =(const  my_auto_ptr<_Ty>& _Y)
	{
		if (this != &_Y)
		{
		  if (_Ptr != _Y.get())  //
			{
				if (_Owns)  //��ԭ���ɿռ�ʱ��Ҫɾ��ԭ�пռ�
					delete _Ptr;
				_Owns = _Y._Owns;
			}
			else if (_Y._Owns)   //���_Y._OwnsΪflase���򲻸ı�_Owns������Ȩ
				_Owns = true;
			_Ptr = _Y.release();//ɾ��ԭ�еĹ���Ȩ����ֵ��_Ptr
		}
		return (*this);
	}
	~my_auto_ptr()
	{
		if (_Owns)
			delete _Ptr;
	}
public:
	_Ty& operator*()const
	{
		return *_Ptr;
	}
	_Ty* operator->()const
	{
		return _Ptr;
	}
public:
	_Ty* release()const  //ɾ������ָ�룬������Ȩ��Ϊfalse
	{
		//_Owns = false; ���У��ǳ��������������ǿ������ת��   ����ʹ�� mutable�ؼ���
		//*((bool*)&_Owns) = false;  //Ҫôֱ�ӽ�const bool����ǿתΪbool����
		((my_auto_ptr<_Ty>*)this)->_Owns = false;  //Ҫôֱ�ӽ�const (my_auto_ptr<_Ty>*)this����ǿתΪ(my_auto_ptr<_Ty>*) this����         ǿ��ת�� ��������
		return _Ptr;
	}
	_Ty* get()const
	{
		return _Ptr;
	}
private:
	bool _Owns;//����Ȩ
	_Ty *_Ptr;  //ָ������ַ��ָ��
};
void main()
{
	int *p = new int(10);
	int *q = new int(20);
	my_auto_ptr<int> ap1(p);
	ap1.release();
	my_auto_ptr<int> ap2(p);
	ap2 = ap1;
}
/*
void main()
{
	int *p = new int(10);
	my_auto_ptr<int> ap(p);
	cout << *ap << endl;
	my_auto_ptr<int> ap1 = ap;
	my_auto_ptr<int> ap2;
	ap2 = ap1;
}*/
/*
void main()
{
	int *p = new int(10);
	int *q = new int(20);
	my_auto_ptr<int> ap1(p);
	my_auto_ptr<int> ap2(q);
	cout << *ap2 << endl;
	ap2 = ap1;
	//cout << *ap2 << endl;
}*/



//vs����ģ��
/*
template<class _Ty>
class my_auto_ptr
{
	typedef my_auto_ptr<_Ty> _Myt;
public:
	my_auto_ptr(_Ty *_Ptr = 0) : _Myptr(_Ptr)
	{}
	auto_ptr(_Myt& _Right) : _Myptr(_Right.release())
	{}
	_Myt& operator=(_Myt& _Right)
	{
		reset(_Right.release());//��һ���൱�����������£�1���ͷ�����ָ��_Right 2��reset(_Right._Myptr)  ��_Right._Myptr��ֵ��_Myptr
		return (*this);
	}
	~my_auto_ptr()
	{
		delete _Myptr;
	}
public:
	_Ty& operator*() const
	{
		return (*get());
	}
	_Ty *release()
	{
		_Ty *_Tmp = _Myptr;
		_Myptr = 0;
		return (_Tmp);
	}
	_Ty *get() const
	{
		return (_Myptr);
	}
	void reset(_Ty *_Ptr = 0)
	{
		if (_Ptr != _Myptr)
			delete _Myptr;
		_Myptr = _Ptr;
	}
private:
	_Ty *_Myptr;   //
};

*/

/*

template<class T>
class My_unique_ptr
{
private:
	T * px;
	My_unique_ptr(My_unique_ptr const &);
	My_unique_ptr & operator=(My_unique_ptr const &);
	typedef My_unique_ptr<T> this_type;
	void operator==(My_unique_ptr const&) const;
	void operator!=(My_unique_ptr const&) const;
public:
	typedef T element_type;
	explicit My_unique_ptr(T * p = 0) : px(p) // never throws
	{  }
	~My_unique_ptr() // never throws
	{
		//boost::checked_delete(px);
		delete px;
	}
	void reset(T * p = 0) // never throws
	{
		this_type(p).swap(*this);
	}
	T & operator*() const // never throws
	{
		return *px;
	}
	T * operator->() const // never throws
	{
		return px;
	}
	T * get() const // never throws
	{
		return px;
	}
	void swap(My_unique_ptr & b) // never throws
	{
		T * tmp = b.px;
		b.px = px;
		px = tmp;
	}
};

void main()
{
	string* s = new string("1234");
	My_unique_ptr<string> up(s);
	cout << up->size() << endl;
}



/*
void main()
{
	string* s = new string ("1234");
	unique_ptr<string> up(s);
	cout << up->size() << endl;
	//������������͸�ֵ
	//unique_ptr<string> up2(up);
	//unique_ptr<string> up3;
	//up3 = up2;
	int *p = new int(10);
	int *q = new int(20);
    
}*/
/*
void main()
{
	string* s = new string("1234");
	auto_ptr<string> ap1(s);
	//auto_ptr<string> ap2(s);
	auto_ptr<string> ap2(s);
	ap2 = ap1;
}

class state_deleter {  // a deleter class with state
	int count_;
public:
	state_deleter() : count_(0) {}
	template <class T>
	void operator()(T* p) {
		std::cout << "[deleted #" << ++count_ << "]\n";
		delete p;
	}
};

void main()
{
	DeleteArrayFunc<int> deleteArrayFunc;
	shared_ptr<int> sp2((int*)malloc(4), deleteArrayFunc);

	state_deleter del;
	unique_ptr<int, state_deleter&> sp2(new int, del);

}*/
/*
template <class T>
class state_deleter {  // a deleter class with state
public:
	
	void operator()(T* p) {
		std::cout << "[deleted[] #" << "]\n";
		delete[] p;
	}
};

void main()
{
	state_deleter<int> del;
	unique_ptr<int, state_deleter<int>&> sp2(new int[3], del);
}*/
/*
template<class T>
struct DeleteArrayFunc
{
	void operator()(T* ptr)
	{
		cout << "delete[]" << ptr << endl;
		delete[] ptr;
	}
};
void main()
{
	DeleteArrayFunc<int> deleteArrayFunc;
	shared_ptr<int> sp2((int*)malloc(4), deleteArrayFunc);

	unique_ptr<int, DeleteArrayFunc&> sp2(new int[], deleteArrayFunc);
	
	state_deleter del;
	unique_ptr<int, state_deleter&> sp2(new int, del);

	unique_ptr<int[]> foo(new int[5]);
	unique_ptr<int, deleteArrayFunc<int>> alpha(new int);

	unique_ptr<int, deleteArrayFunc> alpha(new int(2));
}


template<class T>
struct FreeFunc
{
	void operator()(T* ptr)
	{
		cout << "free:" << ptr << endl;
		free(ptr);
	}
};
template<class T>
struct DeleteArrayFunc
{
	void operator()(T* ptr)
	{
		cout << "delete[]" << ptr << endl;
		delete[] ptr;
	}
};
void main()
{
	FreeFunc<int> freeFunc;
	int *p = (int *)malloc(4);
	cout << "p = " << p << endl;
	shared_ptr<int> sp1(p, freeFunc);  //delete 
	DeleteArrayFunc<int> deleteArrayFunc;
	shared_ptr<int> sp2((int*)malloc(4), deleteArrayFunc);
}
*/

/*
int main() {
	std::unique_ptr<int[]> foo(new int[5]);
	int *p= new int[6];
	unique_ptr<int[]> foo3(p);
	for (int i = 0; i < 5; ++i) foo[i] = i;
	for (int i = 0; i < 5; ++i) std::cout << foo[i] << ' ';
	std::cout << '\n';
	return 0;
}
*/
#endif