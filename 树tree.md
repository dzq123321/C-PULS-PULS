#### 树

![P00430-145031(1)](E:\duzhiqiang\我的编程资料和代码\github\picture\P00430-145031(1).jpg)

```c++
typedef struct node {
	int data;
	struct node* left;
	struct node* right;
	node(int x) : data(x), left(NULL), right(NULL) {}
} Node;
typedef struct {
	Node* root;
}Tree;
void preorder(Node* node)
{
	if (node != NULL)
	{
		printf("%d", node->data);
		preorder(node->left);
		preorder(node->right);
	}
}
void inorder(Node* node)//中序遍历
{
	if (node != NULL)
	{
		inorder(node->left);
		printf("%d", node->data);
		inorder(node->right);
	}
}
void postorder(Node* node)//后序遍历
{
	if (node != NULL)
	{
		postorder(node->left);
		postorder(node->right);
		printf("%d", node->data);
	}
}
void insert(Tree* tree, int value)
{
	Node* node = (Node*)malloc(sizeof(Node));
	assert(node);
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	if (tree->root == NULL)
		tree->root = node;
	else
	{
		Node* tmp = tree->root;
		while (tmp != NULL)
		{
			if (value < tmp->data)
			{
				if (tmp->left == NULL)
				{
					tmp->left = node;
					return;
				}
				else
					tmp = tmp->left;
			}
			else if (value > tmp->data)
			{
				if (tmp->right == NULL)
				{
					tmp->right = node;
					return;
				}
				else
					tmp = tmp->right;
			}
		}
	}
}
int get_height(Node* node)
{
	if (node == NULL)
		return -1;
	int left = get_height(node->left);
	int right = get_height(node->right);
	return max(left, right) + 1;

}
int get_maximumdata(Node* node)
{
	if (node == NULL)
		return -1;
	int max1 = node->data;
	int max2 = get_maximumdata(node->left);
	int max3 = get_maximumdata(node->right);
	int max = max1;
	if (max < max2) max = max2;
	if (max < max3) max = max3;
	return max;
}
typedef vector<int>::iterator type;
Node* _buildTree_By_VLR_LVR(type prebegin, type preend, type inbegin, type inend)
{
	if (inbegin == inend)
		return NULL;
	Node* root = new Node(*prebegin);
	auto pos = find(inbegin, inend, *prebegin);
	root->left = _buildTree_By_VLR_LVR(prebegin + 1, prebegin + 1 + (pos - inbegin), inbegin, pos);//迭代器的范围是[ )前闭后开
	root->right = _buildTree_By_VLR_LVR(prebegin + 1 + (pos - inbegin), preend, pos + 1, inend);
	return root;
}
Node* buildTree_By_VLR_LVR(vector<int>& preorder, vector<int>& inorder) {
	Node* root = NULL;
	if (preorder.size() == 0)
		return root;
	return _buildTree_By_VLR_LVR(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
}

Node* _buildTree_By_LVR_LRV(type inbegin, type inend,type postbegin, type postend)
{
	if (inbegin == inend)
		return NULL;
	Node* root = new Node(*(postend-1));
	type pos = find(inbegin, inend, *(postend - 1));
	root->left = _buildTree_By_VLR_LVR(inbegin, pos, postbegin, postbegin + (pos - inbegin));
	root->right = _buildTree_By_VLR_LVR(pos + 1, inend, postbegin + (pos - inbegin), postend - 1);
	return root;
}
Node* buildTree_By_LVR_LRV(vector<int>& inorder,vector<int>& postorder) {
	return _buildTree_By_LVR_LRV(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
}

int main()
{
	vector<int> Preorder = { 6,3,2,1,5,8,7 };
	vector<int> Inorder = { 1,2,3,5,6,7,8 };
	vector<int> Postorder = { 1,2,5,3,7,8,6 };
	Tree tree;
	tree.root = buildTree_By_LVR_LRV(Inorder, Postorder);
	cout << "preorder= ";
	preorder(tree.root);
	cout << endl;

	Tree tree2;
	tree2.root = buildTree_By_VLR_LVR(Preorder, Inorder);
		cout << "postorder= ";
		postorder(tree2.root);
	cout << endl;

}
```

#### 二叉树

二叉搜索树（BST   binary search tree）： 左子树的值 <  根的值 <右子树的值   （中序遍历是按从小到大排列）

```
typedef struct node {
	int data;
	struct node* left;
	struct node* right;
} Node;
typedef struct {
	Node* root;
}Tree;
void preorder(Node* node)
{
	if (node != NULL)
	{
		printf("%d", node->data);
		preorder(node->left);
		preorder(node->right);
	}
}
void inorder(Node* node)//中序遍历
{
	if (node != NULL)
	{
		inorder(node->left);
		printf("%d", node->data);
		inorder(node->right);
	}
}
//void postorder(Node* node)//中序遍历
void insert(Tree* tree, int value)
{
	Node* node = (Node*)malloc(sizeof(Node));
	assert(node);
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	if (tree->root == NULL)
		tree->root = node;
	else
	{
		Node* tmp = tree->root;
		while (tmp != NULL)
		{
			if (value < tmp->data)
			{
				if (tmp->left == NULL)
				{
					tmp->left = node;
					return;
				}
				else
					tmp = tmp->left;
			}
			else if (value > tmp->data)
			{
				if (tmp->right == NULL)
				{
					tmp->right = node;
					return;
				}
				else
					tmp = tmp->right;
			}
		}
	}
}
int get_height(Node* node)
{
	if (node == NULL)
		return -1;
	int left = get_height(node->left);
	int right = get_height(node->right);
	return max(left, right) + 1;

}
int get_maximumdata(Node* node)
{
	if (node == NULL)
		return -1;
	int max1 = node->data;
	int max2 = get_maximumdata(node->left);
	int max3 = get_maximumdata(node->right);
	int max = max1;
	if (max < max2) max = max2;
	if (max < max3) max = max3;
	return max;
}
int main()
{
	int arr[7] = { 6,3,8,2,5,1,7 };
	Tree tree;
	tree.root = NULL;
	int i;
	for (int i = 0; i < 7; i++)
	{
		insert(&tree, arr[i]);
	}
	inorder(tree.root);
	cout << endl;
	cout << "--------------------------" << endl;
	preorder(tree.root);
	cout << endl;
	cout << get_height(tree.root) << endl;
	cout << get_maximumdata(tree.root) << endl;
}
```
#### AVL树的旋转和调整(先旋转在链接)

```c++
//利用一个栈stack记录父亲节点，当旋转完成后进行链接（这段代码是放在了最后）
if (st.empty())
		t = pr;
	else
	{
		AVLNode<Type> *ppr = st.top();
		if (ppr->data > pr->data)
			ppr->leftchild = pr;
		else
			ppr->rightchild = pr;
	}
```

左单旋

![左单旋转](E:\duzhiqiang\我的编程资料和代码\github\picture\左单旋转.jpg)

```c++
void RotateL(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subL = ptr;
		ptr = ptr->rightchild;
		subL->rightchild = ptr->leftchild;
		ptr->leftchild = subL;
		ptr->bf = subL->bf = 0;
	}
```

右单旋

![右单旋转](E:\duzhiqiang\我的编程资料和代码\github\picture\右单旋转.jpg)

```c++
void RotateR(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subR = ptr;
		ptr = ptr->leftchild;
		subR->leftchild = ptr->rightchild;
		ptr->rightchild = subR;
		ptr->bf = subR->bf = 0;
	}
```

双旋转

![P00509-141443(1)](E:\duzhiqiang\我的编程资料和代码\github\picture\P00509-141443(1).jpg)

```c++
void RotateLR(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subL = ptr->leftchild;
		AVLNode<Type> *subR = ptr;
		ptr = subL->rightchild;
		//先左旋转
		subL->rightchild = ptr->leftchild;
		ptr->leftchild = subL;
		//再右旋转
		subR->leftchild = ptr->rightchild;
		ptr->rightchild = subR;
		//修正平衡因子
		if (ptr->bf == 1)
		{
			subL->bf = -1;
			subR->bf = 0;
		}
		else if (ptr->bf == -1)
		{
			subL->bf = 0;
			subR->bf = 1;
		}
		else
		{
			subL->bf = 0;
			subR->bf = 0;
		}
		ptr->bf = 0;
	}
	void RotateRL(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subL = ptr;
		AVLNode<Type> *subR = ptr->rightchild;
		ptr = subR->leftchild;
		//先右旋转
		subR->leftchild = ptr->rightchild;
		ptr->rightchild = subR;
		//在左旋转
		subL->rightchild = ptr->leftchild;
		ptr->leftchild = subL;
		//调整平衡因子
		if (ptr->bf == -1)
		{
			subL->bf = 0;
			subR->bf = 1;
		}
		else if (ptr->bf == 1)
		{
			subL->bf = -1;
			subR->bf = 0;
		}
		else
		{
			subL->bf = 0;
			subR->bf = 0;
		}
		ptr->bf = 0;
	}
```

#### 判断树是否为二叉排序树

```
int pre=INT_MIN;
bool flag=true;
bool Isbst(Treenode* root)
{
    if(root!=NULL){
      Isbst(root->left);
      if(pre>root->val) flag= false;
       pre=root->val;
      Isbst(root->right);  
    }
     return flag; 
}
```

#### [297. 二叉树的序列化与反序列化](https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/)

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
string serialize(TreeNode* root) {
        string res;
        dfs_s(root, res);
        return res;
    }

    // 前序遍历序列转化为字符串
    void dfs_s(TreeNode* root, string& res) {
        if (!root) {
            res += "null ";
            return;
        }
        res += to_string(root->val) + ' ';
        dfs_s(root->left, res);
        dfs_s(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // 开始遍历索引
        int u = 0;
        return dfs_d(data, u);
    }

    TreeNode* dfs_d(string& data, int& u) {
        if (u >= data.size()) return NULL;
        if (data[u] == 'n') {
            u = u + 5;
            return NULL;
        }
        int val = 0, sign = 1;
        if (data[u] == '-') sign = -1, u ++ ;
        while(data[u] != ' '){val = val * 10 + data[u] - '0'; u++;}
        val *= sign;
        u = u + 1 ;

        auto root = new TreeNode(val);
        root->left = dfs_d(data, u);
        root->right = dfs_d(data, u);

        return root;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```

#### [112. 路径总和](https://leetcode-cn.com/problems/path-sum/)

```
给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
说明: 叶子节点是指没有子节点的节点。
示例: 
给定如下二叉树，以及目标和 sum = 22，
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
 bool hasPathSum(TreeNode* root, int sum) {
        return DFS(root, sum);
    }
    bool DFS(TreeNode* root, int sum) {
        if(root==NULL)
        return false;
        if(root->val==sum&&root->left==NULL&&root->right==NULL)
        return true;
        sum-=root->val;
        return  DFS(root->left,sum)||DFS(root->right,sum);
    }
};
```

#### [113. 路径总和 II](https://leetcode-cn.com/problems/path-sum-ii/)

```
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
说明: 叶子节点是指没有子节点的节点。
示例:
给定如下二叉树，以及目标和 sum = 22，
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
//回溯
vector<vector<int>>  ans;
 vector<int> t;
void dfs(TreeNode* root, int sum)
{
    if(root==NULL) return ;
    t.push_back(root->val);
    if(root->val==sum&&root->left==NULL&&root->right==NULL)
    {
        ans.push_back(t);
    }
    dfs(root->left,sum-root->val);
    dfs(root->right,sum-root->val);
    t.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL) return{};
        dfs(root,sum);
        return ans;
    }
};
```



#### [437. 路径总和 III](https://leetcode-cn.com/problems/path-sum-iii/)

```
给定一个二叉树，它的每个结点都存放着一个整数值。
找出路径和等于给定数值的路径总数。
路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
int res=0;
void dfs(TreeNode* root, int sum) {
    if(root==NULL) return ;
    sum=sum-root->val;
    if(sum==0) res++;
    dfs(root->left,sum);
     dfs(root->right,sum);
}
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL) return 0;
         dfs(root,sum);
          pathSum(root->left,sum);
           pathSum(root->right,sum);
           return res;
    }
};
```

