#if 0
#include<iostream>
#include<vector>
#include<queue>
#include<assert.h>
using namespace std;
#if 0
/*
void main()
{
	vector<int> v = { 2,1,4,5,3,0,6,7 };//�����Ϳ���ʵ������
	make_heap(v.begin(), v.end());
	for (auto e : v)
		cout << e << " ";
	cout << endl;
	auto pos = find(v.begin(), v.end(), 7);
	v.erase(pos);
	push_heap(v.begin(), v.end());
	for(auto e:v)
		cout << e << " ";
	cout << endl;
	/*priority_queue <int, vector<int>, greater<int>> pq;
	for (auto e:v)
		pq.push(e);*/
		//for (int i = 0; i < 6; i++)
		//{
		//	cout << pq.top() << " ";
		//	pq.pop();
		//}
		//cout << endl;
		////make_heap push_heap pop_heap
		//make_heap(v.begin(), v.end(), greater<int>());
		//for (int i = 0; i < v.size(); i++)
		//{
		//	cout << v[0] << " ";
		//	pop_heap(v.begin(),v.end()-i, greater<int>());
		//}
		//cout << endl;
		//for(auto e:v)
		//	cout << e << " ";
		//cout << endl;
}
*/
#endif
//proority queue ��ģ�� �����㷨 make_heap push_heap pop_heap
//namespace Mypriority
//{
//	template<class T>
//	struct less
//	{
//		bool operator ()(const T& left, const T& right)
//		{
//			return (left < right);
//		}
//	};
//	template<class T>
//	struct greater
//	{
//		bool operator ()(const T& left, const T& right)
//		{
//			return (left > right);
//		}
//	};
//	template <class T,class Cont=vector<T>,class Pred=less<T>>
//	class priority_queue
//	{
//	public:
//
//		explicit priority_queue(const Pred& pr = Pred())
//		{
//			make_heap(c.begin(), c.end());
//		}
//		bool empty()const
//		{
//			return c.empty();
//		}
//		size_t size()const
//		{
//			return c.size();
//		}
//		T& top()
//		{
//			assert(!empty());
//			return c.front();
//		}
//		T& top()const
//		{
//			assert(!empty());
//			return c.front();
//		}
//		void push(const T& _value)
//		{
//			c.push_back(_value);
//			push_heap(c.begin(), c.end());
//		}
//		void pop()
//		{
//			pop_heap(c.begin(), c.end());
//			c.pop_back();
//		}
//	protected:
//		Cont c;
//		Pred comp;
//	};
//};
//void main()
//{
//	Mypriority::priority_queue<int> pq;
//	cout << pq.empty() << endl;
//	vector<int> v = { 2,5,7,4,3,6,1,8 };
//	for (auto e : v)
//		pq.push(e);
//
//	for (int i = 0; i < 8; i++)
//	{
//		cout<<pq.top()<<" ";
//		pq.pop();
//	}
//
//}
//priority queue ��ģ�� �Լ���д����
/*
��д���µ�������adjustdown �����ϵ���adjustup
�����ѣ��Ȱ�Ԫ�ز��룬 �����һ����֧���µ�  �ҵ����һ���ڵ�ĸ��ڵ�������һ����֧ int root=(c.size()-1)/2  ������adjustdown(root--)
         ֪��root==0�������
����Ԫ�أ���Ԫ�ز��뵽�ѵ����һ���ڵ��ϣ���ʼ���ϵ��� adjustup(child)  ����parent����λ�� parent=(child-1)/2��
ɾ��Ԫ�أ������һ��Ԫ�غͶѶ�Ԫ�ػ�����ɾ�����һ��Ԫ�أ��ӶѶ���ʼ���µ�  adjustdown(parent)(child=2*parent+1)(ע������������parentֻ��������������)
*/
namespace Mypriority
{
	template<typename T>

	struct less
	{
		bool operator()(const T& left, const T& right)
		{
			return left < right;
		}
	};
	template<class T>
	struct greater
	{
		bool operator()(const T& left, const T& right)  
		{
			return left > right;
		}
	};
	template<class T, class Cont = vector<T>, class Pred = less<T> >  
	class priority_queue {
	public:
		priority_queue()
		{}
		priority_queue(const T*first, const T*last)    ////����ָ��  ������  �����һ����֧���µ�
		{
			while (first != last)
				c.push_back(*first++);
			int root = ((first - last) - 1) / 2;//�ҵ����һ���ӽڵ�ĸ��ڵ�������һ����֧
			while (root >= 0)
			{
				adjustdown(root);
				root--;
			}
		}
		template<class INputiterator>
		priority_queue(INputiterator first, INputiterator last)    ////���õ����� ������  �����һ����֧���µ�
		{
			while (first != last)
				c.push_back(*first++);
			int root = ((c.size()) - 1) / 2;//
			while (root >= 0)
			{
				adjustdown(root);
				root--;
			}
		}
	public:
		size_t size()const
		{
			return c.size();
		}
		bool empty()const
		{
			return c.empty();
		}
		T& top()
		{
			assert(!empty());
			return c.front();
		}
		T& top()const
		{
			assert(!empty());
			return c.front();
		}
		void push(const T& value)
		{
			c.push_back(value);
			adjustup(c.size() - 1);
		}
		void pop()
		{
			std::swap(c.front(), c.back());
			c.pop_back();
			adjustdown(0);
		}
		void show_pvector()
		{
			for (auto &e : c)
				cout << e << " ";
			cout << endl;

		}
	protected:
		void adjustup(int child)
		{
			int parent = (child - 1) / 2;
			while (child)
			{
				if (comp(c[parent], c[child]))
				{
					std::swap(c[parent], c[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
					break;
			}
		}
		void adjustdown(int parent)
		{
			int child = 2 * parent + 1;
			while (child < c.size())
			{
				if (child + 1 < c.size() && comp(c[child], c[child + 1]))
				{
					child += 1;
				}
				if (comp(c[parent], c[child]))
				{
					std::swap(c[parent], c[child]);
					parent = child;
					child = 2 * parent + 1;
				}
				else
					break;
			}
		}
	protected:
		Cont c;
		Pred comp;
	};
};
void main()
{

	/*vector<int> v = { 1,2,4,5,7,3,0,6 };
	Mypriority::priority_queue <int> pq(v.begin(), v.end());*/
	int v[] = { 5, 7, 8, 2, 9, 3, 1, 0 };
	int n = sizeof(v) / sizeof(int);

	Mypriority::priority_queue<int> pq(v, v + n);
	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}
}
//void main()
//{
//
//	Mypriority::priority_queue<int> pq;
//	pq.push(2);
//	pq.push(3);
//	pq.push(7);
//	pq.push(1);
//	pq.push(0);
//	pq.push(10);
//	pq.push(9);
//	pq.show_pvector();
//	while (!pq.empty())
//	{
//		cout<<pq.top()<<endl;
//		pq.pop();
//	}
//}
#endif