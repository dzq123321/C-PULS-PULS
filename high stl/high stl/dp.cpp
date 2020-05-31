#if 1
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<assert.h>
using namespace std;
//动态规划的出发点在于选和不选
//目前都可以看是比递归更加高级
//给定一堆的数字，怎么选择一些不相邻的数字，使找出最大的和
//给定一个数组 [4 1 2 9 1]  4 +9=13
//int RecSolution(vector<int> & v,int i)
//{
//	//递归出口  i=0 return v[0]  i=1  return max(v[0],v[1])
//	if (i == 0)
//		return v[0];
//	else if (i == 1)
//		return max(v[0], v[1]);
//	//递归方程   max(OPT(i-2)+v[i],OPT(i-1))
//	else
//	{
//		int A = RecSolution(v, i - 2) + v[i];
//		int B= RecSolution(v, i - 1);
//		return max(A, B);
//	}
//
//}
//int DpSolution(vector<int> & v)
//{
//	vector<int> tmp;
//	tmp.resize(v.size());
//	tmp[0] = v[0];
//	tmp[1]= max(v[0], v[1]);
//	for (int i = 2; i < v.size(); i++) {
//		int A = tmp[i - 2] + v[i];//状态转移方程
//		int B = tmp[i - 1];
//		tmp[i]=max(A, B);
//	}
//	return tmp[v.size() - 1];
//}
//void main()
//{
//	vector<int> v = { 1,2,4,1,7,8,3 };
//	cout << RecSolution(v,v.size()-1) << endl;
//	cout << DpSolution(v) << endl;
//
//}


//给定一个数组，在给定一个数字，判断其某些数组元素加起来是否可以等于S,等于返回true,找不到返回false
//bool RecSolution(vector<int> & v,int i,int S)
//{
//	if (i == 0)
//		return v[0] == S;
//	else if (S == 0)
//		return true;
//	else if (v[i] > S)
//		return RecSolution(v, i - 1, S);
//	else
//		return (RecSolution(v, i - 1, S - v[i]) || RecSolution(v, i - 1, S));
//}
//bool DpSolution(vector<int> & v,int S)
//{
//	bool subset[6][10];
//	for (int i = 0; i < 6; i++)
//		subset[i][0] = true;
//	for (int j = 0; j < 10; j++)
//		subset[0][j] = false;
//	subset[0][v[0]] = true;
//	for (int i = 1; i < 6; i++)
//	{
//		for (int j = 1; j < 10; j++)
//		{
//			if (v[i] > S)
//				subset[i][j] = subset[i-1][j];
//			else
//			{
//				int A = subset[i - 1][j];
//				int B = subset[i - 1][j-v[i]];
//				subset[i][j] = A || B;
//			}
//		}
//	}
//	return subset[5][9];
//}
//void main()
//{
//	vector<int> v = { 3,34,4,12,5,2 };
//	int S = 9;
//	cout << RecSolution(v,v.size()-1,S) << endl;
//	cout << DpSolution(v,S) << endl;
//
//}


//找零钱问题，返回个数(假设每种硬币无限)
//递归
//int RecSolution(vector<int> & v, int S)//最少需要几个数
//{
//	int res = INT_MAX;
//	int this_res;
//	//递归出口
//	if (S == 0)
//		return 0;
//	for(auto coin:v)
//	{
//		if (S >= coin)//如果选coin
//			this_res = RecSolution(v, S - coin);
//		if (this_res == -1)
//			continue;
//		else
//			res = min(this_res + 1, res);
//	}
//	if (res == INT_MAX)
//		return -1;
//	return res;
//	//状态转移方程  min(f(v,i-1,S-v[i]),f(v,i-1,S))
//}
////带记事本的递归
//int MemRecSolution(vector<int> & v, int S)//最少需要几个数
//{
//	vector<int> mem(S + 1);
//	if (mem[S] != 0)
//		return mem[S];
//	int res = INT_MAX;
//	int this_res;
//	//递归出口
//	if (S == 0)
//	{
//		mem[S] = 0;
//		return 0;
//	}
//	for (auto coin : v)
//	{
//		if (S >= coin)//如果选coin
//			this_res = RecSolution(v, S - coin);
//		if (this_res == -1)
//			continue;
//		else
//			res = min(this_res + 1, res);
//	}
//	if (res == INT_MAX)
//	{
//		mem[S] = -1;
//		return -1;
//	}
//	return res;
//	//状态转移方程  min(f(v,i-1,S-v[i]),f(v,i-1,S))
//}
////动态规划
//int DpSolution(vector<int>& v, int amount)
//{
//	vector<int> dp(amount + 1, INT_MAX -1);
//	dp[0] = 0;
//	for (int coin : v)
//	{
//		for (int i = coin; i <= amount; ++i)
//		{
//			dp[i] = min(dp[i], dp[i - coin] + 1);
//		}
//	}
//	return dp[amount] >= INT_MAX ? -1 : dp[amount];
//}
//void main()
//{
//	vector<int> v = { 1,2,5,4,8 };
//	int S = 10;
//	cout << RecSolution(v, S) << endl;
//	cout << MemRecSolution(v, S) << endl;
//	cout << DpSolution(v, S) << endl;
//
//	//cout << DpSolution(v, S) << endl;
//}
//bool DpSolution(vector<int> & v, int S)
//{
//	bool subset[6][10];
//	for (int i = 0; i < 6; i++)
//		subset[i][0] = true;
//	for (int j = 0; j < 10; j++)
//		subset[0][j] = false;
//	subset[0][v[0]] = true;
//	for (int i = 1; i < 6; i++)
//	{
//		for (int j = 1; j < 10; j++)
//		{
//			if (v[i] > S)
//				subset[i][j] = subset[i - 1][j];
//			else
//			{
//				int A = subset[i - 1][j];
//				int B = subset[i - 1][j - v[i]];
//				subset[i][j] = A || B;
//			}
//		}
//	}
//	return subset[5][9];
//}
/*
//01背包
const int MV = 1001;
int dp[MV][MV];
int zero_one_pack(vector<int>&v, vector<int>&w, int V)
{
	dp[0][0] = 0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j <= V; j++)
		{
			if(j>=v[i])
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
		}
	}
	return dp[v.size()-1][V];
}
int dp2[MV];//优化空间 从后往前遍历
int Op_zero_one_pack(vector<int>&v, vector<int>&w, int V)
{
	dp2[0] = 0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = V; j >= v[i]; j--)
			dp2[j] = max(dp2[j], dp2[j - v[i]] + w[i]);
	}
	return dp2[V];
}
int dp3[MV];
int Full_Op_zero_one_pack(vector<int>&v, vector<int>&w, int V)//必须放满的01背包，只需加一条判断
{
	memset(dp3, -1, sizeof(dp3));
	dp3[0] = 0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = V; j >= v[i]; j--)
		{
			if(dp3[j-v[i]]!=-1)
			dp3[j] = max(dp3[j], dp3[j - v[i]] + w[i]);
		}
	}
	return dp3[V];
}
//多重背包

int Complete_pack(vector<int>&v, vector<int>&w, int V)
{
	dp2[0] = 0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = v[i]; j <= V; j++)
			dp2[j] = max(dp2[j], dp2[j - v[i]] + w[i]);
	}
	return dp2[V];
}
const int n = 1010;
int dp5[n][n];//这里我们是故意开大，也可以定义int dp[v.size()][V]
int O_Complete_pack(vector<int>&v, vector<int>&w, int V)
{
	dp5[0][0] = 0;//一般动态规划都需要初始化，这里我们dp是全局的，默认元素为0
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 1; j <= V; j++)
		{
			for (int k = 1; k <= j / v[i]; k++)
				if (j >= v[i])
					dp5[i][j] = max(dp5[i - 1][j], dp5[i - 1][j - k * v[i]] + k * w[i]);
		}
	}
	return dp5[v.size() - 1][V];
}

//多重背包有三种方法：1、拆分为01背包（空间和时间复杂度高）2、二进制分解（复杂度n^2logN）3、单调队列优化（代码复杂）
//一般采用二进制分解。二进制分解就是将一个数分解为2^k(1,2,4,8 ...)比如将13 分解为1 2 4 6，则之后就用这个数就可以表示13

int Multiple_pack(vector<int>&v, vector<int>&w, vector<int>&c, int V)
{
	dp2[0] = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (V / v[i] <= c[i])//说明对于v[i]的数量远大于V/[i],则可以将其视为完全背包问题(这一步可有可无，只是剪枝)
			for (int j = v[i]; j <= V; j++)
				dp2[j] = max(dp2[j], dp2[j - v[i]] + w[i]);
		for (int i = 1; i <= c[i]; i <<=1)//进行二进制分解
		{
			c[i] -= i;//减去i
			//调用01背包
			v[i] *= i;
			w[i] *= i;
			for (int j = V; j >= v[i]; j--)
				dp2[j] = max(dp2[j], dp2[j - v[i]] + w[i]);
		}
		v[i] *= c[i];//剩下的c[i]
		w[i] *= c[i];
		for (int j = V; j >= v[i]; j--)
			dp2[j] = max(dp2[j], dp2[j - v[i]] + w[i]);
	}
	return dp2[V];
}
int dpp[MV];
void Zero_one_pack2(int v_i, int w_i, int V)
{
	for (int i = V; i >= v_i; i--)
	{
		dpp[i] = max(dpp[i], dpp[i - v_i] + w_i);
	}
}
void Complete_pack2(int v_i, int w_i, int V)
{
	for (int i = v_i; i <= V; i++)
	{
		dpp[i] = max(dpp[i], dpp[i - v_i] + w_i);
	}
}
int Op1_Multiple_pack(vector<int>&v, vector<int>&w, vector<int> c, int V)
{
	for (int i = 0; i < v.size(); i++)
	{
		//当c[i]的数大于等于允许的最大数量，则直接进行完全背包
		if (V/v[i] <= c[i])
		{
			Complete_pack2(v[i], w[i], V);
			continue;
		}
		//否则进行二进制优化
		for (int j = 1; j <= c[i]; j *= 2)
		{
			//对其进行等价的01背包
			c[i] -= j;
			Zero_one_pack2(j*v[i], j*w[i], V);
		}
		//有可能还剩下一个不是二进制的数，如我们的例子中的5，对其继续进行01背包
		Zero_one_pack2(c[i] * v[i], c[i] * w[i], V);
	}
	return dpp[V];
}





void  main()
{
	vector<int> v = { 3,4,3};
	vector<int> w = { 5,6,7};
	vector<int> c = { 13,2,1 };
	int V = 7;
	//cout << "zero_one_pack= " << zero_one_pack(v, w, V) << endl;
	//cout << "Op_zero_one_pack= " << Op_zero_one_pack(v, w, V) << endl;
	//cout << "Full_Op_zero_one_pack= " << Full_Op_zero_one_pack(v, w, V) << endl;
	//cout << "Complete_pack= " << Complete_pack(v, w, V) << endl;
	//cout << "O_Complete_pack= " << O_Complete_pack(v, w, V) << endl;
	//cout << "Multiple_pack= " << Multiple_pack(v, w, c, V) << endl;
	cout << "Op1_Multiple_pack= " << Op1_Multiple_pack(v, w, c, V) << endl;
	for (int i = 0; i < 10; i++)
		cout << dp3[i] << " ";
	cout << endl;
}
*/

//typedef struct node {
//	int data;
//	struct node* left;
//	struct node* right;
//} Node;
//typedef struct {
//	Node* root;
//}Tree;
//void preorder(Node* node)
//{
//	if (node != NULL)
//	{
//		printf("%d", node->data);
//		preorder(node->left);
//		preorder(node->right);
//	}
//}
//void inorder(Node* node)//中序遍历
//{
//	if (node != NULL)
//	{
//		inorder(node->left);
//		printf("%d", node->data);
//		inorder(node->right);
//	}
//}
//void postorder(Node* node)//中序遍历
//void insert(Tree* tree, int value)
//{
//	Node* node = (Node*)malloc(sizeof(Node));
//	assert(node);
//	node->data = value;
//	node->left = NULL;
//	node->right = NULL;
//	if (tree->root == NULL)
//		tree->root = node;
//	else
//	{
//		Node* tmp = tree->root;
//		while (tmp != NULL)
//		{
//			if (value < tmp->data)
//			{
//				if (tmp->left == NULL)
//				{
//					tmp->left = node;
//					return;
//				}
//				else
//					tmp = tmp->left;
//			}
//			else if (value > tmp->data)
//			{
//				if (tmp->right == NULL)
//				{
//					tmp->right = node;
//					return;
//				}
//				else
//					tmp = tmp->right;
//			}
//		}
//	}
//}
//int get_height(Node* node)
//{
//	if (node == NULL)
//		return -1;
//	int left = get_height(node->left);
//	int right = get_height(node->right);
//	return max(left, right) + 1;
//
//}
//int get_maximumdata(Node* node)
//{
//	if (node == NULL)
//		return -1;
//	int max1 = node->data;
//	int max2 = get_maximumdata(node->left);
//	int max3 = get_maximumdata(node->right);
//	int max = max1;
//	if (max < max2) max = max2;
//	if (max < max3) max = max3;
//	return max;
//}
//int main()
//{
//	int arr[7] = { 6,3,8,2,5,1,7 };
//	Tree tree;
//	tree.root = NULL;
//	int i;
//	for (int i = 0; i < 7; i++)
//	{
//		insert(&tree, arr[i]);
//	}
//	inorder(tree.root);
//	cout << endl;
//	cout << "--------------------------" << endl;
//	preorder(tree.root);
//	cout << endl;
//	cout << get_height(tree.root) << endl;
//	cout << get_maximumdata(tree.root) << endl;
//}


/*
区间dp问题
动态规划：（如果不相邻就变为了贪心问题）
合并堆消费体力问题，每次只能合并相邻的两个堆，消耗的体力为两个堆个数之和，求最少消费的体力
比如 5 8 9 3
5+8=13  消费13体力  13 9 3
9+3=12   消费12体力  13 12
13+12=25  消费25体力
总体力消耗为 13+12+25=50

1、状态表示：  dp[i][j]代表从第i堆到第j堆这个区间合并为一堆消耗的体力
2、状态计算：化整为0  dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+s[j]-s[i-1])
*/
//const int N = 310;
//int n;
//int s[N];//前缀和
//int dp[N][N];
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> s[i], s[i] += s[i - 1];
//	for(int len=2;len<=n;len++)//（当len=1时说明只有一堆，直接返回）区间dp   先枚举区间长度，再枚举区间范围
//		for (int i = 1; i + len - 1 <= n; i++)
//		{
//			int j = i + len - 1;
//			dp[i][j] = 1e8;
//			for (int k = j; k < j; k++)
//				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]);
//		}
//	cout << dp[1][n] << endl;//最终需要求出从1-n范围的
//}


/*
数字的全排列问题
1 2 3 4
*/
//void Recpermutation(vector<int>& ar,int p,int q)
//{
//	if (p == q)   //打印
//	{
//		for (int i = 0; i < 4; i++)
//			cout << ar[i] << " ";
//		cout << endl;
//	}
//	else
//	for(int i=p ; i<= q; i++)
//	{
//		std::swap(ar[i], ar[p]);//先交换
//		Recpermutation(ar, p + 1, q);
//		std::swap(ar[i], ar[p]);
//	}
//}
//vector<int> vis;
//vector<int> nu;
//vector<int> ret;
//int n;
//void dfs(int cur)
//{
//	if (cur == n)
//	{
//		for (int i = 0; i < n; i++)
//			cout << ret[i] << " ";
//		cout << endl;
//		return;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (vis[i] == 0) {
//			vis[i] = 1;//开始选择
//			ret[cur] = nu[i];//记录已经做的选择
//			dfs(cur + 1);//递归
//			vis[i] = 0;//撤销选择
//		}
//	}
//}
//void permutation(vector<int>& ar)
//{
//	sort(ar.begin(), ar.end());
//	int n = ar.size();
//	vector<vector<int>> ans;
//	do {
//		//ans.push_back(ar);
//		for (int i = 0; i <ar.size();i++ )
//			cout << ar[i] << " ";
//		cout << endl;
//	} while (next_permutation(ar.begin(), ar.end()));
//}
//void Dfspermutation(vector<int>& ar)//深度优先遍历
//{
//	n = ar.size();
//	vis.assign(n, 0);
//	ret.assign(n, 0);
//	nu = ar;
//	dfs(0);
//}
//int main()
//{
//	vector<int> ar = {1,2,3,4};
//	//Recpermutation(ar,0,3);	
//	//Dfspermutation(ar);
//	permutation(ar);
//}

//vector<int> vis;
//vector<int> nu;
//vector<int>  nans;
//vector<vector<int> > ans;
//int n;
//vector<vector<int>> permute(vector<int>& nums) {
//	if (nums.size() == 0)
//		return ans;
//	nu = nums;
//	nans.assign(n, 0);
//	vis.assign(n, 0);
//	n = nums.size();
//	//dfs(0);
//	return ans;	
//}

//void dfs(int cur)
//{
//	if (cur == n)
//	{
//		ans.push_back(nans);
//		return;
//	}
//		for (int i = 0; i < n; i++)
//		{
//			if (vis[i] == 0)
//			{
//				vis[i] = 1;
//				nans[cur] = nu[i];
//				dfs(cur + 1);
//				vis[i] = 0;
//			}
//		}
//}
//
//vector<vector<int>> permute(vector<int>& nums) {
//	if (nums.size() == 0)
//		return ans;
//	nu = nums;
//	nans.assign(n, 0);
//	vis.assign(n, 0);
//	n = nums.size();
//	dfs(0);
//	return ans;	
//}
//int main()
//{
//	vector<int> ar = { 1,2,3,4 };
//	//Recpermutation(ar,0,3);	
//	//Dfspermutation(ar);
//	permute(ar);
//}

//vector<int> ans;
//void quick_sort(vector<int>& nums, int left, int right, int k)
//{
//	//从大到小排列
//	if (left >= right)
//		return;
//	int i = left, j = right;
//	while (i < j)
//	{
//		//从right向左找出大于nums[left]
//		while (i < j&&nums[j] < nums[left])
//		{
//			j--;
//		}
//		//从left向右找出小于nums[left]
//		while (i < j&&nums[i] >= nums[left])
//		{
//			i++;
//		}
//		if (i < j)
//			swap(nums[i], nums[j]);
//	}
//	swap(nums[left], nums[i]);
//	if (i - left + 1 == k)
//		return;
//	if (i - left + 1 > k)
//		quick_sort(nums, left, i - 1, k);
//	else
//		quick_sort(nums, i + 1, right, k - (i - left) - 1);
//}
//vector<int> getLeastNumbers(vector<int>& arr, int k) {
//	ans.assign(k, 0);
//	quick_sort(arr, 0, arr.size() - 1, k);
//	for (int i = 0; i < k; i++)
//		ans.push_back(arr[i]);
//	return ans;
//}
//int main()
//{
//	vector<int> v = { 3,2,1};
//	getLeastNumbers(v,2);
//	for (auto e : ans)
//		cout << e << " ";
//	cout << endl;
//	return 0;
//}
//vector<int> v;
//void dfs(vector<int>& data)
//{
//	int i = 0;
//	while (i != data.size())
//	{
//		for (int j = i + 1; j < data.size(); j++)
//		{
//			if (j<data.size() && v[i]>data[j])
//				v[i]++;
//		}
//		i++;
//	}
//}
//int InversePairs(vector<int> data) {
//	if (data.size() == 0)
//		return 0;
//	v.assign(data.size(), 0);
//	dfs(data);
//	int ans=0;
//	for (int i = 0; i < data.size(); i++)
//		ans += v[i];
//	return ans;
//}
//void main()
//{
//	vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 0 };
//	cout << InversePairs(data) << endl;
//}
//vector<int> tmp;
//vector<int> num;
//int ans;
//int merge(vector<int> &num, int left, int mid, int right)
//{
//	int i = left, j = mid + 1;
//	for (int k = 0; k <= right; k++)
//	{
//		if (i == mid + 1)
//		{
//			tmp[k] = num[j];
//			j++;
//		}
//		else if (j == right + 1)
//		{
//			tmp[k] = num[i];
//			i++;
//		}
//		else if (num[i] <= num[j])
//		{
//			tmp[k] = num[i];
//			i++;
//		}
//		else {
//			tmp[k] = num[j];
//			j++;
//			ans += (mid - i + 1);
//		}
//	}
//	for (int i = left; i <= right; i++)
//		num[i] = tmp[i];
//	return ans;
//}
//int mergesort(vector<int> &num, int left, int right)
//{
//	if (left == right)
//		return 0;
//	int mid = left + (right - left) / 2;
//	int x1 = mergesort(num, left, mid);
//	int x2 = mergesort(num, mid + 1, right);
//	if (num[mid] <= num[mid + 1])
//		return x1 + x2;
//	int x3 = merge(num, left, mid, right);
//	return x1 + x2 + x3;
//}
//
//int reversePairs(vector<int> data) {
//	if (data.size() < 2)
//		return 0;
//	num = data;
//	ans = 0;
//	tmp.assign(data.size(), 0);
//	mergesort(num, 0, data.size() - 1);
//	return ans;
//}
//	
//	void main()
//	{
// 		vector<int> num2 = { 3,4,5,7,2,6,8 };
//		cout << reversePairs(num2) << endl;
//		for (auto e : num)
//			cout << e << " ";
//		cout << endl;
//		vector<int> num4;
//		num4 = num2;
//		for (auto e : num4)
//			cout << e << " ";
//	}


/*
4.动态规划
题目：长度为n的数组nums，每次在剩余数组中取一个数字获得最终求和的最大值，求和规则：如果取nums[j]，则sum += nums[j-1] * nums[j] * nums[j+1]，
当j-1<0，则nums[j-1] = 1，当j+1 >= len(n)，则nums[j+1] = 1。其中1<n<500,1<nums[i]<100
例子：nums[4] = {3,1,5,8} 依次取 1,5,3,8 ，得到剩余数组{3,5,8} ,{3,8},{8},{}，得到值为sum = 3*1*5 + 3*5*8 + 1*3*8 + 1* 8*1 = 167为最大值
注意：由于n可能为500，则500！算不了，所以不能用暴力的全排列
dp[i]=max(dp[i-1],nums[j-1] * nums[j] * nums[j+1])
dp[0]=num[0]*num[1];
*/
//
//int dp;
//int predp;
//int ans;
//vector<int>  vis;
//vector<int>  tmp;
//void fun(vector<int>& v,int pos)
//{
//	if (v.size()-1 == pos)
//	{
//		tmp.push_back(dp);
//		return;
//	}
//	int dp = predp = v[0] * v[1];
//	int x = v[0];
//	for (int i = 1; i < v.size(); i++)
//	{
//		if (vis[i] == 1) continue;
//		vis[i] = 1;
//		if (i == v.size() - 1)
//			dp = max(predp, v[i - 1] * v[i]);
//		else
//			dp = max(predp, v[i - 1] * v[i] * v[i + 1]);
//		predp = dp;
//		fun(v, pos + 1);
//		vis[i] = 0;		
//	}
	//for (int i=0;i<v.size();i++)
	//{
	//	if(v[i]!=x)
	//	tmp[i]=v[i];
	//}
	//if (tmp.size() == 1)
	//	return dp + tmp[0];
	///*cout << x;
	//cout << endl;*/
	//int x2=fun(tmp);
//	//return dp+x2;
//}
//void main()
//{
//	vector<int> v = { 3,1,5,8 };
//	vis.assign(v.size(), 0);
//	fun(v,0);
//	for (auto e : tmp)
//		cout << e << " ";
//	cout << ans << endl;
//}
//void main()
//{
//	int tmp,x1, x2, x3, x4, x5;
//	for ( int i = INT_MAX-1; i >= 1000; i--)
//	{
//		 tmp = i;
//		if ((tmp + 1) % 5 == 0)
//		{
//			x1 = (tmp + 1) / 5;
//			tmp -= x1;
//			if ((tmp + 1) % 5 == 0)
//			{
//				x2 = (tmp + 1) / 5;
//				tmp -= x2;
//				if ((tmp + 1) % 5 == 0)
//				{
//					x3 = (tmp + 1) / 5;
//					tmp -= x3;
//						if ((tmp + 1) % 5 == 0)
//						{
//							x4 = (tmp + 1) / 5;
//							tmp -= x4;
//							if ((tmp + 1) % 5 == 0)
//							{
//								x5= (tmp + 1) / 5;
//								tmp -= x5;
//								if (tmp > 2000)
//									continue;
//								else
//								  break;
//							}
//					}
//				}
//			}
//		}
//	}
//	cout << "剩余="<<tmp<<endl;
//	cout << "x1=" << x1 << endl;
//	cout << "x2=" << x2 << endl;
//	cout << "x3=" << x3 << endl;
//	cout << "x4=" << x4 << endl;
//	cout << "x5=" << x5 << endl;
//}
//vector<int> tmp;
//void merge(vector<int> &num, int left, int mid, int right) {
//	int i = left, j = mid + 1;
//	int ans = 0;
//	int k = 0;
//	tmp.assign(right - left + 1,0);
//	while (i <= mid && j <= right)
//	{
//		if (num[i] <= num[j])
//		{
//			tmp[k++] = num[i++];
//		}
//		else
//		{
//			tmp[k++] = num[j++];
//			ans += (mid - i + 1);
//		}
//	}
//	while (i <= mid)
//	{
//		tmp[k++] = num[i++];
//	}
//	while (j <= right)
//	{
//		tmp[k++] = num[j++];
//	}
//	for (int i = 0; i < tmp.size(); i++)
//		num[i+left] = tmp[i];
//}
//void mergesort(vector<int> &num, int left, int right) {
//	if (left >= right)
//		return;
//
//	int mid = left + (right - left) / 2;
//	mergesort(num, left, mid);
//	mergesort(num, mid + 1, right);
//	if (num[mid] <= num[mid + 1])
//		return;
//	merge(num, left, mid, right);
//	//return x1+x2+x3;
//}
//
//vector<int> sortArray(vector<int>& nums) {
//	//tmp.resize(nums.size(), 0);
//	mergesort(nums, 0, nums.size() - 1);
//	return nums;
//}
//
//int leftbinaryfind(vector<int>& data, int k)
//{
//	int left = 0;
//	int right = data.size() - 1;
//	int mid;
//	while (left <= right)
//	{
//		mid = (left + right) >> 1;
//		if (data[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (data[mid] >= k)
//		{
//			right = mid - 1;
//		}
//	}
//	return left;
//}
//int rightbinaryfind(vector<int>& data, int k)
//{
//	int left = 0;
//	int right = data.size() - 1;
//	int mid;
//	while (left <= right)
//	{
//		mid = (left + right) >> 1;
//		if (data[mid] <= k)
//		{
//			left = mid + 1;
//		}
//		else if (data[mid] > k)
//		{
//			right = mid - 1;
//		}
//	}
//	return right;
//}
//void main()
//{
//	vector<int> v = { 1,2,4,4,4,5,6,7};
//	cout<< leftbinaryfind(v,3)<<endl;
//	cout << rightbinaryfind(v, 3) << endl;
//	cout << leftbinaryfind(v, 4) << endl;
//	cout << rightbinaryfind(v, 4) << endl;
//	/*for (auto e : v)
//		cout << e << " ";*/
//}
#include<map>
//void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
//	map<int, int> mp;
//	for (int i = 0; i < data.size(); i++)
//		mp[data[i]]++;
//	for (int i = 0; i < data.size(); i++)
//	{
//		if (*num1 == 0 && mp[data[i]] == 1)
//			*num1 = data [i];
//		else if ( mp[data[i]] == 1)
//			*num2 = data[i];
//	}
//}
vector<int> FindNumbersWithSum(vector<int> array, int sum) {
	if (array.size() < 2)
		return {};
	int i = 0, j = array.size() - 1;
	int preres = INT_MAX;
	int res;
	vector<int> v ;
	while (i < j)
	{
		if (array[i] + array[j] < sum)
		{
			i++;
		}
		else if (array[i] + array[j] > sum)
		{
			j--;
		}
		else
		{
			res = array[i] * array[j];
			if (res < preres)
			{
				v.assign(2, 0);
				v[0] = array[i];
				v[1] = array[j];
				preres = res;
			}
			i++;
		}
	}
	return v;
}
void main()
{
	vector<int> data = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	vector<int> v = { 0,0 };
	v=FindNumbersWithSum(data, 21);
	cout << v[0] << " " << v[1]<< endl;
}

#endif