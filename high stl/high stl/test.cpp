#if 0
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<stdlib.h>
using namespace std;
//class Solution {
//public:
//	static string addStrings(string num1, string num2) {
//		char* str1 = new char[num1.size() + 1];
//		char* str2 = new char[num2.size() + 1];
//		strcpy(str1, num1.c_str());
//		strcpy(str2, num2.c_str());
//		strcat(str1, str2);
//		return   string(str1);
//	}
//private:
//	string s1;
//	string s2;
//};
//void main()
//{
//	string s1 = "1234";
//	string s2 = "0";
//	cout << s1.rfind('2') << endl;
//	cout << s1.size() << endl;
//	//cout << Solution::addStrings(s1, s2) << endl;
//}
//int main(void)
//{
//	char buf[] = "hello@boy@this@is@heima";
//	char*temp = strtok(buf, "@");
//	char *str = new char[1000];
//	memset(str,'\0', 1000);
//	while (temp)
//	{
//		strcat(str, temp);
//		temp = strtok(NULL, "@");
//	}
//	cout << str << endl;
//	return 0;
//}
//int main()
//{
//	string s(".,");
//	if (s.size() == 0)
//		cout << true << endl;
//	int left = 0;
//	int right = (s.size() - 1);
//	int flag2 = 0;
//	for (int i = 0; i < s.size() - 1; i++)
//	{
//		if (s[i] != ' ')
//			flag2--;
//	}
//	if (flag2 == 0)
//		return true;
//	while (left < right)
//	{
//		while (!(isalpha(s.c_str()[left]) || (s[left] >= '0'&&s[left] <= '9')))
//		{
//			if (left != right)
//				left++;
//			else
//			{
//				cout << false << endl;
//				return 1;
//			}
//
//		}
//		while (!(isalpha(s.c_str()[right]) || (s[right] >= '0'&&s[right] <= '9')))
//		{
//			if (left != right)
//				right--;
//			else
//			{
//				cout << false << endl;
//				return 1;
//			};
//
//		}
//		if (tolower(s.c_str()[left]) == tolower(s.c_str()[right]))
//		{
//			left++;
//			right--;
//		}
//		else
//		{
//			cout << false << endl;
//			return 1;
//		}
//	}
//	cout << true << endl;
//}

//void _reverse(string::iterator pos1, string::iterator pos2)
//{
//	while (pos1< pos2)
//	{
//		std::swap(*pos1, *pos2);
//			pos1++;
//		pos2--;
//	}
//}
//string reverseStr(string s, int k) {
//	if (s.size() == 0 || s.size() == 1)
//		return s;
//	size_t size = s.size();
//	int n = size % 2*k;
//	int n1 = size / (2*k);
//	for (int i = 0; i < n1; i++)
//	{
//		string::iterator first = s.begin() + k * 2*i;
//		string::iterator last = first + k;
//		_reverse(first, last-1);
//	}
//	size_t y = size - 2*k*n1;
//	if (y == 0)
//		return s;
//	else
//	{
//		if (y < k)
//		{
//			_reverse(s.begin() + 2*k*n1, s.end()-1);
//			return s;
//		}
//		if (y >= k)
//		{
//			_reverse(s.begin() + 2 * k*n1, s.begin() + 2 * k*n1 + k-1);
//			return s;
//		}
//	}
//}
//void main()               //  abcdefg       "bacdfeg"
//{
//	string s1("abcdefg"); 
//	cout << reverseStr(s1, 2) << endl;
//
//}
//
//	void _reverse(string::iterator pos1, string::iterator pos2)
//	{
//		while (pos1 < pos2)
//		{
//			std::swap(*pos1, *pos2);
//			pos1++;
//			pos2--;
//		}
//	}
//	string reverseWords(string s) {
//		if (s.size() == 0 || s.size() == 1)  //空串或只有一个字符返回
//			return s;
//		string::iterator it = s.begin();
//		auto first = it;
//		auto last = it;
//		while ((*it) != '\0')
//		{
//			first = it;
//			last = first;
//			while ((*it != ' '))
//			{
//				it++;
//				if (it == s.end())
//					break;
//			}
//			last = it ;
//			_reverse(first, last-1);
//			if (it == s.end())
//				break;
//			it++;
//		}
//		return s;
//	}
//void main()
//{
//	string s1("contest");
//	cout << reverseWords(s1) << endl;
//}

//
//string _add(string num1, string num2) {
//	int carry = 0;
//	string ret;
//	int sum = 0;
//	for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0; i--, j--)
//	{
//		sum = carry;
//		sum += i >= 0 ? num1[i] - '0' : 0;
//		sum += j >= 0 ? num2[j] - '0' : 0;
//		carry = sum / 10;
//		ret.insert(ret.begin(), sum % 10 + '0');
//	}
//	if (carry == 1)
//		ret.insert(ret.begin(), 1 + '0');
//	return ret;
//}
//string multiply(string num1, string num2) {
//	string ret("0");
//	if ((num1[0] == '0') || (num2[0] == '0'))
//		return ret;
//	int carry = 0;
//	string tmp1, tmp2;
//	int sum = 0;
//	for (int j = num2.size() - 1; j >= 0; j--)
//	{
//		carry = 0;
//		sum = 0;
//		for (int i = num1.size() - 1; i >= 0; i--)
//		{
//			sum = carry;
//			sum = sum + (num2[j] - '0')*(num1[i] - '0');
//			carry = sum / 10;
//			tmp1.insert(tmp1.begin(), sum % 10 + '0');
//		}
//		if (carry > 0)
//			tmp1.insert(tmp1.begin(), carry + '0');
//		int t = j;
//		while (t != num2.size() - 1)
//		{
//			t++;
//			tmp1.insert(tmp1.end(), '0');
//		}
//		ret = _add(ret, tmp1);
//		tmp1.clear();
//	}
//	return ret;
//}
//void main()
//{
//	string s1("0");
//	string s2("123");
//	cout << multiply(s1, s2) << endl;
//  
//}
//int main()
//{
//	string str;
//	cin >> str;
//	int i;
//		for (i = 0; i < str.size(); i++)
//		{
//			size_t left = str.find(str[i]);
//			size_t  right = str.rfind(str[i]);
//			if (left == right)
//			{
//				cout << str[left] << endl;
//				break;
//			}
//		}
//		if (i == str.size())
//			cout << -1 << endl;
//	
//	return 0;
//}
//int main()
//{
//	string str1 = "hello world";
//	string str2 = str1;
//
//	printf("Sharing the memory:\n");
//	printf("/tstr1's address: %x\n", str1.c_str());
//	printf("/tstr2's address: %x\n", str2.c_str());
//
//	str1[1] = 'q';
//	str2[1] = 'w';
//
//	printf("After Copy-On-Write:\n");
//	printf("/tstr1's address: %x\n", str1.c_str());
//	printf("/tstr2's address: %x\n", str2.c_str());
//
//	return 0;
//}
/*
int main()
{
	string str1 = "hello world";
	string str2 = str1;
	printf("/tstr1's address: %x\n", str1.c_str());
	printf("/tstr2's address: %x\n", str2.c_str());
	//const char*s = str1.c_str();
	//const char*s2 = str1.c_str();
	//printf("s's address: %x\n", s);
	//printf("s2's address: %x\n", s2);;
	str1[0] = 'q';
	str2[0] = 'w';
	printf("发生写时拷贝:\n");
	printf("str1 的地址: %x\n", str1.c_str());
	printf("str2 的地址: %x\n", str2.c_str());
	//printf("str1 的地址: %d\n", &(str1.c_str()));
	//printf("str2 的地址: %d\n", &(str2.c_str()));
	cout << "str1=" << str1 << endl;
	cout << "str2=" << str2 << endl;

	return 0;
}
*/

//int singleNumber(vector<int>& nums) {
//	for (int i = 0; i < nums.size(); i++)
//	{
//		vector<int> ::iterator left = find(nums.begin(), nums.end(), nums[i]);
//		vector<int> ::reverse_iterator right = find(nums.rbegin(), nums.rend(), nums[i]);
//		//if (left- right)
//			return *left;
//	}
//	return -1;
//}
//void main()
//{
//	vector<int> nums = { 2,2,1 };
//	vector<int> ::iterator left = find(nums.begin(), nums.end()-1, nums[1]);
//	vector<int> ::iterator right = find(nums.rbegin, nums.rend(), nums[1]);
	/*if (left == right)
		cout <<"==" << endl;*/



		/*vector<int> ::iterator it =nums.end()-1;
		while (it != nums.begin())
		{
			cout << *it << " ";
			it--;
		}*/
		////}
		//int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
		//	*returnSize = numRows;//returnSize是真相一个整数的指针，表示返回杨辉三角的行数 = 输入numRows
		//	*returnColumnSizes = (int*)malloc(numRows * sizeof(int));//returnColumnSizes是指向一个数组的指针，数组元素为对应行的元素个数
		//	int **res = (int**)malloc((*returnSize) * sizeof(int*));//res是一个指针，它指向的是由指针构成的数组，每个指针都指向对应的三角的一行数；res也是二维数组
		//	int i = 0;
		//	for (; i < *returnSize; i++) {
		//		(*returnColumnSizes)[i] = i + 1;
		//		res[i] = (int*)malloc((*returnColumnSizes)[i] * sizeof(int));
		//		res[i][0] = 1;
		//		res[i][i] = 1;
		//	}
		//	for (i = 2; i <= numRows - 1; i++) {
		//		for (int j = 1; j < i; j++) {
		//			res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
		//		}
		//	}
		//	return res;
		//
		//}
		//void main()
		//{
		//	int s[5][5] = generate(5,5,5);
		//	for (int i = 0; i < 5; i++)
		//	{
		//		for (int j = 0; j < 5; j++)
		//		{
		//			cout << s[i][j]<<" ";
		//		}
		//		cout << endl;
		//	}
		//}


		//class Solution {
		//public:
		//	vector<vector<int>> generate(int numRows) {
		//		vector<vector<int>> vv;
		//		// 先开辟杨辉三角的空间
		//		vv.resize(numRows);
		//		for (size_t i = 1; i <= numRows; ++i)
		//		{
		//			vv[i - 1].resize(i, 0);
		//			// 每一行的第一个和最后一个都是1
		//			vv[i - 1][0] = 1;
		//			vv[i - 1][i - 1] = 1;
		//		}
		//		for (size_t i = 0; i < vv.size(); ++i)
		//		{
		//			for (size_t j = 0; j < vv[i].size(); ++j)
		//			{
		//				if (vv[i][j] == 0)
		//				{
		//					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
		//				}
		//			}
		//		}
		//		return vv;
		//	}
		//};
		//int fun(int x)
		//{
		//	int sum = x;
		//	if (x > 0)
		//		cout<<(sum += fun(x - 1))<<" ";
		//	return sum;
		//}
		//int main()
		//{
		//	int x = 5;
		//	fun(x);
		//	//cout<<"sum="<<fun(x)<<endl;
		//}

	/*	int removeDuplicates(vector<int>& nums) {
			int pos1, pos2;
			int tmp;
			int count = 0;
			if (nums.size() == 2)
			{
				if (nums[0] == nums[1])
					return 1;
				else
				return 2;
			}
			else
			for ( pos1 = 0; pos1 < nums.size(); ) {
				 pos2 = pos1 + 1;
				 tmp =nums[ pos2 + 1];
				if (nums[pos2] == nums[pos1])
				{
					while (pos2<nums.size()-1)
					{
						nums[pos2] = nums[pos2 + 1];
						pos2++;
					}
				}
				if (nums[pos1] != tmp)
					pos1++;
				if (nums[pos1] == nums[nums.size() - 1])
					break;
			}
			return pos1+1;
		}*/
		//int removeDuplicates(vector<int>& nums)
		//{
		//	先处理特殊情况，否则会产生执行错误
		//	if (nums.size() == 0)  //所给数组为空
		//		return 0;
		//	auto itr1{ nums.begin() };  //指针1指向第一个元素
		//	auto itr2{ nums.begin() + 1 };  //指针2指向第二个元素
		//	for (itr2; itr2 != nums.end(); ++itr2)  //遍历数组
		//	{
		//		if (*itr2 > * itr1)  //发现和指针1不相同的数
		//		{
		//			itr1 += 1;  //指针1向后移动一个元素
		//			*itr1 = *itr2;  //修改指针1的值
		//		}
		//	}
		//	return itr1 - nums.begin() + 1;  //返回数组长度
		//}
//int singleNumber(vector<int>& nums) {
//	for (int i = 0; i < nums.size()-1; i++)
//	{
//		auto first = find(nums.begin(), nums.end(), nums[i]);
//		auto second = find(first + 1, nums.end(), nums[i]);
//		if (second == nums.end())
//			return *first;
//	}
//	return nums[nums.size() - 1];
//}
//void main()
//{
//	vector<int> v = { 0,0,1,1,1,2,2,3,3,4 };
//	cout << singleNumber(v) << endl;
//
//}


//typedef char* ht[5];
//int main()
//{
//	ht h;
//	int i;
//	for ( i = 0; i < 5; ++i)
//	{
//		h[i] = NULL;
//	}
//}
//typedef char* HashTable[4];
//void main()
//{
//	HashTable pht;
//	for (int i = 0; i < 4; ++i)
//	{
//		pht[i] = NULL;
//	}
//}

//vector<int> singleNumber(vector<int>& nums) {
//	int sum = 0;
//	for (auto e : nums)
//	{
//		sum = sum ^ e;
//	}
//	int k = sum & (-sum);
//	vector<int> v = { 0,0 };
//	for (auto e : nums)
//	{
//		if (e | k == e)
//			v[0] = v[0] ^ nums;
//		else
//			v[1] = v[1] ^ nums;
//	}
//	return v;
//}
//int MoreThanHalfNum_Solution(vector<int> numbers) {
//	sort(numbers.begin(), numbers.end());
//	int mid = numbers[numbers.size() / 2]
//		int count = 0;
//	for (int i = 0; i < numbers.size(); i++)
//	{
//		if (numbers[i] == mid)
//			count++;
//	}
//	if (count > numbers.size() / 2)
//		return mid;
//	else
//		return 0;
//}
//void main()
//{
//	int a = 5, b = 6;
//	int c = a ^ b;
//	cout << "c= "<<c << endl;
//	c = 1228;
//	int d = c & (-c);
//	cout << "d= " << d << endl;
//}

//
//void main()
//{
//	string digits("92");
//	int Max = 9;
//	vector<string> x(9);
//	for (int i = 0; i < digits.size(); i++)
//	{
//		if (digits[i] == (9 + '0'))
//		{
//			x[i].append("wxyz");
//		}
//		else
//		{
//			for (int j = 0; j <= 3; j++)
//			{
//				 x[i].push_back(digits[i] +j+47);
//			}
//		}
//	}
//	for (auto e : x)
//		cout << e << " ";
//	cout << endl;
//}

//void main()
//{
//	vector<int> v1;
//	vector<int> v2(10);
//	vector<int> v3(10,1);
//	string s1;
//	s1.append("asdsa");
//	s1.push_back('q');
//	cout << s1 << endl;
//	vector<int> v;
//	v.insert(v.begin(), 4);
//	v.push_back(5);
//	cout << v[1] << endl;
//	vector<string> vv;
//	vv.push_back("as");
//	cout << vv[0] << endl;
//}

//void main()
//{
//	string s1("qwe");
//	string s2("rty");
//	string s3;
//	s3 = s1 + s2;
//	cout << s3 << endl;
//
//}
//vector<string> combinations(vector<string> v1, string v2)
//{
//	int j = 0;
//	int max = v1.size()*v2.size();
//	vector<string> ret(max);
//	for (int i = 0; i < max; i++)
//	{
//		for (int j = 0; j < v1.size(); j++)
//		{
//			if (v2.size() == 3)
//			{
//				ret[i++] = v1[j] + v2[0];
//				ret[i++] = v1[j] + v2[1];
//				ret[i++] = v1[j] + v2[2];
//			}
//			else
//			{
//				ret[i++] = v1[j] + v2[0];
//				ret[i++] = v1[j] + v2[1];
//				ret[i++] = v1[j] + v2[2];
//				ret[i++] = v1[j] + v2[3];
//			}
//		}
//	}
//	return ret;
//}
//vector<string> letterCombinations(string digits)
//{
//	vector<string> x(digits.size());
//	for (int i = 0; i < digits.size(); i++)
//	{
//		if (digits[i] == (9 + '0'))
//		{
//			x[i].append("wxyz");
//		}
//		else {
//			for (int j = 0; j < 3; j++)
//			{
//				x[i].push_back('a' + (digits[i] - '0' - 2) * 3 + j);
//			}
//		}
//	}
//	vector<string> ret(x[0].size());
//	for (int i = 0; i < x[0].size(); i++)
//		ret[i].push_back(x[0][i]);
//
//	for (int i = 1; i < digits.size(); i++)
//	{
//		ret = combinations(ret, x[i]);
//	}
//	return ret;
//}
//vector<string> letterCombinations(string digits) {
//	vector<string> result;
//	if (digits.size() == 0) return result;
//	vector<string> v = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//	result.push_back("");
//	for (int i = 0; i < digits.size(); i++) {
//		int size = result.size();
//		for (int j = 0; j < size; j++) {
//			string word = result[j];
//			result[j] += v[digits[i] - '2'][0];
//			for (int k = 1; k < v[digits[i] - '2'].size(); k++) {
//				result.push_back( v[digits[i] - '2'][k]);
//			}
//		}
//	}
//	return result;
//}
//void main()
//{
//	string digits("29");
//	vector<string> v = letterCombinations(digits);
//	for (auto e : v)
//		cout << e << " ";
//	cout << endl;
//}

//int FindGreatestSumOfSubArray(vector<int> array) {
//	int Max = array[0];
//	for (int i = 1; i < array.size(); i++) {
//		if (array[i - 1] > 0)
//			array[i] += array[i - 1];
//		else
//			array[i] += 0;
//		Max = max(Max, array[i]);
//	}
//	return Max;
//}
//int FindGreatestSumOfSubArray(vector<int> array) {
//	if (array.size() == 0)
//		return 0;
//	int sum = array[0];
//	int tmpsum = array[0];
//	for (int i = 1; i < array.size(); i++) {
//		if (tmpsum <= 0)
//			tmpsum = array[i];  // array[i] += array[i - 1] > 0 ? array[i - 1] : 0;
//		else
//			tmpsum = tmpsum + array[i];
//		if (tmpsum > sum)
//			sum = tmpsum;
//	}
//	return sum;
//
//}
//void main()
//{
//	vector<int> ar = { -6,-3,-2,-7,-15,-1,-2,-2 };
//	cout << FindGreatestSumOfSubArray(ar) << endl;
//}


//void main()
//{
//	stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.top();
//	vector<string> v1(5);
//	for (int i = 0; i < 5; i++)
//		v1[i].push_back('a' + i);
//	for (int i = 0; i < 5; i++)
//		cout << v1[i] << " ";
//	cout << endl;
//	vector<string> v2;
//	/*v2.push_back("dasd");
//	v2.push_back("asds");
//	v2.push_back("hj");*/
//	for (int i = 0; i < 5; i++)
//		v2.push_back("a" + 'b'+i);
//	for (int i = 0; i < 5; i++)
//		cout << v2[i] << " ";
//	cout << endl;
//}
//class MinStack {
//public:
//	/** initialize your data structure here. */
//	MinStack() {
//		stack<int> s1;
//	}
//	void push(int x) {
//		if (s1.empty())
//		{
//			s1.push(x);
//			s1.push(x);
//		}
//		else
//		{
//			int top = s1.top;
//			s1.push(x)
//				if (top < x) {
//					s1.push(top);
//				}
//				else {
//					s1.push(x);
//				}
//		}
//	}
//
//	void pop() {
//		s1.pop();
//		s1.pop();
//	}
//
//	int top() {
//		top = s1.top();
//		s1.pop();
//		tmp = s1.top;
//		s1.push(top);
//		return tmp;
//	}
//
//	int getMin() {
//		return s1.top();
//	}
//};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 //
 //
 //bool IsPopOrder(vector<int> pushV, vector<int> popV) {
 //	stack <int> s;
 //	int j = 0;
 //	for (int i = 0; i < pushV.size(); i++)
 //	{
 //		s.push(pushV[i]);
 //		while (s.size() > 0&&popV[j] == s.top())
 //		{
 //			if (j == popV.size()-1)
 //				return true;
 //			j++;
 //			s.pop();
 //		}
 //	}
 //		return false;
 //}
 //void main()
 //{
 //	vector<int> v1 = { 1,2,3,4,5 };
 //	vector<int> v2 = { 2,1,4,3,5 };
 //	cout << IsPopOrder(v1, v2) << endl;
 //
 //}

//int evalRPN(vector<string>& tokens) {
//	stack<int> s;
//	for (int i = 0; i < tokens.size(); i++) { 
//		while (!(tokens[i]=="+"|| tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")) {
//			s.push(atoi(tokens[i].c_str()));
//			i++;
//		}
//		int tmp1 = s.top();
//		s.pop();
//		int tmp2 = s.top();
//		s.pop();
//		int tmp3;
//		if (tokens[i][0] == '+')
//		{
//			tmp3 = tmp2 + tmp1;
//			s.push(tmp3);
//		}
//		if (tokens[i][0] == '-')
//		{
//			tmp3 = tmp2 - tmp1;
//			s.push(tmp3);
//		}
//		if (tokens[i][0] == '*')
//		{
//			tmp3 = tmp2 * tmp1;
//			s.push(tmp3);
//		}
//		if (tokens[i][0] == '/')
//		{
//			tmp3 = tmp2 / tmp1;
//			s.push(tmp3);
//		}
//	}
//	return s.top();
//}
//void main()
//{
//	vector<string> v = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
//	cout << evalRPN(v) << endl;
//}
//class MyQueue {
//public:
//	/** Initialize your data structure here. */
//	MyQueue() {
//
//	}
//
//	/** Push element x to the back of queue. */
//	void push(int x) {
//		if (s2.empty())
//			s2.push(x);
//		s1.push(x);
//	}
//
//	/** Removes the element from in front of queue and returns that element. */
//	int pop() {
//
//		int tmp = s2.top();
//		s2.pop();
//		while (!(s1.empty())) {
//			int tmp1 = s1.top();
//			s1.pop();
//			s2.push(tmp1);
//		}
//		s2.pop();
//		int top = s2.top();
//		while (!(s2.empty())) {
//			int tmp1 = s2.top();
//			s2.pop();
//			s1.push(tmp1);
//		}
//		s2.push(top);
//		return tmp;
//	}
//
//	int peek() {
//		return s2.top();
//	}
//
//	/** Returns whether the queue is empty. */
//	bool empty() {
//		if (s1.empty())
//			return true;
//		return false;
//	}
//private:
//	stack<int> s1;
//	stack<int> s2;
//};
//void main()
//{
//	MyQueue queue;
////	cout << queue.peek() << endl; // 返回 1
//	queue.push(1);
//	queue.push(2);
//	cout << queue.peek() << endl; // 返回 1
//	queue.pop();   // 返回 1
//	cout << queue.empty() << endl;// 返回 false
//	stack<int> s;	
//	cout << s.top() << endl;
//}

//class MyStack {
//public:
//	/** Initialize your data structure here. */
//	MyStack() {
//
//	}
//
//	/** Push element x onto stack. */
//	void push(int x) {
//		q.push(x);
//	}
//
//	/** Removes the element on top of the stack and returns that element. */
//	int pop() {
//		if (q.empty())
//			return -1;
//		int tmp = q.back();
//		while (q.front() != tmp)
//		{
//			int tmp2 = q.front();
//			q.pop();
//			q.push(tmp2);
//		}
//		tmp = q.front();
//		q.pop();
//		return tmp;
//	}
//
//	/** Get the top element. */
//	int top() {
//		return q.back();
//	}
//
//	/** Returns whether the stack is empty. */
//	bool empty() {
//		return q.empty();
//	}
//private:
//	queue<int> q;
//};
//void main()
//{
//	MyStack s;
//	s.push(1);
//	s.push(2);
//	s.push(3);
//	s.pop();
//	cout << s.top() << endl;
//
//}
//int findKthLargest(vector<int>& nums, int k) {
	/*
  priority_queue<int> pq;
  for(auto e:nums)
  pq.push(e);
  for(int i=0;i<k-1;i++)
  {
	  pq.pop();
  }
  return pq.top();
}
//*/
//	sort(nums.begin(), nums.end(), greater<int>());
//	int count = 0;
//	int i;
//	for (i = 0; i < nums.size(); i++)
//	{
//		if (count == k - 1)
//			break;
//		while (i < nums.size() && nums[i] == nums[i + 1])
//			i++;
//			count++;
//	}
//	if (count == k - 1)
//		return nums[i];
//	return -1;
//}
//int main()
//{
//	vector<int> v = {3,2,3,1,2,4,5,5,6};
//	//cout << findKthLargest(v, 2) << endl;
//	cout << findKthLargest(v, 4) << endl;
//	//sort(v.begin(), v.end(),greater<int>());  //<algorithm>
//	//for (auto e : v)
//	//	cout << e << " ";
//	//cout << endl;
//}
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//ListNode* removeElements(ListNode* head, int val) {
//	ListNode* p = head;
//	ListNode* q = head;
//	while (p->next != nullptr)
//	{
//		q = p;
//		p = p->next;
//		if (p->val == val)
//		{
//			if (p->next != nullptr)
//				q->next = p->next;
//			delete p;
//			p = q;
//		}
//	}
//
//	return head;
//}


#endif
