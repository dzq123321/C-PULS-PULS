#if 1

#include <iostream>
#include<string>
#include<vector>
#include<assert.h>
using namespace std;


template<class Type>
class BSTtree;

template<class Type>
class BSTNode
{
	friend class BSTtree<Type>;
public:
	BSTNode(Type d= Type(), BSTNode<Type> *left=nullptr, BSTNode<Type> *right=nullptr)
		:data(d),leftchild(left),rightchild(right)
	{}
	~BSTNode()
	{}
private:
	Type data;
	BSTNode<Type> *leftchild;
	BSTNode<Type> *rightchild;
};



template<class Type>
class BSTtree
{
	typedef BSTNode<Type>* bstTree;
public:
	BSTtree():root(nullptr)
	{}
public:
	bool Insert(const Type &x)
	{
		return Insert(root, x);
	}
public:
	Type& Min()const
	{
		return Min(root);
	}
	Type& Max()const
	{
		return Max(root);
	}
	void Inorder()const
	{
		 Inorder(root);
	}
	bool Remove(const Type &key)
	{
		return Remove(root, key);
	}
	BSTNode<Type> *Search(const Type &key)
	{
		return Search(root, key);
	}
public:
	BSTNode<Type> *Search(bstTree&t, const Type &key)
	{
		if (t == nullptr)
			return nullptr;
		else if (t->data > key)
			Search(t->leftchild, key);
		else if (t->data < key)
			Search(t->rightchild, key);
		else
			return t;
	}
	bool Remove(bstTree&t, const Type &key)
	{
		if (t == nullptr)
			return false;
		if (t->data > key)
			Remove(t->leftchild, key);
		else if (t->data < key)
			Remove(t->rightchild, key);
		else
		{
			//找到该节点后，当左右子树都不为null的时候，将该节点的左树的最大值（最右）交换上去，或者右树的最小值交换上去
			if (t->leftchild != nullptr && t->rightchild != nullptr)
			{
				//定义tmp为t的左子树
				BSTNode<Type> *tmp = t->leftchild;
				//找左树的最大值
				while (tmp->rightchild != nullptr)
					tmp = tmp->rightchild;
				t->data = tmp->data;
				Remove(t->leftchild, t->data);
			}
			else
			{
				BSTNode<Type> *tmp = t;
				if (t->leftchild != nullptr)
					t = t->leftchild;
				else
					t = t->rightchild;
				delete tmp;
				return true;
			}
			//else if (t->leftchild != nullptr && t->rightchild == nullptr)
			//{
			//	//该节点只有左子树，无右子树，将该节点的左子树替换上来
			//	BSTNode<Type> *tmp = t;//这里的t就相当于t->lefthild
			//	t= tmp->leftchild;
			//	delete tmp;
			//	return true;
			//}
			//else if (t->leftchild == nullptr && t->rightchild != nullptr)
			//{
			//	//该节点只有右子树，无左子树，将该节点的右子树替换上来
			//	BSTNode<Type> *tmp = t;//这里的t就相当于t->righthild
			//	t = tmp->rightchild;
			//	delete tmp;
			//	return true;
			//}
			//else
			//{
			//	//无左右子树，直接删除
			//	delete t;
			//	t = nullptr;
			//	return true;
			//}
		}
	}
	Type& Min( BSTNode<Type> *t)const
	{
		assert(t);
		while (t->leftchild)
		{
			t = t->leftchild;
		}
		return t->data;
	}
	Type& Max(BSTNode<Type> *t)const
	{
		assert(t);
		while (t->rightchild)
		{
			t = t->rightchild;
		}
		return t->data;
	}
	void Inorder(const BSTNode<Type> *t)const
	{
		if (t != nullptr)
		{
			Inorder(t->leftchild);
			//cout << t->data << " ";
			cout << (t->data).first << ": " << (t->data).second << endl;
			Inorder(t->rightchild);
		}
	}
	bool Insert(BSTNode<Type> *&t, const Type &x)
	{
		if (t == nullptr)
		{
			t = new BSTNode<Type>(x);
			return true;
		}
		else if (x < t->data)
		{
			Insert(t->leftchild, x);
		}
		else if (x > t->data)
		{
			Insert(t->rightchild, x);
		}
		else
			return false;

	}
private:
	BSTNode<Type>* root;
};


void main()
{
	pair<string, string > kv1("1.1", "元旦");
	pair<string, string > kv2  ("5.1", "劳动");
	pair<string, string> v[] = { {"1.1", "元旦"} ,{"5.1", "劳动"} };
	pair<string, string> v2[] = { kv1,kv2 };
	BSTtree<pair<string,string>> bst;
		int n = sizeof(v) / sizeof(v[0]);
		for (const auto &e : v)
			bst.Insert(e);
	bst.Inorder();
}
//
//int main()
//{
//	vector <int> v = { 1,2,3,4,5 };
//	BSTtree<int> bst;
//	for (auto e : v)
//		bst.Insert(e);
//	bst.Inorder();
//	cout << endl;
//	bst.Remove(1);
//	bst.Inorder();
//	cout << endl;
//	BSTNode<int> *p=bst.Search(2);
//	//cout << bst.Max() << endl;
//}

#endif
