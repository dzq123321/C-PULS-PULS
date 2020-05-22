#if 1
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<list>
#include<algorithm>
#include<queue>
#include<unordered_map>
using namespace std;


bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	/*
	先记录以某个节点i为直接前驱的出度表，用map记录
	*/
	unordered_map<int, vector<int>> map;
	vector<int> degree(numCourses, 0);//每个课程的入度是多少
	for (vector<int> prerequisite : prerequisites)
	{
		map[prerequisite[1]].push_back(prerequisite[0]);
		degree[prerequisite[0]]++;
	}
	return true;
}
void main()
{
	vector<vector<int>> v = { {0,1,2},{3,5,4},{3,1,0} };
	bool b=canFinish(6, v);
}







//
//
//vector<vector<bool>> vis;
//char* m;
//int n;
//bool dfs(int pos, int x, int y, int rows, int cols, char* str)
//{
//	int dx[] = { 0,1,0,-1 };
//	int dy[] = { 1,0,-1,0 };
//	if (pos == n)
//		return true;
//	for (int i = 0; i < 4; i++)
//	{
//		int xx = dx[i] + x;
//		int yy = dy[i] + y;
//		if (xx < 0 || xx >= rows || yy < 0 || yy >= cols)
//			continue;
//		if (m[xx*cols + yy] != str[pos])
//			continue;
//		if (vis[xx][yy] == true)
//			continue;
//		vis[xx][yy] = true;
//		if (dfs(pos + 1, xx, yy, rows, cols, str))
//			return true;
//		vis[xx][yy] = false;
//	}
//	return false;
//}
//bool hasPath(char* matrix, int rows, int cols, char* str)
//{
//	if (rows < 0 || cols < 0 || str == NULL)
//		return false;
//	vis.assign(rows, vector<bool>(cols, false));
//	m = matrix;
//	n = strlen(str);
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			if (matrix[i*cols + j] != str[0])
//				continue;
//			if(matrix[i*cols + j] == str[0])
//			{
//				vis[i][j] = true;
//				if (dfs(1, i, j, rows, cols, str))
//					return true;
//				vis[i][j] = false;
//			}
//		}
//	}
//	return false;
//}
//void main()
//{
//	char* matrix = "ABCESFCSADEE";
//	char* str = "ABCCED";
//	cout << hasPath(matrix, 3, 4, str)<<endl;
//}
//vector<vector<int>> vis;
//int m, n;
//vector<int> dx = { 0,1,0,-1 };
//vector<int> dy = { 1,0,-1,0 };
//bool dfs(int pos, int i, int j, vector<vector<char>>&  board, string word)
//{
//	if (pos == word.size())
//		return true;
//	for (int d = 0; d < 4; d++)
//	{
//		int ii = i + dx[d];
//		int jj = j + dy[d];
//		if (ii < 0 || ii >= m || jj < 0 || jj >= n)
//			continue;
//		if (vis[ii][jj] == 1 || board[ii][jj] != word[pos])
//			continue;
//		//if(board[ii][jj]==word[pos])
//	   // {
//		vis[ii][jj] = 1;
//		if (dfs(pos + 1, ii, jj, board, word))
//			return true;
//		vis[ii][jj] = 0;
//		// }
//	}
//	return false;
//}
//bool exist(vector<vector<char>>& board, string word) {
//	if (board.size() == 0 || board[0].size() == 0)
//		return false;
//	m = board.size();
//	n = board[0].size();
//	vis.assign(m, vector<int>(n, 0));
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//
//			if (board[i][j] != word[0])
//				continue;
//			if (board[i][j] == word[0])
//			{
//				vis[i][j] = 1;
//				if (dfs(1, i, j, board, word)) {
//					return true;
//				}
//				vis[i][j] = 0;
//			}
//		}
//	}
//	return false;
//}
//
//void main()
//{
//	char* matrix = "ABCESFCSADEE";
//	vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
//	string str = "ABCCED";
//	cout << exist(board, str)<<endl;
//}












//void main()
//{
//	char* s = "123345";
//	cout << s[3] << endl;
//}




//vector<vector<bool>> vis;
//int movingCount(int m, int n, int k) {
//	// vis.assign(m,vector<bool>(n,false));
//	vector<vector<bool>> vis(m, vector<bool>(n, false));
//	int ans = 0;
//	int dx[] = { 0,1,0,-1 };
//	int dy[] = { 1,0,-1,0 };
//	queue<pair<int, int>> que;
//	que.push(make_pair(0, 0));
//	ans++;
//	vis[0][0] = true;
//	while (!que.empty())
//	{
//		auto x = que.front().first;
//		auto y = que.front().second;
//		que.pop();
//		for (int i = 0; i < 4; i++)
//		{
//			x = x + dx[i];
//			y = y + dy[i];
//			if (x >= m || x < 0 || y >= n || y<0 || vis[x][y] == true || x + y>k)
//				continue;
//			que.push(make_pair(x, y));
//			vis[x][y] = true;
//			ans++;
//		}
//	}
//	return ans;
//}
//
//void main()
//{
//	cout << movingCount(11, 8, 16) << endl;
//}






//
//int integerBreak2(int n) {
//	//解法2 带备忘录的递归
//	if (n == 2)
//		return 1;
//	vector<int> memo(n + 1, 0);
//	int res = -1;
//	if (memo[n] != 0)
//		return memo[n];
//	for (int i = 1; i < n; i++)
//	{
//		res = max(res, max(i * (n - i), i * integerBreak(n - i)));
//	}
//	memo[n] = res;
//	return res;
//}
//int integerBreak(int n) {
//	/*
//	贪心  a*3+b=n
//	https://leetcode-cn.com/problems/integer-break/solution/343-zheng-shu-chai-fen-tan-xin-by-jyd/
//	*/
//	int b = n % 3;
//	if (b == 0)
//	{
//		int a = n / 3;
//		return pow(3, a);
//	}
//	if (b == 1)
//	{
//		int a = n / 3;
//		return pow(3, a - 1) * 4;
//	}
//	if (b == 2)
//	{
//		int a = n / 3;
//		return pow(3, a) * 2;
//	}
//}
//void main()
//{
//	cout << integerBreak(10) << endl;
//	vector<vector<bool>> vis;
//	int m = 4, n = 5;
//	vis.assign(m, vector<bool>(n, true));
//	cout << vis[3][4] << endl;
//}
//
//
//
//////-2147483648到2147483647.
////int StrToInt(string str) {
////	if (str == "")
////		return 0;
////	long ret = 0;
////	int  bndry = INT_MAX / 10;
//	int flag = 0;
//	if (str[0] == '-')
//		flag = 1;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[0] == '-' || str[0] == '+')
//		{
//			str[0] = '*';
//			continue;
//		}
//		if ('0' <= str[i] && str[i] <= '9')
//		{
//			ret = 10 * ret + (str[i] - '0');
//			if (ret > bndry || ret == bndry && str[i] > '7') return flag ==0 ? INT_MAX : INT_MIN;
//		}
//		else
//			return 0;
//	}
//	if (flag == 1)
//		return -ret;
//	return ret;
//}
//void main()
//{
//	string s("-2147483647");
//	cout << StrToInt(s) << endl;
//	cout << s.substr(2) << endl;
//}


//int LastRemaining_Solution(int n, int m)
//{
//	if (n == 0)
//		return -1;
//	list<int> li;
//	for (int i = 0; i < n; i++)
//		li.push_back(i);
//	auto it = li.begin();
//	while (li.size() > 1)
//	{
//		int i = 0;
//		for (; i < m-1; i++)
//		{
// 			if (it == li.end())
//				it = li.begin();
//			it++;
//		}
//		if (it == li.end())
//			it = li.begin();
//		it = li.erase(it);
//	}
//	return li.front();
//}
//void main()
//{
//
//	cout << LastRemaining_Solution(5, 2) << endl;
//}











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