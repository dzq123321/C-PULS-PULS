#### 树

![P00430-145031(1)](E:\duzhiqiang\比特51c语言\github\picture\P00430-145031(1).jpg)

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

![左单旋转](E:\duzhiqiang\比特51c语言\github\picture\左单旋转.jpg)

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

![右单旋转](E:\duzhiqiang\比特51c语言\github\picture\右单旋转.jpg)

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

![P00509-141443(1)](E:\duzhiqiang\比特51c语言\github\picture\P00509-141443(1).jpg)

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

