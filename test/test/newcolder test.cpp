#if 0
#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<list>
using namespace std;

/*
//������д�1���������֮��(������1���������)��λΪ1������(����֮���ÿո���������һ����������û�пո�)�����û�������-1��
char t[10000];
int isprime(int t)
{
	if (t == 2 || t == 3)
		return 0;
	for (int i = 2; i <= (t / 2); i++)
	{
		int x = t / i;
		if (x*i == t)
		{
			return 0;
		}
	}
	return t;
}

int main()
{
	int n;
	cin >> n;
	int flag = 0;
	for (int i = 2; i < n; i++)
	{
		int r = isprime(i);
		if (r)
		{
			sprintf(t, "%d", r);
			// _itoa_s(isprime(n),t,10);
			string s(t);
			if (s[s.size() - 1] == '1')
			{
				cout << r<<" ";
				flag++;
				s.clear();
			}
		}
	}
	if (flag == 0)
		cout << -1;
}
*/

/*����������֡�
���������ļ��������ţţ�ڼ��ر����ģ�������������һ��С��Ϸ����Ϸ����Ϊ�����ַ���������Ϊż��λ�����ֽ��з�ת������ת��Ľ�����������
1234  ->  "1432"*/
/*
string change(string number) {
	if (number == "")
		return "";
	int left = 0;
	int right = number.size() - 1;
	for (int i=1;left < right; i++,left++,right--)
	{
		if (i%2==0)
		{
			std::swap(number[left], number[right]);
		}

	}
	return number;
}
void main()
{
	string s = "1234";
	cout << change(s) << endl;
}
*/

/*
int main()
{
	char *s2 = "123";
	string s("123");
	int n = atoi(s.c_str());
	cout << n << endl;
	cout << s<< endl;
	int n2 = atoi(s.c_str[2]);
	cout << n2 << endl;
	//int n3 = atoi(s2[2]);
	//cout << n3<< endl;
}
*/
//sprintf(t, "%d", r);
char help[10000];
#if 0
void main()
{
	printf("%d\n", sizeof(help) / sizeof(help[0]));
	int i = 123;
	sprintf(help, "%d", i);
	printf("%s\n", help);
	printf("%d\n", sizeof(help) / sizeof(help[0]));
	string s(help);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	char* S = "456";
	//������ת��Ϊ�ַ�
}
#endif


/*
�ַ�ת��Ϊ���֣��������⺯��
 1��atoi
	atoi/ atof/ atol   ��int��double,long ת��Ϊ�ַ���
	int atoi( const char *string );
	double atof( const char *string );
	long atol( const char *string );
Convert strings to double (atof), integer (atoi, _atoi64), or long (atol).


 ����ת��Ϊ�ַ����������ֿ⺯��
 1��_itoa   2��sprintf  3��stringstream
 1��itoa ת���������ַ�
char *_itoa( int value, char *string, int radix );
  2��sprintf
  Write formatted data to a string. ֧�ֽ������ʽ��Դת��Ϊ�ַ���
   int sprintf( char *buffer, const char *format [, argument] ... );
 3�������C++,ת��Ϊstring�࣬���� stringstream
 ��Ҫͷ�ļ�#include<sstream>
 ��������ֵ�������ݸ�ʽ��Ϊ�ַ���

*/

#include<sstream>

//void main()
//{
//	
//}
/*
void main()
{
	// ����_itoa
	char buffer1[10] = { 0 };
	int i = 12345;
	_itoa(i, buffer1, 10);
	printf("buffer1= %s\n", buffer1);
	//����sprintf
	double n = 12345.234;
	char buffer2[100] = { 0 };
	sprintf(buffer2, "%lf", n);
	printf("buffer2= %s\n", buffer2);

	//����sstream
	double n2 = 182.382;
	string s;
	stringstream ss;
	ss << n2;
	ss >> s;
	cout << s << endl;
	cout << ss.str() << endl;
//ÿ��ʹ����stringstream��Ҫ���
	ss.clear();
}
*/
//stringstream���������ַ�����ƴ��
//void main()
//{
//	string s1 = "1234";
//	string s2 = "5678";
//	stringstream ss;
//	ss.clear();  //����֮ǰ���ڵĴ����־
//	ss << s1 << "*" << s2;
//	cout << ss.str() << endl;
//	ss.str("");//��ss�ײ�ά����string������Ϊ""���ַ���
//	ss << "qwe";
//	cout << ss.str() << endl;
//}
/*
void main()
{
	// ���� atoi atol
	char* s = "123";
	char* s = "456";
	//���ַ�ת��Ϊ����
	int i =atoi(s);//����ַ�����С�����ᷢ���ضϣ�����atoi����
	cout << i << endl;   //i=456
	char* s2 = "-9.12E-3";
	float x = atol(s2);
	printf("x=%e\n", x);
	cout << x << endl;
}
*/


//
//void main()
//{
//	// ����_itoa
//	char buffer1[10] = { 0 };
//	int i = 12345;
//	_itoa(i, buffer1, 10);
//	printf("buffer1= %s\n", buffer1);
//	//����sprintf
//	double n = 12345.234;
//	char buffer2[100] = { 0 };
//	sprintf(buffer2, "%lf", n);
//	printf("buffer2= %s\n", buffer2);
//
//	//����sstream
//	double n2 = 182.382;
//	string s;
//	stringstream ss;
//	ss << n2;
//	ss >> s;
//	cout << s << endl;
//	cout << ss.str() << endl;
//	//ÿ��ʹ����stringstream��Ҫ���
//	ss.clear();
//}
/*
class B;
class A {
	friend class B;
	int i;
};
class B
{
	
	A *p;
public:
	B()
	{
		p = new A;
	}
	~B()
	{
		delete p;
	}
};
void sayHello(B b)
{ }
int main()
{
	B b;
	sayHello(b);
}
*/
#include<vector>
//bool Find(int target, vector<vector<int> > array) {
//	int row = array.size();
//	int col = array[1].size();
//	int i = 0, j = col - 1;
//	while (1)
//	{
//		while (i<row&&target>array[i][j])
//			i++;
//		if (i >= row)
//			return false;
//		while (j >= 0 && target < array[i][j])
//			j--;
//		if (j < 0)
//			return false;
//		if (target == array[i][j])
//			return true;
//	}
//}
//int main()
//{
//	vector<vector<int> > v = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
//	cout << Find(19,v) << endl;
//	vector<vector<int> > v2 = { {1} };
//	cout << v2.size() << endl;
//	cout << v2[0].size() << endl;
//}
/*
void replaceSpace(char *str, int length) {
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ' ')
			count++;
	}
	char *help = new char[length + 2 * count];
	int j = length + 2 * count;
	for (int i = length + 2 * count; i >= 0; i--)
	{
		if (str[i] != ' ')
			help[j--] = str[i];
		else
		{
			help[j--] = '0';
			help[j--] = '2';
			help[j--] = '%';
		}
	}
	strcpy(str, help);
}
*/
#include<algorithm>
//int maxSubArray(vector<int>& nums) {
//	//dp[i]=max(dp[i-1],dp[i-1]+nums[i])
//	vector<int> dp(nums.size() + 1, 0);
//	dp[0] = nums[0];
//	for (int i = 1; i < nums.size(); i++)
//	{
//		dp[i] = max(nums[i], dp[i - 1] + nums[i]);
//	}
//	int Max = dp[0];
//	for (int i = 1; i < nums.size(); i++)
//	{
//		Max = max(Max, dp[i]);
//	}
//	return Max;
//}
//void main()
//{
//	vector<int> v = { -2,1,-3,4,-1,2,1,-5,4 };
//	cout << maxSubArray(v) << endl;
//	//char* str = "We Are Happy.";
//	// replaceSpace(str, strlen(str));
//	 //cout << str << endl;
//}
//int maxSubArray(vector<int>& nums) {
//	int dp = nums[0], predp = nums[0];
//	int Maxprice = nums[0];
//	for (int i = 1; i < nums.size(); i++)
//	{
//		dp = max(nums[i], predp + nums[i]);
//		Maxprice = max(Maxprice, dp);
//		predp = dp;
//	}
//	return Maxprice;
//}
//int maxProfit(vector<int>& prices) {
//	/*
//	������ƱҲ���Բ��ò��
//	����ת��Ϊ���������������Ӷκ;����������
//	*/
//	if (prices.size() == 0)
//		return 0;
//	vector<int>b(prices.size() - 1, 0);
//	for (int i = 0; i < prices.size() - 1; i++)
//	{
//		b[i] = prices[i + 1] - prices[i];
//	}
//	return maxSubArray(b)<0? 0: maxSubArray(b);
//}
//void main()
//{
//	vector<int> v = { 7,6,4,3,1};
//	cout << maxProfit(v) << endl;
//}
//double Power(double base, int exponent) {
//		if (exponent == 0)
//			return 1;
//		if (base == 0)
//			return 0;
//		return base * Power(base, exponent - 1);
//}
//void main()
//{
//	cout << Power(2.3,3) << endl;
//	cout<<2.3*2.3*2.3 << endl;
//}
//vector<int> vis, nans, nu;
//vector<vector<int> > ans;
//int n;
//void dfs2(int first,int last)
//{
//    if(nans.size()==n)
//    {
//        ans.push_back(nans);
//        return;
//    }
//   for(int i=first; i<=last; i++)
//        {
//             nans.push_back(nu[i]);
//            swap(nu[i],nu[first]);
//               dfs2(i+1,last);
//                 swap(nu[i],nu[first]);
//               nans.pop_back();
//           }
//       
//}
//    vector<vector<int>> permute(vector<int>& nums) {
//        if(nums.size()==0)
//        return ans;
//        n=nums.size();
//        nu=nums;
//        dfs2(0,n-1);
//        return ans;
//    }
//vector<vector<int>> vis;
//int m, n;
//vector<int> dx = { 1,-1,0,0 };
//vector<int> dy = { 0,0,1,-1 };
//bool dfs(int pos, int i, int j, vector<vector<char>>&  board, string word)
//{
//	if (pos == word.size())
//		return true;
//		for (int d = 0; d < 4; d++)
//	{
//		int ii = i + dx[d];
//		int jj = j + dy[d];
//		if (ii < 0 || ii >= m || jj < 0 || jj >= n)
//			continue;
//		if (vis[i][j] == 0)
//			continue;
//		if (board[ii][jj] == word[pos])
//		{
//			vis[ii][jj] = 1;
//			if (dfs(pos + 1, ii, jj, board, word))
//				return true;
//			vis[ii][jj] = 0;
//		}
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
//			if (board[i][j] == word[0])
//			{
//				vis[i][j] = 0;
//				if (dfs(1, i, j, board, word))
//					return true;
//				vis[i][j] = false;
//			}
//		}
//	}
//	return false;
//}
//void main()
//{
//	vector<vector<char>> board = { {'A', 'B', 'C', 'E'},
//		{'S', 'F', 'C', 'S'},
//	{'A', 'D', 'E', 'E'} };
//	string word ("ABCCED");
//	cout << exist(board, word) << endl;
//}
//
//int ans;
//vector<string> list;
//bool ifvalid(int row, int col, int n)
//{
//	//�ȶ���һ�н����ж�
//	for (int j = 0; j < n; j++)
//	{
//		//�ж������һ���лʺ�
//		if (list[row][j] == 'Q')
//			return false;
//	}
//	//����һ�н����ж�
//	for (int i = 0; i < n; i++)
//	{
//		//�ж������һ���лʺ�
//		if (list[i][col] == 'Q')
//			return false;
//	}
//	//�Խ���  \
//       for(int k=1; k<=min(row,col); k++)
//	{
//		//�ж������һ���лʺ�
//		if (list[row - i][col - i] == 'Q')
//			return false;
//	}
//	//���Խ���  /
//	for (int i = 1; i <= min(row, n - 1 - col); i++)
//	{
//		//�ж������һ���лʺ�
//		if (list[row - i][col + i] == 'Q')
//			return false;
//	}
//	return true;
//
//}
//void dfs(int n, int pos)
//{
//	if (pos == n)
//	{
//		ans++;
//		return;
//	}
//	for (int j = 0; j < n; j++)
//	{
//		if (ifvalid(pos, j, n))//�ж����λ���Ƿ�Ϸ�
//		{
//			list[pos][j] = 'Q';//�ԳƵĻ���
//			dfs(n, pos + 1);
//			list[pos][j] = '.';
//		}
//	}
//}
//int totalNQueens(int n) {
//	list.assign (n, string(n, '.'));
//	dfs(n, 0);
//	return ans;
//}
//void main()
//{
//	cout<<totalNQueens(4);
//}

//string LeftRotateString(string str, int n) {
//	int len = str.size();
//	if (n == 0 || n % len == 0)
//		return str;
//	int l = n % len;
//	string ret(str.c_str() + n );
//	for (int i = 0; i < n; i++)
//	{
//		ret += str[i];
//	}
//	return ret;
//}
//void main()
//{
//	string s("abcXYZdef");
//	string ret("qw");
//	ret.insert(ret.begin(), s.begin() + 3, s.begin() + 6);
//	cout << ret << endl;
//	cout << *(s.begin() + 6) << endl;
//	/*cout << LeftRotateString(s, 3) << endl;;
//	cout << "4%2= " << 4%2  << endl;*/
//}

//string ReverseSentence(string str) {
//	if (str == "")
//		return "";
//	string ret;
//	int j = 0;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] == ' ')
//		{
//			ret.insert(ret.begin(), str.begin() + j, str.begin() + i);
//			ret.insert(ret.begin(), ' ');
//			j = i + 1;
//		}
//		if (str[i+1] == '\0')
//		{
//			ret.insert(ret.begin(), str.begin() + j, str.begin() + i+1);
//		}
//	}
//	return ret;
//}
//void main()
//{
//	string s("student.           a   am      I");
//	cout << ReverseSentence(s) << endl;
//	reverse(s.begin(), s.end());
//	cout <<s << endl;
//}
//bool IsContinuous(vector<int> numbers) {
//	//���ֵ-��Сֵ+1<=5  Ҳ�������ظ�ֵ
//	int count = 0;
//	bool vis[14];
//	int maxval = 0, minval = 14;
//	for (auto e : numbers)
//	{
//		if (e == 0)
//			count++;
//		else
//		{
//			if (e != 0 && vis[e] == 1)//��ֹ���ظ�ֵ
//				return false;
//			maxval = max(maxval, e);
//			minval = min(minval, e);
//			vis[e] = 1;
//		}
//	}
//	if (count == 4)
//		return true;
//	return (maxval - minval + 1) <= 5;
//}
//void main()
//{
//	vector<int> v = { 0,3,2,6,4 };
//	cout << IsContinuous(v) << endl;
//}
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
		for (; i < m; i++)
		{
			if (it == li.end())
				it = li.begin();
		}
		it = li.erase(it);
	}
	return *it;
}
void main()
{
	
	cout << LastRemaining_Solution(11, 3) << endl;
}




#endif