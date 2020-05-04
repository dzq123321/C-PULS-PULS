1、二维数组中的查找 

在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。 

<https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&tqId=11154&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking> 

```c++
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row=array.size();
          if(row==0)
            return false;
        int col=array[0].size();
         if(col==0)
            return false;
        int i=0,j=col-1;
        while(j>=0&&i<row)
        {
            if(array[i][j]<target)
                i++;
            else if(array[i][j]>target)
                j--;
            else if(array[i][j]==target)
                return true;
        }
        return false;
    }
};
```

#### 2、 请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。 

<https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking> 

```
class Solution {
public:
	void replaceSpace(char *str,int length) {
        int count=0;
         for(int i=0; i<length; i++)
         {
             if(str[i]==' ')
                 count++;
         }
        char *help=new char[length+2*count];
        int j=length+2*count;
        for(int i=length; i>=0; i--)
        {
            if(str[i]!=' ')
                help[j--]=str[i];
            else
            {
                help[j--]='0';
                help[j--]='2';
                help[j--]='%';
            }
        }
        strcpy(str,help);
	}
};
```

#### 3、从尾到头打印链表 

输入一个链表，按链表从尾到头的顺序返回一个ArrayList。 

```
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> st;
        vector<int> v;
        if(head==NULL)
            return v;
        ListNode* p=head;
        while(p->next!=NULL)
        {
            st.push(p->val);
            p=p->next;
        }
        st.push(p->val);
        while(!(st.empty()))
        {
            v.push_back(st.top());
            st.pop();
        }
        return v;
        
        
        
        ////////////////////////递归做法
        vector<int> v;
    vector<int> printListFromTailToHead(ListNode* head) {
        //递归
        if(head==NULL)
            return v;
        printListFromTailToHead(head->next);
        v.push_back(head->val);
        return v;
    }
};
```

#### 重建二叉树 

输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。 

```c++
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    typedef vector<int>::iterator type;
    TreeNode*  _reConstructBinaryTree(type prebegin,type preend,type vinbegin,type vinend)
    {
        if(vinbegin==vinend)
            return NULL;
        TreeNode* root=new TreeNode(*prebegin);
        auto pos=std::find(vinbegin,vinend,*prebegin);
        root->left=_reConstructBinaryTree(prebegin+1,prebegin+1+(pos-vinbegin),vinbegin,pos);
        root->right=_reConstructBinaryTree(prebegin+1+(pos-vinbegin),preend,pos+1,vinend);
        return root;
    }
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty())
            return NULL;
        return _reConstructBinaryTree(pre.begin(),pre.end(),vin.begin(),vin.end());
    }
};
```

#### 变态跳台阶 

<https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=11162&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking> 

一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

```
class Solution {
public:
    int jumpFloorII(int number) {
        //f(n)=f(n-1)+f(n-2)...+f(0)=f(n-1)+f(n-1)=2*f(n-1)=2*2*f(n-2)=...=2^(n-1)
        return (1<<(number-1));
    }
};

//递归
  int jumpFloorII(int number) {
        if(number==1)
            return 1;
        if(number==2)
            return 2;
        return 2*jumpFloorII(number-1);
   }
//dp
class Solution {
public:
    int jumpFloorII(int number) {
        //f(n)=f(n-1)+f(n-2)...+f(0)=f(n-1)+f(n-1)=2*f(n-1)=2*2*f(n-2)=...=2^(n-1)
        //动态规划 和上面的f[n]一样， dp[i]=dp[i-1]+dp[i-2]+...dp[0]
        vector<int> dp(number+1,0);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=number; i++)
        {
            for(int j=0;j<=i-1;j++)
            {
                dp[i]=dp[i]+dp[j];
            }
        }
        return dp[number];
    }
};

```

## 数值的整数次方 

给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

保证base和exponent不同时为0

<https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&tqId=11165&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking> 

```c++
class Solution {
public:
    double Power(double base, int exponent) {
        /*
        if(exponent==0)
            return 1;
        if(base==0)
            return 0;
        return base*Power(base,exponent-1);
        */
        if(exponent==0)
            return 1;
        if(base==0)
            return 0;
        double ret=1.0;
        int flag=0;
        if(exponent<0)
        {
            flag=1;
            exponent=-exponent;
        }
        //快速幂
        while(exponent)
        {
            if(exponent%2==1)//如果是奇数的话直接乘
                ret*=base;
            exponent/=2;
            base*=base;
        }
        return flag==0? ret: 1/ret;
    }
};
```

## 调整数组顺序使奇数位于偶数前面 

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

<https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking> 

```c++
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.size()==0)
            return;
       //冒泡的思想
        for(int i=0;i<array.size();i++)
        {
            for(int j=0; j<array.size();j++)
            {
                if((array[j]%2==0)&&(array[j+1]%2==1))
                    std::swap(array[j],array[j+1]);
            }
        }
    }
};
```

## 合并两个排序的链表 

输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则

<https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=11169&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking> 

//采用一个哑节点

```c++
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL)
            return pHead2;
        if(pHead2==NULL)
            return pHead1;
        ListNode* dummy=new ListNode(0);
        ListNode* cur=dummy;
        while(pHead1!=NULL&&pHead2!=NULL)
        {
            if(pHead1->val <= pHead2->val )
            {
                cur->next=pHead1;
                pHead1=pHead1->next;
            }
            else if(pHead1->val > pHead2->val )
            {
                cur->next=pHead2;
                pHead2=pHead2->next;
            }
            cur=cur->next;
        }
        if(pHead1==NULL)
            cur->next=pHead2;
        else
            cur->next=pHead1;
        return dummy->next;
    }
};
```

## 树的子结构 

输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

```c++
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool helper (TreeNode* A, TreeNode* B)
    {
         //如果TreeB已经遍历完了都能对应的上，返回true
        if(B==NULL)
            return true;
        //如果TreeB还没有遍历完，TreeA却遍历完了。返回false
        if(A==NULL)
            return false;
        //如果其中有一个点没有对应上，返回false
        if(A->val!=B->val)
            return false;
        //如果根节点对应的上，那么就分别去子节点里面匹配
        return helper(A->left,B->left)&& helper(A->right,B->right);
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1==NULL || pRoot2==NULL)
            return false;
        bool res=false;
            //如果找到了对应TreeB的根节点的点
        if(pRoot1->val==pRoot2->val)
            //以这个根节点为为起点判断是否包含TreeB
             res=helper(pRoot1,pRoot2);
            //如果找不到，那么就再去TreeA的左子树当作起点，去判断是否包含TreeB
         if (!res)
                res = HasSubtree(pRoot1->left, pRoot2);
            //如果还找不到，那么就再去TreeA的右子树当作起点，去判断是否包含TreeB
          if (!res)
                res = HasSubtree(pRoot1->right, pRoot2);
        // 返回结果
        return res;
    }
};
```

