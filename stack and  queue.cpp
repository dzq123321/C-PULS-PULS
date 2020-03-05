#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<deque>
#include<functional>

using namespace std;
//int main()
//{
//	stack <int> st1;
//	st1.push(1);
//	st1.push(2);
//	st1.push(3);
//	st1.push(4);
//	cout << st1.top()<<endl;
//	st1.pop();
//	cout << st1.top() << endl;
//	vector<int> v = { 1,2,3,4,5,6 };
//	priority_queue<int,vector<int>,greater<int>> pq;
//	for (auto e : v)
//		pq.push(e);
//	for (auto e : v)
//		cout << e << " ";
//	cout << endl;
//
//}
//void main()
//{
//	queue<int> Q;
//	Q.push(1);
//	Q.push(2);
//	Q.push(3);
//	Q.push(4);
//	cout << Q.front() << endl;
//	cout << Q.back() << endl;
//	Q.pop();
//	cout << Q.front() << endl;
//	cout << Q.back() << endl;
//}
//stack  和queue作为容器适配器，底层是用其他容器来实现的
//namespace MyStl
//{
//	template <typename T, typename Cont = list<T>>
//	class queue
//	{
//		typedef size_t size_type;
//		typedef T      value_type;
//	public:
//		explicit queue()
//		{}
//		bool empty() const
//		{
//			return c.empty();
//		}
//		size_type size() const
//		{
//			return c.size();
//		}
//		value_type& front()
//		{
//			return c.front();
//		}
//		const value_type& front()const
//		{
//			return c.front();
//		}
//		value_type& back()
//		{
//			return c.back();
//		}
//		const value_type& back()const
//		{
//			return c.back();
//		}
//		void push(const value_type& x)
//		{
//			c.push_back(x);
//		}
//		void pop()
//		{
//			c.pop_front();
//		}
//	protected:
//		Cont c;
//	};
//};
//void main()
//{
//	MyStl::queue<int> Q;
//	cout << Q.empty() << endl;
//	Q.push(1);
//	Q.push(2);
//	Q.push(3);
//	Q.push(4);
//	cout << Q.front() << endl;
//	cout << Q.back() << endl;
//	Q.pop();
//	cout << Q.front() << endl;
//	cout << Q.back() << endl;
//}
//栈同上，底层容器可以是string,vector,list,但queue只能是list 在系统内两者都用的是deque
//namespace Mystack
//{
//	template <typename T, typename Cont = deque<T>>
//	class stack
//	{
//		typedef size_t size_type;
//		typedef T      value_type;
//	public:
//		explicit stack()
//		{}
//		bool empty() const
//		{
//			return c.empty();
//		}
//		size_type size() const
//		{
//			return c.size();
//		}
//		value_type& top()
//		{
//			return c.back();
//		}
//		const value_type& top()const
//		{
//			return c.back();
//		}
//		void push(const value_type& x)
//		{
//			c.push_back(x);
//		}
//		void pop()
//		{
//			c.pop_front();
//		}
//	protected:
//		Cont c;
//	};
//};
//void main()
//{
//	Mystack::stack<int> st;
//	cout << st.empty() << endl;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	cout << st.top() << endl;
//	st.pop();
//	cout << st.top() << endl;
//}
//void main()
//{
//	vector<int> v = { 1,2,3,4,5,6 };
//	priority_queue<int, vector<int>, greater<int>> pq;
//	for (auto e : v)
//		pq.push(e);
//	cout << pq.top() << endl;
//	cout << endl;
//	vector<int> v1 = { 1,2,3,5,6 };
//	make_heap(v1.begin(), v1.end(), greater<int>());
//	v1.push_back(4);
//	push_heap(v1.begin(), v1.end(), greater<int>());
//	for (auto e : v1)
//		cout << e << " ";
//	cout << endl;
//}