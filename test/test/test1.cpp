#if 1
#include<iostream>
#include<vector>
#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<list>
using namespace std;


int LastRemaining_Solution(int n, int m)
{
	if (n == 0)
		return -1;
	list<int> li;
	for (int i = 0; i < n; i++)
		li.push_back(i);
	auto it = li.begin();
	while (li.size() > 1)
	{
		int i = 0;
		for (; i < m-1; i++)
		{
 			if (it == li.end())
				it = li.begin();
			it++;
		}
		if (it == li.end())
			it = li.begin();
		it = li.erase(it);
	}
	return li.front();
}
void main()
{

	cout << LastRemaining_Solution(5, 2) << endl;
}











//void main()
//{
//	char *title = "文档快速搜索工具";
//	char buffer[MAX_TITLE_SIZE + 6 + 1] = "title "; //6:title%20  1:\0    
//	strcat(buffer, title);
//	system("title,文档快速搜索工具");
//	//string title = "文档快速搜索工具";
//	cout << title << endl;
//
//}
//int main()
//{
//	SetConsoleTitle("title 你的标题");
//	system("title 你的标题");
//	return 0;
//}
//int main()
//{
//	string s1= "qwer";
//	for (int i = 0; i < s1.size(); i++)
//	{
//		cout<<s1[i]<<" ";
//	}
//	cout << endl;
//}
//using namespace std;
//
//int add(int x=8, int y)
//{
//	return x + y;
//}
//int main(void)
//{ 
//	cout << add(4) << endl;
//	printf("%s,%10.3s\n", "computer", "computer");
//	return 0;
//}
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<limits.h>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> v;
//	for (int i = 0; i < 3 * n; i++)
//	{
//		int t;
//		cin >> t;
//		v.push_back(t);
//	}
//	//排序
//	sort(v.begin(), v.end());
//	int size = v.size();
//	int sum = 0;
//	int i = size / 3;
//	while (i < size)
//	{
//		sum = sum + v[i];
//		i += 2;
//	}
//	int ret = (sum < 0 ? INT_MAX:sum);
//	cout << ret << endl;
//}
//#include<stdio.h>
//struct S1 {
//	char c1;    //1+1=2
//	int i;    //4
//	char c2;//1+1=2
//};
//#define  OffSetOf(s,m)  (&((s*)0)->m)
//struct A {
//	int _a : 2;    //_a只占2个比特位
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};
//struct S {
//char a : 3;  
//char b : 4;  
//char c : 5;   
//char d : 4; };
//int main()
//{
//	printf("%d\n", OffSetOf(struct S1, c1));
//	printf("%d\n", OffSetOf(struct S1, i));
//	printf("%d\n", OffSetOf(struct S1, c2));
//	cout <<"sizeof(A)  ="<<sizeof(A) << endl;
//	cout << "sizeof(S)  =" << sizeof(S) << endl;
//}
//union Un2 { char c[5];  int i; };
//void main()
//{
//	printf("%d\n", sizeof(union Un2));//联合体的大小为最大成员的字节对齐数
//}

#endif