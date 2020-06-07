#if 1
#include<iostream>
#include<string>
#include<memory>
using namespace std;


/*
double Division(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}
void Func()
{
	// 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再
	// 重新抛出去。
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
		e.What(); //多态
	}
	catch (...)
	{
		cout << "Unkown Exception" << endl;
	}
	return 0;

}
*/
//RAII 资源获取及初始化  自动
/*
void main()
{
	int  *tmp = new int(100);
	auto_ptr<int> ap(tmp); //智能指针ap接管tmp，ap其实是一个对象，智能体现在对象由析构方法，不要用户析构
	cout << *ap << endl;
	auto_ptr<string> ap1(new string("hello world!"));
	cout << ap1->size() << endl;

	ap1.reset(new string("good "));  //重新设置ap1管理的对象
	cout << ap1->size() << endl;
	ap1.release();  //释放指向的对象的地空间（vs c++11）/释放指向对象的所有权（vc c++98）
	auto_ptr<string>ap2 (new string ("bad"));
	ap1 = ap2;
	cout << *ap1 << endl;

}*/

//VC 源码模拟  带有管理权
/*
template<class _Ty>
class my_auto_ptr
{
public:
	my_auto_ptr(_Ty *_P = 0) : _Owns(_P != 0), _Ptr(_P)//当_P != 0时，_Owns=1，_Ptr=_P
	{}
	my_auto_ptr(const my_auto_ptr<_Ty> &_Y) : _Owns(_Y._Owns), _Ptr(_Y.release())
	{}
	my_auto_ptr<_Ty>& operator =(const  my_auto_ptr<_Ty>& _Y)
	{
		if (this != &_Y)
		{
		  if (_Ptr != _Y.get())  //
			{
				if (_Owns)  //当原来由空间时，要删除原有空间
					delete _Ptr;
				_Owns = _Y._Owns;
			}
			else if (_Y._Owns)   //如果_Y._Owns为flase，则不改变_Owns的所有权
				_Owns = true;
			_Ptr = _Y.release();//删除原有的管理权，赋值给_Ptr
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
	_Ty* release()const  //删除智能指针，将管理权变为false
	{
		//_Owns = false; 不行，是常方法，必须进行强制类型转换   或者使用 mutable关键字
		//*((bool*)&_Owns) = false;  //要么直接将const bool类型强转为bool类型
		((my_auto_ptr<_Ty>*)this)->_Owns = false;  //要么直接将const (my_auto_ptr<_Ty>*)this类型强转为(my_auto_ptr<_Ty>*) this类型         强制转换 忽略类型
		return _Ptr;
	}
	_Ty* get()const
	{
		return _Ptr;
	}
private:
	bool _Owns;//管理权
	_Ty *_Ptr;  //指向这块地址的指针
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



//vs代码模拟
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
		reset(_Right.release());//这一步相当于做了两件事，1、释放智能指针_Right 2、reset(_Right._Myptr)  将_Right._Myptr赋值给_Myptr
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
	//不允许拷贝构造和赋值
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