#if 1
#include<iostream>
#include<string>
#include<vector>
#include<bitset>
using namespace std;


template<typename T>
struct comp
{
	bool operator()(T in1, T in2) const
	{
		return (in1 > in2);
	}
};
void main()
{
	comp<int> m_comp_objext;
	cout << m_comp_objext(6, 3) << endl;     //使用对象调用
	cout << comp<int>()(1, 2) << endl;       //使用仿函数实现
}
#if 0
struct StrToInt1
{
	size_t BKDRHash(const char *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
	size_t operator()(const string &str)
	{
		return BKDRHash(str.c_str());
	}
};

struct StrToInt2
{
	size_t SDBMHash(const char *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = 65599 * hash + ch;
		}		return hash;

	}
	size_t operator()(const string &str)
	{
		return SDBMHash(str.c_str());
	}
};
struct StrToInt3
{
	size_t RSHash(const char *str)
	{
		register size_t hash = 0;
		size_t magic = 63689;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * magic + ch;
			magic *= 378551;
		}
		return hash;
	}
	size_t operator()(const string &str)
	{
		return RSHash(str.c_str());
	}
};
//布隆过滤器
#define _N 1000
template<class K, class HashFunc1 = StrToInt1,class HashFunc2 = StrToInt2, class HashFunc3 = StrToInt3 >
class BloomFilter
{
public:
	BloomFilter() :m_size(0)
	{}
public:
	void Insert(const string &str)
	{
		size_t bit_capacity = m_bmp.size();
		size_t index1 = HashFunc1()(str) % bit_capacity;
		m_bmp.set(index1);
		size_t index2 = HashFunc2()(str) % bit_capacity;
		m_bmp.set(index2);
		size_t index3 = HashFunc3()(str) % bit_capacity;
		m_bmp.set(index3);
		m_size++;
	}
	bool Test(const string &str)
	{
		size_t bit_capacity = m_bmp.size();
		size_t index1 = HashFunc1()(str) % bit_capacity;
		if (!m_bmp.test(index1))
			return false;
		size_t index2 = HashFunc2()(str) % bit_capacity;
		if (!m_bmp.test(index2))
			return false;
		size_t index3 = HashFunc3()(str) % bit_capacity;
		if (!m_bmp.test(index3))
			return false;
		return true;
	}
private:
	bitset<_N * 5> m_bmp;
	size_t m_size;
};

void main() {

	BloomFilter<string> bf;
	string str0 = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
	string str1 = "ttps://www.cnb";
	string str2 = "https://www.cnblogs";
	string str3 = "https://www.cnblogs.com/clq/archive/2012/05/31/2528153.html";
	bf.Insert(str0);
	bf.Insert(str1);
	bf.Insert(str2);
	bf.Insert(str3);
	cout << bf.Test(str2) << endl;
}

#endif
#if 0
template <size_t _N>
class Bitset;
//#define _N 10;
ostream& operator<<(ostream &out, const Bitset<10> &bt);
template <size_t _N>
class Bitset
{
	friend ostream& operator<<(ostream &out, const Bitset<10> &bt);
public:
	Bitset() :m_bit((_N - 1) / 32 + 1), m_size(_N)
	{}
	void set(size_t pos)
	{
		if (pos >= m_size)
			return;
		size_t index = pos / 32;
		size_t offset = pos % 32;
		m_bit[index] |= (1 << offset);
	}
	bool test(size_t pos)
	{
		if (pos >= m_size)
			return false;
		size_t index = pos / 32;
		size_t offset = pos % 32;
		m_bit[index] &= (1 << offset);
	}
public:
	size_t count()const
	{
		int bitCnttable[256] = {
			0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2,
			3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3,
			3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3,
			4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4,
			3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5,
			6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4,
			4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5,
			6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5,
			3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3,
			4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6,
			6, 7, 6, 7, 7, 8 };
		/*
		编程之美  0-255  之间，数num的比特位中1的个数是bitCnttable[num]
		*/
		size_t size = m_bit.size();
		size_t count = 0;
		for (size_t i = 0; i < size; i++)
		{
			//每次先取出一个int -> m_bit[i];
			//int有32个比特位，我们每次右移8位
			int value = m_bit[i];
			int j = 0;
			while (j < sizeof(m_bit[0]))//循环4次sizeof(m_bit[0]=4
			{
				unsigned char c = value;//将int强转为char类型，取低8位
				count += bitCnttable[c];
				++j;
				value >>= 8;
			}
		}
		return count;
	}
private:
	vector<int> m_bit;
	size_t m_size;
};
ostream& operator<<(ostream &out, const Bitset<10> &bt)
{
	cout << bt.m_bit[0] << endl;
	for (int i = 9; i >= 0; --i)
	{
		if (bt.m_bit[i / 32] & (0x01 << i))
			out << i;
		else
			out << 0;
	}
	return out;
}

void main()
{
	Bitset<10> bt;
	cout << bt << endl;
	bt.set(2);
	bt.set(1);
	cout << bt.test(3) << endl;
	cout << bt.count() << endl;
}

#endif

#endif