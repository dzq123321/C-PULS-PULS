#if 1
#include<iostream>
#include <list>
#include<assert.h>
using namespace std;
//void main()
//{
//	int ar[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int n = sizeof(ar) / sizeof(int);
//	list<int> mylist1;
//	list<int> mylist2(10, 2);
//	list<int> mylist3(ar,ar+10);
//	list<int> mylist4 = { 1,2,3,4,5 };
//	list<int> mylist5(++mylist4.begin(), mylist4.end());
//	for (const auto &e : mylist4)
//		cout << e << "-->";
//	cout << "over" << endl;
//	list<int>::iterator it = mylist4.begin();
//	while (it != mylist4.end())
//	{
//		cout << *it << "-->";
//		++it;
//	}
//	cout << "over" << endl;
//	list<int>::reverse_iterator rit = mylist4.rbegin();//用auto会更方便
//	while (rit != mylist4.rend())
//	{
//		cout << *rit << "-->";
//		++rit;
//	}
//	cout << "over" << endl;
//}
//void main()
//{
//	int ar[] = { 1,2,3,4,5,6,7,8,9,10 };
//	list<int> mylist(ar, ar + 10);
//	/*mylist.push_back(11);
//	mylist.pop_front();
//	auto it = mylist.begin();
//	while (it != mylist.end())
//	{
//		cout << *it << "-->";
//		++it;
//	}
//	cout << endl;*/
//	auto pos = find(mylist.begin(), mylist.end(), 1);//find找的是当前数的前一个位置
//	cout << typeid(pos).name() << endl;
//	mylist.insert(pos, 3,1);
//	for (const auto &e : mylist)
//		cout << e << "-->";
//	cout << "over" << endl;
//	 pos = mylist.begin();
//	 auto pos2 = find(mylist.begin(), mylist.end(), 3);
//	mylist.erase(pos, pos2);
//	for (const auto &e : mylist)
//		cout << e << "-->";
//	cout << "over" << endl;
//	cout << mylist.size() << endl;
//}
//迭代器失效
//void main()
//{
//	list<int> mylist = { 1,2,3,4,5 };
//	mylist.clear();
//	cout << mylist.size() << endl;
//}
//int main()
//{
//	cout << "int()"<<int() << typeid(int()).name()<<endl;   //零初始化
//	cout << "double()" << double() << typeid(double()).name() << endl;
//	cout << "char()" << char() << typeid(char()).name() << endl;
//
//}

//void main()
//{
//	list<int> mylist = { 1, 2, 3, 4 };
//	for (auto e : mylist)
//		cout << e << "-->";
//		cout <<"over"<< endl;
//		cout << *mylist.begin() << endl;
//}
//list 类的模拟

namespace Mylist
{
	template <typename T>
	struct ListNode
	{
		ListNode(const T& value = T()) :next(nullptr), prev(nullptr), _value(value)
		{}
		ListNode<T> *next;
		ListNode<T> *prev;
		T _value;
	};
	template <typename T>
	class ListIterator
	{
		typedef ListNode<T>* PNode;
	public:
		ListIterator() :_ptr(nullptr)
		{}
		ListIterator(PNode p) :_ptr(p)
		{}
		~ListIterator()
		{}
	public:
		PNode _MyNode()
		{
			return _ptr;
		}
	public:
		T& operator *()
		{
			return _ptr->_value;
		}
		T& operator->()
		{
			return &(**this); //&(this->_value)
		}
		bool operator==(const ListIterator& it)
		{
			return  (_ptr == it._ptr);
		}
		bool operator!=(const ListIterator& it)//==重载的是ListIterator的类型，所以不能是！(_ptr == it._ptr)
		{
			return  !(*this == it);
		}

		ListIterator& operator++()
		{
			_ptr = _ptr->next;
			return *this;
		}
		ListIterator operator++(int)
		{
			ListIterator tmp = *this;
			++*this;
			return tmp;
		}
		ListIterator& operator--()
		{
			_ptr = _ptr->prev;
			return *this;
		}
		ListIterator operator--(int)
		{
			ListIterator tmp = *this;
			--*this;
			return tmp;
		}
	private:
		PNode _ptr;
	};
	template <typename T>
	class list
	{
	public:
		typedef ListNode<T>* PNode;
		typedef ListIterator<T> iterator;
		list(size_t size = T()) :_head(_BuyNode()), _size(size)
		{}
		list(size_t n, const T &value = T()) :_head(_BuyNode()), _size(0)
		{
			while (n)
			{
				push_back(value);
				n--;
			}
		}
		template<typename _It>//要用模板因为构造是可能是数组L1(ar,ar+10) 也有可能是迭代器L2(L1.begin(),L1.end())
		list(_It first,_It last) :_head(_BuyNode()), _size(0)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
	/*	list<T>& operator=( const list<T>& lt)
		{
			if (this != &lt)
			{
				list<T> tmp(lt.begin(), lt.end());
				swap(tmp);
			}
			return *this;
		}*/
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
	public:
		iterator erase(iterator pos)
		{
			PNode _S = pos._MyNode();
			PNode  _R = _S->next;
			_S->next->prev = _S->prev;
			_S->prev->next = _S->next;
			delete _S;
			_S = nullptr;
			return iterator(_R);
		}
		void clear()
		{
			PNode p = _head->next;
			PNode q = p;
			while (p!=_head)
			{
				p = p->next;
					delete q;
				q = p;
			}
		}
	public:
		size_t size() const
		{
			return _size;
		}
		bool empty()const
		{
			return (_size == 0);
		}
		iterator begin()
		{
			return iterator(_head->next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		void push_back(const T& value = T())
		{
			insert(end(), value);
		}
		T& front()
		{
			assert(!(empty));
			return  *begin();
		}
		void swap(list& lt)
		{
			std::swap(this->_head, lt._head);
			std::swap(this->_size, lt._size);
		}
	public:
		iterator insert(iterator pos, const T& value)
		{
			PNode ND = _BuyNode(value);
			PNode _I = pos._MyNode();
			ND->next = _I;
			ND->prev = _I->prev;
			ND->prev->next = ND;
			_I->prev = ND;
			_size++;
			return iterator(ND);
		}
	protected:
		PNode _BuyNode(const T& value = T())
		{
			PNode ND = new ListNode<T>(value);
			ND->next = ND;
			ND->prev = ND;
			return ND;
		}
	private:
		PNode _head;
		size_t _size;

	};
};
void main()
{
	int ar[] = { 1, 2, 3, 4, 5 };
	Mylist::list<int> L1(ar, ar + 5);
	Mylist::list<int> L2(L1.begin(), L1.end());
	/*Mylist::list<int> L1(10,1);*/

   cout << "over" << endl;
   L2.push_back(6);
   L1.swap(L2);
   auto it = L1.begin();
   while (it != L1.end())
   {
	   cout << *it << "-->";
	   ++it;
   }
   	cout << "over"<<endl;
	for(auto e:L2)
		cout << e << "-->";
	cout << "over"<<endl;
	Mylist::list<int> L3(L1);
	L3.erase(L3.begin());
	for (auto e : L3)
		cout << e << "-->";
	cout << "over" << endl;
	/*Mylist::list<int> (L4);
	L4 = L3;
	for (auto e : L4)
		cout << e << "-->";
	cout << "over" << endl;*/
}
//void main()
//{
//	Mylist::list<int> L1;
//	L1.insert(L1.begin(), 1);
//	L1.insert(L1.begin(), 2);
//	L1.insert(L1.begin(), 3);
//	cout << *L1.begin() << endl;
//	//for(auto e:L1)
//	auto it = L1.begin();
//	while (it != L1.end())
//		{
//			cout << *it << "-->";
//			++it;
//	}
//	cout << endl;
//}

#endif