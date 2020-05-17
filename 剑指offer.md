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

#### 二叉树的镜像 

<https://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011?tpId=13&tqId=11171&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking> 

操作给定的二叉树，将其变换为源二叉树的镜像。 

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
    void Mirror(TreeNode *pRoot) {
         //递归，前序遍历
        if(pRoot==NULL)
            return ;
        swap(pRoot->left,pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
         //利用队列进行二叉树层序遍历,出栈后直接交换tmp的左右子树
        if(pRoot==NULL)
            return ;
        queue<TreeNode*> que;
        que.push(pRoot);
        while(!que.empty())
        {
            TreeNode *tmp=que.front();
            que.pop();
            swap(tmp->left,tmp->right);
            if(tmp->left!=NULL)
                que.push(tmp->left);
            if(tmp->right!=NULL)
                que.push(tmp->right);
        }
        
    }
};
```

#### 顺时针打印矩阵 https://www.nowcoder.com/practice/9b4c81a02cd34f76be2659fa0d54342a

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10. 

自定义方向    right-》down->left=>up

```
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> v;
        if(matrix.size()==0)
            return v;
        int top=0,bottom=matrix.size()-1;
        int left=0,right=matrix[0].size()-1;
        string direction="right";
        while(left<=right&&top<=bottom)
        {
            if(direction=="right")
            {
               for(int i=left; i<=right; i++)
               {
                   v.push_back(matrix[top][i]);
               }
                   top++;
                   direction="down";
            }
            else if(direction=="down")
            {
               for(int i=top; i<=bottom; i++)
               {
                   v.push_back(matrix[i][right]);
               }
                  right--;
                   direction="left";
            }
            else if(direction=="left")
            {
               for(int i=right; i>=left; i--)
               {
                   v.push_back(matrix[bottom][i]);
               }
                   bottom--;
                   direction="up";
             }
            else if(direction=="up")
            {
               for(int i=bottom; i>=top; i--)
               {
                   v.push_back(matrix[i][left]);
               }
                left++;
                direction="right";
            }
        }
       return v;
    }
};

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
          vector <int> ans;
        if(matrix.empty()) return ans; //若数组为空，直接返回答案
        int u = 0; //赋值上下左右边界
        int d = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        while(true)
        {
            for(int i = l; i <= r; ++i) ans.push_back(matrix[u][i]); //向右移动直到最右
            if(++ u > d) break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
            for(int i = u; i <= d; ++i) ans.push_back(matrix[i][r]); //向下
            if(-- r < l) break; //重新设定有边界
            for(int i = r; i >= l; --i) ans.push_back(matrix[d][i]); //向左
            if(-- d < u) break; //重新设定下边界
            for(int i = d; i >= u; --i) ans.push_back(matrix[i][l]); //向上
            if(++ l > r) break; //重新设定左边界
        }
        return ans;
    }
};


```

#### 包含min函数的栈 

定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。

注意：保证测试中不会当栈为空的时候，对栈调用pop()或者min()或者top()方法

//思路：每次压栈的时候压入两个元素，保证栈顶是最小值

```
class Solution {
public:
    void push(int value) {
        if(st.empty()){
            st.push(value);
            st.push(value);
        }
        else{
           int top=st.top();
            st.push(value);
            if(top>=value)
               st.push(value);
            else
                st.push(top);
        }
    }
    void pop() {
        st.pop();
        st.pop();
    }
    int top() {
        int x=st.top();
        st.pop();
        int tmp=st.top();
        st.push(x);
        return tmp;
    }
    int min() {
        return st.top();
    }
    private:
    stack<int> st;
};
```

#### 二叉搜索树的后序遍历序列

输入一个非空整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

```c++
class Solution {
public:
    /*
    思路： 二叉搜索树：左孩子的值小于根的值，右孩子的值大于根的值
    对于一个二叉搜索树的后序遍历： 左右根
    所以先循环判断左右根的分界点k 根据二叉搜索树的特点，循环判断找出第一个大于根的值就可以
    然后再从这个位置k到根之前的节点，理论上都是根的右孩子，要大于根，一旦发现小于，return false
    最后递归判断就好了
    */
    vector<int> seq;
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return false;
        seq=sequence;
        return dfs(0,seq.size()-1);
    }
    bool dfs(int l, int r)
    {
        if(l>=r)
            return true;
        int k=l;
        //找到左右孩子分界点k
        while(k<r&&seq[k]<seq[r])
                k++;
        //右孩子的值应都大于根的值
        for(int i=k; i<r; i++)
        {
            if(seq[i]<seq[r])
                return false;
        }
        return dfs(l,k-1)&&dfs(k,r-1);
    }
};
```

#### 复杂链表的复制 

## 题目描述

输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针random指向一个随机节点），请对此链表进行深拷贝，并返回拷贝后的头结点。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空

常规方法，在我们先new出节点连成单链表后，需要在进行遍历链接random,节点，所以又需要一次遍历，找到原始链表中节点random的指向。

为了避免这个麻烦的问题，通过 map<RandomListNode* ,RandomListNode* > mp; 记录原始链表，将原始链表作为key键值，则之后链接的时候只需mp[it]->random=mp[it->random];, 可以想象为桶排。

```c++
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==NULL)
            return NULL;
        map<RandomListNode* ,RandomListNode* > mp;
        RandomListNode* p=pHead;
        while(p!=NULL){
            mp[p]=new RandomListNode (p->label);
            p=p->next;
        }
        p=pHead;
        while(p!=NULL)
        {
            mp[p]->next=mp[p->next];
            if(mp[p->random]!=NULL)
                mp[p]->random=mp[p->random];
            p=p->next;
        }
        return mp[pHead];
    }
};
```

#### [面试题36. 二叉搜索树与双向链表  LCOF](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/)

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* pre;
	Node* head;
    Node* treeToDoublyList(Node* root) {
		if (root == NULL)
			return NULL;
		inOrder(root);
		pre->right = head;
		head->left = pre;
		return head;
	}

	void inOrder(Node* cur)
	{
		if (cur == NULL)
			return;
		inOrder(cur->left);
		if (pre == NULL)
			head = cur;
		else
			pre->right = cur;
		cur->left = pre;
		pre = cur;
		inOrder(cur->right);
	}
};
```
## 平衡二叉树 

输入一棵二叉树，判断该二叉树是否是平衡二叉树。

在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树

```c++
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
       if(pRoot==NULL)
           return true;
        if(abs(getheight(pRoot->left)-getheight(pRoot->right))>1)
            return false;
            return IsBalanced_Solution(pRoot->left)&& IsBalanced_Solution(pRoot->right);
    }
    int getheight(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return 0;
        return max(getheight(pRoot->left),getheight(pRoot->right))+1;
    }
};
```



## 题目描述 字符串的排列 

输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

## 输入描述:

```c++
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
//请认真读题，可能有重复数字，所以要进行判断，并且时按字典序打印
class Solution {
public:
    vector<string> ans;
    vector<int> vis;
    string nans;
    void dfs(string str)
    {
        if(nans.size()==str.size())
        {
            ans.push_back(nans);
            return;
        }
        for(int i=0;i<str.size();i++)
        {
            if(vis[i]==1) continue;
            //如果当前元素和前一个元素相同，并且前一个元素没有被使用，continue
            if(vis[i-1]==0&&str[i]==str[i-1]) continue;
            vis[i]=1;
            nans.push_back(str[i]);
            dfs(str);
            nans.pop_back();
            vis[i]=0;
        }
    }
    vector<string> Permutation(string str) {
        if(str.size()==0)
            return ans;
        vis.assign(str.size(),0);
        dfs(str);
        return ans;
    }
};
```
## 题目描述 把数组排成最小的数 

输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

思路：按照字典序将a+b和b+a中较小的排在前面，最后直接拼接。注意自己编写的comp函数时静态的。

```c++
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(),numbers.end(),comp);
        string s;
        for(auto e:numbers)
        {
            s+=to_string(e);
        }
        return s;
    }
  private:
    static bool comp(const int &a,const int &b)
    {
        string ab=to_string(a)+to_string(b);
        string ba=to_string(b)+to_string(a);
        return ab<ba;
    }
};
```

#### [263. 丑数](https://leetcode-cn.com/problems/ugly-number/)

编写一个程序判断给定的数是否为丑数。

丑数就是只包含质因数 `2, 3, 5` 的**正整数**。

```c++
class Solution {
public:
    bool isUgly(int num) {
        //不停的整除2 3 5，如果最后结果1,则是丑数，否则返回false
        if(num<=0)
        return false;
        if(num==1)
        return true;
        while(num%2==0) num/=2;
        while(num%3==0) num/=3;
        while(num%5==0) num/=5;
        if(num!=1)
        return false;
        else
        return true;
    }
};
```

## 题目描述 第一个只出现一次的字符 

在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.（从0开始计数）

思路：利用find和rfind左右开始找，找到并且相等则说明只出现一次

```c++
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int left=0,right=0;
        for(int i=0;i<str.size()-1;i++)
        {
            left=str.find(str[i]);
            right=str.rfind(str[i]);
            if(left==right)
                return left;
        }
        return -1;
    }
};
```

#### [数组中的逆序对](https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/)

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

暴力：超时

```
class Solution {
public:
    int reversePairs(vector<int> data) {
        int cnt = 0;
    int len = data.size();
    for (int i = 0; i < len-1; i++) {
        for (int j = i + 1; j < len; j++) {
              if (data[i] > data[j]) {
                cnt++;
             }
         }
     }
        return cnt;
    }
};
```

 归并排序，在归并的时候进行查找，分为两部分数组，只要插入后面那部分的数组数组，说明该元素都大于前面那部分数组的所以元素，则这一阶段的逆序对为前面数组的大小 mid-i+1

#### [面试题51. 数组中的逆序对](https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/)

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。 

思路：归并排序[A，B]，假设A,B都是排好序的，在归并的时候如果数组B的元素小于数组A的元素，则一定存在（mid-i+1）个逆序对

A=[3 5 7 9]  ,  B=[ 2 4 6 8]   B[0]<A[0] ，则再将B[0]归并到tmp数组时，存在3-0+1个逆序对

[A，B]中的逆序对=[A]的逆序对+[B]中的逆序对+将A，B混排在一起的逆序对 

```c++
class Solution {
public:
   vector<int> tmp;
   vector<int> num;
    int reversePairs(vector<int> data) {
    if(data.size()<2)
    return 0;
     num=data;
     tmp.assign(data.size(),0);
      return mergesort(num,0,data.size()-1);
    }
private:
    int mergesort(vector<int> &num,int left, int right){
        if(left>=right)
            return 0;
        int mid=left+(right-left)/2;
        int x1=mergesort(num,left,mid);
        int x2=mergesort(num,mid+1,right);
        if(num[mid]<=num[mid+1])
            return x1+x2;
        int x3=merge(num,left, mid,right);
        return x1+x2+x3;
    }
int merge(vector<int> &num, int left, int mid, int right) {
	int i = left, j = mid + 1;
	int ans = 0;
	int k = 0;
	tmp.assign(right - left + 1,0);
	while (i <= mid && j <= right)
	{
		if (num[i] <= num[j])
		{
			tmp[k++] = num[i++];
		}
		else
		{
			tmp[k++] = num[j++];
			ans += (mid - i + 1);
		}
	}
	while (i <= mid)
	{
		tmp[k++] = num[i++];
	}
	while (j <= right)
	{
		tmp[k++] = num[j++];
	}
	for (int i = 0; i < tmp.size(); i++)
		num[i+left] = tmp[i];
    return ans;
}

}; 
```

## 数字在排序数组中出现的次数

统计一个数字在排序数组中出现的次数。

找到左右边界，leftbinaryfind找到该元素第一次出现的位置，rightbinaryfind找到该元素最后一次出现的位置

leftbinaryfind找不到，返回比该元素大的第一个元素的位置

rightbinaryfind找不到，返回比该元素小的最后一个元素的位置

比如vector<int> v = { 1,2,4,4,4,5,6,7}; ，找3  leftbinaryfind返回2   rightbinaryfind返回1

```c++
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        //二分
        return rightbinaryfind(data,k)-leftbinaryfind(data,k)+1;
};
  int leftbinaryfind(vector<int>& data ,int k)
  {
      int right=data.size()-1;
      int left=0;
      while(left<=right)
      {
          int mid=(left+right)>>1;
          if(data[mid]>=k)
              right=mid-1;
          else
              left=mid+1;
      }
      return left;
    }
  int rightbinaryfind(vector<int>& data ,int k)
  {
      int right=data.size()-1;
      int left=0;
      while(left<=right)
      {
          int mid=(left+right)>>1;
          if(data[mid]<=k)
              left=mid+1;
          else
              right=mid-1;
      }
      return right;
    }
  };
```

普通的二分查找

```c++
int binarySearch(int[] nums, int target) {
    int left = 0; 
    int right = nums.length - 1; // 注意

    while(left <= right) { // 注意
        int mid = (right + left) / 2;
        if(nums[mid] == target)
            return mid; 
        else if (nums[mid] < target)
            left = mid + 1; // 注意
        else if (nums[mid] > target)
            right = mid - 1; // 注意
        }
    return -1;
}
```

## 数组中只出现一次的数字 

一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

思路：将这两个数相办法分为两组，对每一组进行异或就是最终结果。

那怎么区分这两个数字呢，用比特位，先对整个数字进行异或，得到的结果sum就是这两个数字的异或

然后找出这两个只出现一次的数字比特位第几位是不同的，即sum从右向左的第一个比特位为0的位置

比如  有数组num=[2 1 3 2 5 1]  3 5出现一次 3(011) 5(101)  sum=6(110) ，sum第一个为1的比特位就是

3 5有区别的比特位。然后找出这个比特位在进行分组。

```c++
class Solution {
public:
    /*
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        map<int,int> mp;
        for(int i=0;i<data.size();i++)
            mp[data[i]]++;
        for(int i=0;i<data.size();i++)
        {
            if (*num1 == 0 && mp[data[i]] == 1)
			   *num1 = data [i];
		     else if ( mp[data[i]] == 1)
			 *num2 = data[i];
        }
    }
    */    
     void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
            int sum=0;
      for(auto e:data)
      {
          sum=sum^e;
      }
      //找出这两个只出现一次的数字比特位第几位是不同的，即sum从右向左的第一个比特位为0的位置
      int k=1;//从右朝左开始
      while((sum&k)==0)
          k=k<<1;
      for(auto e:data)
      {
         if(e&k)
             *num1^=e;
         else
           *num2^=e;
      }
    }
};
```

#### [面试题57 - II. 和为s的连续正数序列](https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/)

输入一个正整数 `target` ，输出所有和为 `target` 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

思路：滑动窗口 双指针法，定义左闭右开区间[ )，i为左区间，j为右区间，当ij区间的和小于target，j++;

反之，i++,注意边界条件。

```c++
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
  int i = 1; // 滑动窗口的左边界
    int j = 1; // 滑动窗口的右边界
    int sum = 0; // 滑动窗口中数字的和
    vector<vector<int>> res;

    while (i <= target / 2) {
        if (sum < target) {
            // 右边界向右移动
            sum += j;
            j++;
        } else if (sum > target) {
            // 左边界向右移动
            sum -= i;
            i++;
        } else {
            // 记录结果
            vector<int> arr;
            for (int k = i; k < j; k++) {
                arr.push_back(k);
            }
            res.push_back(arr);
            // 左边界向右移动
            sum -= i;
            i++;
        }
    }
      return res;
    }
};
```

## 和为S的两个数字 

输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。

思路：左右两个指i，j, array[i]+array[j]<sum 则  i++，否则j--。

注意边界条件

```c++
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if(array.size()<2)
            return {};
        int i=0,j=array.size()-1;
        int preres=INT_MAX;
        int res;
        vector<int> v;
        while(i<j)
        {
            if(array[i]+array[j]<sum)
            {
                i++;
            }
            else if (array[i]+array[j]>sum)
            {
                j--;
            }
            else
            {
                res=array[i]*array[j];
                if(res<preres)
                {
                   v.assign(2,0);
                  v[0]=array[i];
                  v[1]=array[j];
                    preres=res;
                }
                i++;
            }
      }
          return v;
    }
};
```

## 左旋转字符串 

汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！

思路：主要还是临界条件的判断。解法简单  substr很高效

```
   string LeftRotateString(string str, int n) {
        if(n==0)
            return str;
        if(str=="")
            return "";
        int l=n%str.size();
        if(l==0)
            return str;
        return str.substr(n)+str.substr(0,n);
    }
    
  string LeftRotateString(string str, int n) {
        int len=str.size();
        if(len==0)
            return "";
        if(n==0)
            return str;
        int l=n%len;
        if(l==0)
            return str;
        string ret(str.c_str()+l);
        for(int i=0;i<l;i++)
        {
            ret+=str[i];
        }
        return ret;
    }
```

## 翻转单词顺序列 

牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

```
class Solution {
public:
    string ReverseSentence(string str) {
        if(str=="")
          return "";
        string ret;
        int j=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==' ')
            {
                ret.insert(ret.begin(),str.begin()+j,str.begin()+i);
                ret.insert(ret.begin(),' ');
                j=i+1;
            }
            if(str[i+1]=='\0')
            {
                ret.insert(ret.begin(),str.begin()+j,str.begin()+i+1);
            }
        }
        return ret;
    }
};
```

#### [面试题61. 扑克牌中的顺子](https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/)

有2个大王,2个小王(一副牌原本是54张^_^). 从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。如果牌能组成顺子就输出true，否则就输出false 

思路：1、除大小王，不能有重复的排，所以需要一个vis数组进行记录

​       2、在这五张牌中，除大小王，最大值-最小值+1<=5，这样才能组成顺子（例如2 3 4 5 6 ） 6-2+1=5

```
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        //最大值-最小值+1<=5  也不能有重复值
        if(numbers.size()<4)
            return false;
        int count=0;
        bool vis[14];
        memset(vis,false,sizeof(vis));
        int maxval=0,minval=14;
        for(auto e:numbers)
        {
            if(e==0)
                count++;
            else
            {
                if(vis[e]==1)//防止有重复值
                return false;
               maxval=max(maxval,e);
               minval=min(minval,e);
               vis[e]=1;
            }
        }
        if(count==4)
            return true;
        return (maxval-minval+1)<=5;
    }
};
```

