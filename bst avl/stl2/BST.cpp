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
			//�ҵ��ýڵ�󣬵�������������Ϊnull��ʱ�򣬽��ýڵ�����������ֵ�����ң�������ȥ��������������Сֵ������ȥ
			if (t->leftchild != nullptr && t->rightchild != nullptr)
			{
				//����tmpΪt��������
				BSTNode<Type> *tmp = t->leftchild;
				//�����������ֵ
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
			//	//�ýڵ�ֻ�����������������������ýڵ���������滻����
			//	BSTNode<Type> *tmp = t;//�����t���൱��t->lefthild
			//	t= tmp->leftchild;
			//	delete tmp;
			//	return true;
			//}
			//else if (t->leftchild == nullptr && t->rightchild != nullptr)
			//{
			//	//�ýڵ�ֻ�����������������������ýڵ���������滻����
			//	BSTNode<Type> *tmp = t;//�����t���൱��t->righthild
			//	t = tmp->rightchild;
			//	delete tmp;
			//	return true;
			//}
			//else
			//{
			//	//������������ֱ��ɾ��
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
	pair<string, string > kv1("1.1", "Ԫ��");
	pair<string, string > kv2  ("5.1", "�Ͷ�");
	pair<string, string> v[] = { {"1.1", "Ԫ��"} ,{"5.1", "�Ͷ�"} };
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
