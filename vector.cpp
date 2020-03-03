#if 1
#include<iostream>
#include<vector>
using namespace std;
//
//void main()
//{
////1、默认构造
//	vector <int> v1;
//	cout << v1.size() << endl;
//	cout << v1.capacity() << endl;
//	//2、值构造
//	vector <int> v2(10,5);
//	//迭代器构造
//	vector <int> v3(v2.begin()+5, v2.end()-1);
//	//4、拷贝构造
//	vector <int> v4(v3);
//	//5、数组构造
//	int ar[10] = { 1,2,3,4,5 };
//	vector <int> v5(ar, ar + 5);
//	Print(v5);
//	cout << v2.size() << endl;
//	cout << v2.capacity() << endl;
//	vector<int> ::iterator it = v5.begin();
//	while (it != v5.end())
//	{
//		cout << *it<<" ";
//		++it;
//	}
//	cout << v5.size() << endl;
//	cout << v5.capacity() << endl;
//	v5.resize(2, 5);
//	Print(v5);
//	cout << v5.size() << endl;
//	cout << v5.capacity() << endl;
//}


//void Print(vector <int> & v)
//{
//	for (int i = 0; i < v.size(); ++i)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//}
//   vector 迭代器失效问题
//void main()
//{
//	int a[] = { 1, 2, 3, 4 }; 
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			it = v.erase(it);
//		else
//			++it;
//	}
//	Print(v);
//}

// 模拟实现vector类
namespace Myvector
{
	template <typename T>
	class vector
	{
	public:
		typedef  T* iterator;
		vector() :first(nullptr), last(nullptr), end_of_storge(nullptr)
		{}
		vector(size_t n, const T &value = T())
			:first(nullptr), last(nullptr), end_of_storge(nullptr)
		{
			reserve(n);
			while (n-- != 0)
				push_back(value);
		}
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			:first(nullptr), last(nullptr), end_of_storge(nullptr)
		{
			reserve(last - first);
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		~vector()
		{
			delete[]first;
			first = last = end_of_storge = nullptr;
		}
	public:
		size_t size()const
		{
			return last - first;
		}
		size_t capacity()const
		{
			return end_of_storge - first;
		}
		bool empty()const
		{
			return (first == last);
		}
		T& operator[](int i)
		{	return *(first + i);}
		iterator begin()
		{	return first;}
		iterator end()
		{	return last;}
	public:
		void reserve(size_t n)
		{
			size_t oldsize = size();
			if (n > capacity())
			{
				iterator newcap = new T[n];
				for (int i = 0; i < size(); i++)
				{
					newcap[i] = first[i];
				}
				if (first)
					delete[]first;
				first = newcap;
				last = first + oldsize;  //这里要记得是oldsize(),因为first已变化，不能再是size()
				end_of_storge = first + n;
			}
		}
		void resize(size_t n, const T& value = T())
		{
			if (n <= size())
			{
				last = first + n;
				return;
			}
			if (n > capacity())
				reserve(n * 2);
			iterator p = last;
			 last = first + n;
				while (p != last)
				{
					*p = value;
					p++;
				}
		}
		iterator insert(iterator pos, const T &x)
		{
			//先判断vector是否需要开辟空间
			if (last >= end_of_storge)
			{
				size_t oldpos = pos - first;
				size_t new_cpy = (capacity() ? capacity() * 2 : 1);
				reserve(new_cpy);

				//重新定位迭代器
				pos = first + oldpos;
			}
			iterator  p = last;
			while (p != pos)
			{
				*p = *(p - 1);
				p--;
			}
			last++;
			*pos = x;
			return pos;
		}
		void push_back(const T &x)
		{
			insert(end(), x);
		}
		iterator erase(iterator pos)
		{
				iterator p = pos ;
				while (p != last-1)
				{
					*p = *(p + 1);
					p++;
				}
				last--;
				return pos;	
		}
	private:
		iterator first;
		iterator last;
		iterator end_of_storge;
	};
};
void main()
{
	Myvector::vector<int> v1;
	v1.resize(5, 1);
	//v1.resize(10, 0);
	v1.insert(v1.begin()+1, 2);
	cout << v1.capacity() << endl;
	cout << v1.size() << endl;
//	v1.push_back(3);
	v1.erase(v1.end());
	for (int i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
}

#endif