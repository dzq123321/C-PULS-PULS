	#include<iostream>
	#include<stack>
	#include<vector>
	#include<string>
	using namespace std;
	template<class Type>
	class AVLTree;

	template<class Type>
	class AVLNode
	{
		friend class AVLTree<Type>;
	public:
		AVLNode(Type d = Type(), AVLNode<Type> *left = nullptr, AVLNode<Type> *right = nullptr, int b = int())
			:data(d), leftchild(left), rightchild(right), bf(b)
		{}
		~AVLNode()
		{}
	private:
		Type data;
		AVLNode<Type> *leftchild;
		AVLNode<Type> *rightchild;
		int bf;//平衡因子
	};
	template<class Type>
	class AVLTree
	{
	public:
		AVLTree() :root(nullptr)
		{}
		~AVLTree()
		{}
	public:
		bool Insert(const Type &x)
		{
			return Insert(root, x);
		}
		bool Remove(const Type &key)
		{
			return Remove(root, key);
		}
	protected:
		bool Insert(AVLNode<Type> *&root, const Type & x);
		bool Remove(AVLNode<Type> *&root, const Type & x);
	protected:
		void RotateL(AVLNode<Type> *&ptr)
		{
			AVLNode<Type> *subL = ptr;
			ptr = ptr->rightchild;
			subL->rightchild = ptr->leftchild;
			ptr->leftchild = subL;
			ptr->bf = subL->bf = 0;
		}
		void RotateR(AVLNode<Type> *&ptr)
		{
			AVLNode<Type> *subR = ptr;
			ptr = ptr->leftchild;
			subR->leftchild = ptr->rightchild;
			ptr->rightchild = subR;
			ptr->bf = subR->bf = 0;
		}
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
	private:
		AVLNode<Type> *root;
	};

	template <class Type>
	bool AVLTree<Type>::Insert(AVLNode<Type> *&t, const Type &x)
	{
		//节点插入，按照bst树的规则
		AVLNode<Type> *pr = nullptr;//pr代表当前节点的父节点
		//因为后面要进行平衡的调整，所以需要一个栈记住当前节点的父节点
		AVLNode<Type> *p = t;//因为是引用，重新定义根
		stack<AVLNode<Type>*> st;
		while (p != nullptr)
		{
			if (x == p->data)
				return false;
			pr = p;
			st.push(pr);
			if (x < p->data)
				p = p->leftchild;
			else
				p = p->rightchild;
		}
		//链接节点
		p = new AVLNode<Type>(x);
		if (pr->data > x)
			pr->leftchild = p;
		else
			pr->rightchild = p;
		//平衡调整
		while (!st.empty())
		{
			pr = st.top();
			st.pop();
			if (p == pr->leftchild)
				pr->bf--;
			else
				pr->bf++;
			if (pr->bf == 0)
				break;
			if (pr->bf == 1 || pr->bf == -1)
				p = pr;//=1\-1  则继续往上回溯，看是否有不平衡的节点
			else//找到了不平衡的节点 （pr->bf ==-2/2）
			{
				if (pr->bf == 2)
				{
					if (p->bf == 1)
						//左单旋转
						RotateL(pr);
					else//双旋转 右旋转 +左旋转
						RotateRL(pr);
				}
				else//(pr->bf == -2)
				{
					if (p->bf == -1)
						//右单旋转
						RotateR(pr);
					else//双旋转 左旋转 +右旋转
						RotateLR(pr);
				}
				break;
			}

		}
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
		return true;
	}
	int main()
	{
		vector<int> iv{ 10, 7, 3, 5, 20, 13, 16, 19, 23, 14 };
		//vector<int> iv{10, 70, 300 };
		AVLTree<int> avl;
		for (const auto &e : iv)
			avl.Insert(e);
		return 0;
	}