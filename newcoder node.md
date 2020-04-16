#### Day 1

1、逗号表达式，以最后一位为主

2、printf 中 ，%-m.n     -表示左对齐，m代表输出的最小宽度，n对于字符串而言是输出字符串的前n个字符

```
int main(void)
{ 
	printf("%s , %5.3s\n", "computer", "computer");
	return 0;
}
```

输出  `computer ,  com` 

3、int *p[4]  指针数组，[]的优先级 * 的优先级

   int （*p）[4]     数组指针

4、c符号的优先级  []、{}、 ++、*

5、若有定义语句： int a=10 ; double b=3.14 ; 则表达式 'A'+a+b 值的类型是（）  double

因为按照强制类型转换，类型小的转换为类型大的   

` long double, double, float, unsigned long long, long long, unsigned long, long, unsigned int 和 int`

6 https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b?f=discussion

[编程题]组队竞赛 

贪心算法 进行排序后直接相加

```
#include<iostream>
#include<vector>
#include<algorithm>
#include <limits.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long> v;
    for(int i=0;i<3*n; i++)
    {
        int t;
        cin>>t;
        v.push_back(t);
    }
    //排序
  sort(v.begin(), v.end());
	int size = v.size();
	long sum = 0;
	int i = size / 3;
	while (i < size)
	{
		sum = sum + v[i];
		i += 2;
	}
    cout<<sum<<endl;
    return 0;
}
```

7、https://www.nowcoder.com/practice/f0db4c36573d459cae44ac90b90c6212?tpId=85&&tqId=29868&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

删除公共字符 输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”

题解；采用桶排的思想，将s2的内容获取，在于s1进行比较

```
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1,s2;
     getline(cin, s1); 
     getline(cin, s2); 
    char hashtable[256]={0};
    for(int i=0; i<s2.size();i++)
    {
        hashtable[s2[i]]++;
    }
    string ret;
     for(int i=0; i<s1.size();i++)
    {
       if(hashtable[s1[i]]==0)
           ret+=s1[i];
    }
    cout<<ret<<endl;
    return 0;
}
```

#### Day 2

1、内联函数：