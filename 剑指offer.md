[TOC]

#1、二维数组中的查找 

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

# 2、 字符串替换 

请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

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

# 3、从尾到头打印链表 

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

# 4 重建二叉树 

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

# 5 变态跳台阶 

<https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=11162&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking> 

一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

//状态转移方程  f(n)=f(n-1)+f(n-2)...+f(0)=f(n-1)+f(n-1)=2f(n-1)

由于 f(1)=1,f(2)=2....f(n)=2^(n-1)

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

# 6 数值的整数次方 

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
            {
                ret*=base;
                exponent--;//exponent--,变为偶数
            }
            exponent/=2;
            base*=base;
        }
        return flag==0? ret: 1/ret;
    }
};
```

# 7 调整数组顺序使奇数位于偶数前面 

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
            for(int j=0;j<array.size()-1-i;j++)
            {
                if(array[j]%2==0&&array[j+1]%2==1)
                    std::swap(array[j],array[j+1]);
            }
        }
    }
};
```

# 8 合并两个排序的链表 

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

# 9 树的子结构 

输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

```c++
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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==NULL||B==NULL) return false;
        return help(A,B)||isSubStructure(A->left,B)||isSubStructure(A->right,B);
    }
    bool help(TreeNode* A, TreeNode* B) {
         if(B==NULL) return true;
        if(A==NULL) return false;
        if(A->val!=B->val) return false;
        return help(A->left,B->left)&&help(A->right,B->right);
    }
  
};
```

# 10 二叉树的镜像 

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

# 11 顺时针打印矩阵

 https://www.nowcoder.com/practice/9b4c81a02cd34f76be2659fa0d54342a

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10. 

自定义方向    right-》down->left=>up

```c++
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

# 12 包含min函数的栈 

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

# 13 二叉搜索树的后序遍历序列

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
    class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size()<=1) return true;
       return  dfs(postorder,0,postorder.size()-1);
    }
     bool dfs(vector<int>& postorder,int left,int right)
     {
         if(left>=right) return true;
        int p=left;
        while(postorder[p]<postorder[right])
        p++;
        int m=p-1;
         while(postorder[p]>postorder[right])
         p++;
         return (p==right)&&dfs(postorder,left,m)&&dfs(postorder,m+1,right-1);
     }
};
```

# 14 复杂链表的复制 

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

# 15 [面试题36. 二叉搜索树与双向链表  LCOF](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/)

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
		if (pre == NULL)//pre用于记录双向链表中位于cur左侧的节点，即上一次迭代中的cur,当pre==null时，cur左侧没有节点,即此时cur为双向链表中的头节点
			head = cur;
		else //反之，pre!=null时，cur左侧存在节点pre，需要进行pre.right=cur的操作。
			pre->right = cur;
		cur->left = pre;
		pre = cur;
		inOrder(cur->right);
	}
};
```
# 45 [面试题07. 重建二叉树](https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/)

难度中等111收藏分享切换为英文关注反馈

输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

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
class Solution {
public:
 typedef vector<int>::iterator type;//区间是前闭后开的
  TreeNode*  _reConstructBinaryTree(type prebegin,type preend,type vinbegin,type vinend)
    {
        if(vinbegin==vinend)
            return NULL;
        TreeNode* root=new TreeNode(*prebegin);
        auto pos=std::find(vinbegin,vinend,*prebegin);
        int leftlen=pos-vinbegin;   //
        root->left=_reConstructBinaryTree(prebegin+1,prebegin+1+leftlen,vinbegin,pos);
        root->right=_reConstructBinaryTree(prebegin+1+leftlen,preend,pos+1,vinend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         if(preorder.empty())
            return NULL;
        return _reConstructBinaryTree(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }
};
```



# 16 平衡二叉树 

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



# 17 题目描述 字符串的排列 

输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

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
# 18 二叉搜索树的第k个结点 

给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。 <https://www.nowcoder.com/practice/ef068f602dde4d28aab2b210e859150a?tpId=13&tqId=11215&tPage=4&rp=4&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking> 

思路：二叉树的中序遍历，注意判断临界条件

```
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<TreeNode*> ans;
    void Inorder(TreeNode* pRoot)
    {
        if(pRoot!=NULL){
            Inorder(pRoot->left);
           ans.push_back(pRoot);
            Inorder(pRoot->right);
        }
        
    }
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        //中序遍历
        if(pRoot==NULL)
            return NULL;
        Inorder( pRoot);
        if(ans.size()>=k&&k>=1)
            return ans[k-1];
        else
            return NULL;
    }
    
};
```

# 19 对称的二叉树 

请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。

```c++
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
/*方法1，我开始想的是产生一个镜像的树，然后递归的判断这两个数是否相等，
麻烦，我们只需传进去两个一样的树，判断左子树是否等于右子树
如果一个二叉树是对称的，则假设有两个这样的树，1树的左节点等于2树的右节点
   1树的右节点等于2树的左节点*/
class Solution {
public:
    bool  equal(TreeNode*pRoot,TreeNode*MpRoot){
       if(pRoot==NULL&&MpRoot==NULL)
          return true;
        if(pRoot==NULL||MpRoot==NULL)
          return false;
        return (pRoot->val==MpRoot->val)&&(equal(pRoot->left,MpRoot->right))
            &&(equal(pRoot->right,MpRoot->left));
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        return equal(pRoot,pRoot);
    }

};
```

bfs

```c++
/*方法2:bfs，在队列中插入类似于两个树的元素，注意插入顺序，
和平常的bfs相比，插入四次，删除两次
q.push(tmp1->left);
            q.push(tmp2->right);
		    q.push(tmp1->right);
            q.push(tmp2->left);
            可以想像为由两个队列，一个插入的原来的树的元素，一个刚好相反。
      */
class Solution {
public:
        bool isSymmetrical(TreeNode* pRoot)
	{
		if (!pRoot)
			return true;
		queue<TreeNode* > q;
		q.push(pRoot->left);
        q.push(pRoot->right);
		while (!q.empty())
		{
		    TreeNode* tmp1 = q.front();
			q.pop();
            TreeNode* tmp2 = q.front();
			q.pop();
			if (tmp1==NULL&&tmp2==NULL) continue;
            if (tmp1==NULL||tmp2==NULL) return false;
            if(tmp1->val!=tmp2->val)
                return false;
			q.push(tmp1->left);
            q.push(tmp2->right);
		    q.push(tmp1->right);
            q.push(tmp2->left);
		}
      return true;
    }

};
```

# 20 二叉树的下一个结点 

给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

```c++
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    /*
    1、有右子树，下一结点是右子树中的最左结点，例如 B，下一结点是 H
    2、无右子树，且结点是该结点父结点的左子树，则下一结点是该结点的父结点，例如 H，下一结点是 E
    3、无右子树，且结点是该结点父结点的右子树，则我们一直沿着父结点追朔，直到找到某个结点是其父
    结点的左子树，如果存在这样的结点，那么这个结点的父结点就是我们要找的下一结点。例如 I，下
    一结点是 A；例如 G，并没有符合情况的结点，所以 G 没有下一结点
    */
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        //存在右数，找到右子树中最左的节点
        if(pNode->right!=NULL)
        {
            TreeLinkNode* tmp=pNode->right;
            while(tmp->left!=NULL)
            {
                tmp=tmp->left;
            }
            return tmp;
        }
        //不存在右树，是其父节点的左子树，则返回父节点
        if(pNode->next!=NULL&&pNode->next->left==pNode)
            return pNode->next;
        //不存在右树，是其父节点的右子树，则向上回溯，直到某个父节点是其父节点的父节点的左树
        if(pNode->next!=NULL&&pNode->next->right==pNode)
        {
            TreeLinkNode* tmp=pNode->next;
            while(tmp->next!=NULL&&tmp->next->right==tmp)
            {
                tmp=tmp->next;
            }
            return tmp->next;
        }
        return NULL;
    }
};
```

# 43按层打印二叉树 

从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。 
```c++
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
          if(pRoot==NULL)
              return {};
            vector<vector<int> > ans;
            queue<TreeNode*> q;
            q.push(pRoot);
            while(!q.empty()){
                int size=q.size();
                vector<int> nans(size,0);
                for(int i=0;i<size;i++)
                {
                    TreeNode* tmp=q.front();
                    q.pop();
                    nans[i]=tmp->val;
                    if(tmp->left)
                       q.push(tmp->left);
                    if(tmp->right)
                       q.push(tmp->right);
                }
                ans.push_back(nans);
            }
            return ans;
        }
    
};
```


#  21 把数组排成最小的数 

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

# 22 [263. 丑数](https://leetcode-cn.com/problems/ugly-number/)

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

# 23 第一个只出现一次的字符 

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

# 24 [数组中的逆序对](e)

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

```
/*
1 3 5 2 4 8分为两部分
1 3 5  和 2 4 8，进行归并 i是前面的指针，j是后面的指针
1 2 ...
当插入后面的元素2时，此时i=1 ,则mid-i+1这部分的即3 5和2就构成了逆序对w
*/

class Solution {
public:
  int reversePairs(vector<int>& nums) {
	if (nums.size() < 2) return 0;
	return merge_sort(nums, 0, nums.size()-1);
}
int merge_sort(vector<int>& v, int left, int right)
{
	if (left >= right) return 0;
	int mid = (left + right) / 2;
	int x1 = merge_sort(v, left, mid);
	int x2 = merge_sort(v, mid + 1, right);
	if (v[mid + 1] > v[mid]) return x1 + x2;
	int x3 = merge(v, left, mid, right);
	return x1 + x2 + x3;
}
int merge(vector<int>& v, int left, int mid, int right)
{
	if (left >= right) return 0;
	vector<int> tmp;
	int i = left, j = mid + 1;
	int ans = 0;
	while (i <= mid && j <= right)
	{
		if (v[i] <= v[j])
			tmp.push_back(v[i++]);
		else
		{
			tmp.push_back(v[j++]);
			ans += (mid- i + 1);
		}
	}
	while (i <= mid) tmp.push_back(v[i++]);
	while (j <= right) tmp.push_back(v[j++]);
	for (int i = 0; i < tmp.size(); i++)
	{
		v[i + left] = tmp[i];
	}
	return ans;
}
};
```



# 25 [215. 数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)

​	在未排序的数组中找到第 **k** 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。 

```c++
class Solution {
public:
void quick_sort(vector<int>& nums, int left, int right,int k)
{
    //从大到小排列
    if(left>=right)
    return;
    int i=left,j=right;
    while(i<j)
    {
        //从right向左找出大于nums[left]
        while(i<j&&nums[j]<nums[left])
        {
            j--;
        }
         //从left向右找出小于nums[left]
        while(i<j&&nums[i]>=nums[left])
        {
            i++;
        }
        if(i<j)
        swap(nums[i],nums[j]);
    }
        swap(nums[left], nums[i]);
	if (i - left + 1 == k)
		return;
	if (i - left + 1 > k)
		quick_sort(nums, left, i - 1, k);
	else
		quick_sort(nums, i + 1, right, k - (i-left)-1);
}
    int findKthLargest(vector<int>& nums, int k) {
       //使用快排
       quick_sort(nums,0,nums.size()-1,k);
       return nums[k-1];
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
    */
    /*
     sort(nums.begin(), nums.end(), greater<int>());
     return nums[k-1];
     */
    }
};
```



# 26 [面试题51. 数组中的逆序对](https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/)

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

# 27 数字在排序数组中出现的次数

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

# 28 数组中只出现一次的数字 

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
      //取出sum中左边是1的数的大小
        sum= sum & (~sum + 1);
      for(auto e:data)
      {
         if(e&sum)
             *num1^=e;
         else
           *num2^=e;
      }
    }
};
```

# 29 [面试题57 - II. 和为s的连续正数序列](https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/)

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

# 30 和为S的两个数字 

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

# 31 左旋转字符串 

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

# 32 翻转单词顺序列 

牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

```
/////
class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        string res,str;
        istringstream ss(s);
        while (ss >> str) stk.push(str), stk.push(" ");
        if (!stk.empty()) stk.pop();
        while (!stk.empty()) res += stk.top(), stk.pop();
        return res;
    }
};

//////////
class Solution {
public:
    string reverseWords(string s) {
	string str,ret;
	stringstream ss(s);
	while (ss >> str)
		ret = (str + " " + ret);
	return  ret.substr(0, ret.size() - 1);
}
};
```

# 33 [面试题61. 扑克牌中的顺子](https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/)

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

# 34 约瑟夫问题

#### [面试题62. 圆圈中最后剩下的数字](	https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/)

难度简单139收藏分享切换为英文关注反馈

0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。

例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

思路1：使用list模拟循环链表来模拟这个游戏，每过m-1个人，找到那个人然后it = li.erase(it);，直到最后只剩下一个人 然后return li.front() 即可。这个思路时间复杂度高，newcode可以过，但leetcode过不了。

```
class Solution {
public:
    int lastRemaining(int n, int m) {
        
	if (n == 0)
		return -1;
	list<int> li;
	for (int i = 0; i < n; i++)
		li.push_back(i);
	auto it = li.begin();
	while (li.size() > 1)
	{
		int i = 0;
		for (; i < m-1; i++)
		{
 			if (it == li.end())
				it = li.begin();
			it++;
		}
		if (it == li.end())
			it = li.begin();
		it = li.erase(it);
	}
	return li.front();
    }
};
```

思路2：（动态规划）公式法 f(n,m)= (f(n-1,m)+m)%n   f(n,m)表示，N个人报数，每报到M时杀掉那个人，最终胜利者的编号 ,状态转移方程    dp[i]=(dp[i-1]+m)%i;

当删除报到M时杀掉那个人后，我们以他下一个的人为起始坐标0从新计数，所以可以理解为后面的坐标向前移动了m位，m前面的补到m后面的位置，直到最后。

而我们的思路2刚好相反，这上述的逆过程，每报到M时杀掉那个人时，后面的向后移动m位，比如，设m=3,n=11, 我们已知当f(n-1,m)即f(10，3)的胜利者编号，那么n=11的胜利者编号就是n=10的胜利者编号后移m位，即+m，但有可能越界，所以%n

```
//直接套公式，递归
class Solution {
public:
    int f(int n, int m) {
        if(n==1)
        return 0;
        return (f(n-1,m)+m)%n;
};
    int lastRemaining(int n, int m) {
        return f(n,m);
    }
};
//非递归
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {     
        if(n==0)
            return -1;
	int ret=0;
        for(int i=2; i<=n;i++)
        {
            ret=(ret+m)%i;//dp[i]=(dp[i-1]+m)%i;
        }
        return ret;
    }
};
```

# 35 求1+2+3+...+n 

求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

```c++
class Solution {
public:
    int Sum_Solution(int n) {
        return (int)pow(n,2)+n>>1;
    }
};

===================================位运算
逻辑运算符的短路效应：
常见的逻辑运算符有三种，即 与 &&，或 || 非 !! ；而其有重要的短路效应，如下所示：

if(A && B)  // 若 A 为 false ，则 B 的判断不会执行（即短路），直接判定 A && B 为 false

if(A || B) // 若 A 为 true ，则 B 的判断不会执行（即短路），直接判定 A || B 为 true
本题需要实现 “当 n = 1n=1 时终止递归” 的需求，可通过短路效应实现。

n > 1 && sumNums(n - 1) // 当 n = 1 时 n > 1 不成立 ，此时 “短路” ，终止后续递归
先写出递归
class Solution {
public:
    int Sum_Solution(int n) {
       if(n==1)
           return 1;
        n+=Sum_Solution(n-1);
        return ans;
    }
};
//改造递归
class Solution {
public:
    int Sum_Solution(int n) {
        n&&	(n+=Sum_Solution(n-1));
        return ans;
    }
};
```

# 36 不用加减乘除做加法 

写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

```

思路：
& 按位与运算：相同位的两个数字都为1，则为1；若有一个不为1，则为0。两个数相与，并左移一位：相当于求得进位
1&1=1 将1左移一位变成了10，相当于拿到了进位。
^ 按位异或运算：相同位置不同则为1，相同则为0。相当于每一位相加，而不考虑进位。
第一步 异或——无进位相加得result1 (a^b)
第二步 与+左移一位——求得进位result2 （a&b）<<1
第三步 result = result1 + result2即是结果
但问题在于，result1 + result2可能还有进位，因此result还要重复一二步这个过程。直到没有进位，异或的结果就是最终的结果为止
如 101 + 011 -> 110 + 1010 -> 1100 + 0100 -> 1000 + 1000 -> 0 （异或出现了0，返回上一次异或的结果）
最终得到的是1000 也就是5+3=8

class Solution {
public:
    int Add(int num1, int num2)
    {
         //两数异或相当于无进位相加，两个数相与相当于求两数的进位
         //最后将进位（相与的结果）和异或的结果相加即是最终结果，在因为这个过程又有可能存在进位
        //所以需要循环判断(判断carry是否等于0,本题直接使用num2也可以 num2=carry)
        /*
               10+7
               1010    10
               0111    7
               10^7=  1101   ->13
               10&7<<1=  0100   ->4
               13+4=17
        */
        if(num1==0)
            return num2;
        if(num2==0)
            return num1;
        while(num2!=0)
        {
            int a=num1^num2;
            int carry=(num1&num2)<<1;
            num1=a;
            num2=carry;
        }
        return num1;
    }
};





```

# 37 [1. 两数之和](https://leetcode-cn.com/problems/two-sum/)

给定一个整数数组 `nums` 和一个目标值 `target`，请你在该数组中找出和为目标值的那 **两个** 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        基本上和暴力解法类似：回忆暴力解法，双重循环判断nums[i]+nums[j]==target
        我们先把元素插入到哈希表（hash表value存放元素的下标）中，在第2个for循环中，对于第i个元素，直接查找target-nums[i]是否存在
        ，存在了就说明找到了，返回元素的下标{i，mp[target-nums[i]]}
        这里必须加判断条件mp[target-nums[i]]!=i
        以为有可能 nums = [2, 3，4], target = 6
        这样就导致返回的是{1，1}而不是{0，2}
        */
       unordered_map <int,int> mp;
       for(int i=0;i<nums.size();i++)
          mp[nums[i]]=i;
        for(int i=0;i<nums.size();i++)
        {  
            if(mp.find(target-nums[i])!=mp.end()&&mp[target-nums[i]]!=i)
               return {i,mp[target-nums[i]]};
        }
        return {};
    }
};

```

# 38 题目描述 构建乘积数组 

<https://www.nowcoder.com/practice/94a4d381a68b47b7a8bed86f2975db46?tpId=13&tqId=11204&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking> 

给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];）

![对称](E:\duzhiqiang\我的编程资料和代码\github\picture\对称.jpg)

```c++
	class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
       if(A.size()==0)
           return {};
        vector<int> left(A.size(),1);
        //left=A[0]*A[1]*....*A[i-1]
        for(int i=1;i<A.size();i++)
        {
            left[i]=A[i-1]*left[i-1];
        }
        int tmp=1;
        //right=A[n-1]*A[n-2]*....*A[i+1]
        for(int i=A.size()-2;i>=0;i--)
        {
            tmp=tmp*A[i+1];
            left[i]=tmp*left[i];
        }
        return left;
    }
};
```

# 39 题目描述 数据流中的中位数 

如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。

暴力方法：尾插之后，在从新排序

```c++
class Solution {
public:
    void Insert(int num)
    {
        v.push_back(num);
    }

    double GetMedian()
    { 
       double res;
        sort(v.begin(),v.end());
        if((size&1)==0)//判断是否为偶数
            return (v[(size/2)-1]+v[size/2])/2;
        else
            return v[size/2];
    }
private:
    vector<double> v;
};
```

快排：时间复杂度：O(n) + O(log n) ≈O(n). 

```c++
class Solution {
public:
    void Insert(int num)
    {
        if(v.empty())
        v.push_back(num);
        else
        {//快排   lower_bound函数，在数组v中找到第一个大于num的位置(相反是upper_bound)
            auto i=lower_bound(v.begin(),v.end(),num);
             v.insert(i,num);
        }
    }

    double GetMedian()
    { 
        int size=v.size();
        if((size&1)==0)//判断是否为偶数
            return (v[(size/2)-1]+v[size/2])/2;
        else
            return v[size/2];
    }
private:
    vector<double> v;
};
```

利用两个堆来维护，一个大根堆，一个小根堆，容易想到是保持两个堆的元素的个数为  大根堆=n/2 或者n/2+1（偶数或奇数）并且大根堆的所有元素都小于小根堆的所有元素。这样我们在求中位数时候，只需取大根堆的堆顶元素（当数组元素个数为奇数）或 大根堆的堆顶元素和 大根堆的堆顶元素的平均值。

所以重点是维护好这两个堆，利用priority_queue,在插入元素的时候，先插入到大根堆，如果大根堆的元素个数大于小根堆，则将大根堆的堆顶元素push到小根堆（这样只匹配了数目，还没有匹配大小），当然还需要循环判断（大根堆的根是否小于小根堆的根）1

```c++
class MedianFinder {
public:
    void addNum(int num) {
         maxheap.push(num);
         if(maxheap.size()-minheap.size()>1)
         {
             minheap.push(maxheap.top());
             maxheap.pop();
         }
         //如果大根堆的最大值比小根堆的最小值大，则交换 
        /*
        如果没有下面判断  输入元素为1，2，3   大根堆为 3 1  小根堆为2  这样就不能返回正确的元素
        这是因为是大根堆先插入两个元素才在较较大值插入到minheap中，如果偶数的话就不存在问题，但如果是奇数，则maxheap比minheap多插入一次，不能确定这最后的元素是否大于minheap的top（），所以还需要一次比较
        */
         if((minheap.size()>0)&&maxheap.top()>minheap.top())
         {
             int min=minheap.top();minheap.pop();
              int max=maxheap.top(); maxheap.pop();
              minheap.push(max);
              maxheap.push(min);
         }
    }
    double findMedian() {
           if((maxheap.size()+minheap.size())%2==1)
              return (double)maxheap.top();
            return (maxheap.top()+minheap.top())*0.5;
    }
private:
      priority_queue<int>  maxheap;
      priority_queue<int,vector<int>,greater<int>>  minheap;

};

```
# 40 矩阵中的路径  wordsearch

```c++
class Solution {
public:
    //回溯法
    vector<vector<bool>> vis;
    char* m;
    int n;
    bool dfs(int pos,int x,int y,int rows, int cols, char* str)
    {
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        if(pos==n)
            return true;
        for (int i = 0; i < 4; i++)
	    {
		int xx = dx[i] + x;
		int yy = dy[i] + y;
		if (xx < 0 || xx >= rows || yy < 0 || yy >= cols)
			continue;
		if (m[xx*cols + yy] != str[pos])
			continue;
		if (vis[xx][yy] == true)
			continue;
		vis[xx][yy] = true;
		if (dfs(pos + 1, xx, yy, rows, cols, str))
			return true;
		vis[xx][yy] = false;
	   }
        return false;
    }
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(rows<0||cols<0||str==NULL)
            return false;
       vis.assign(rows,vector<bool>(cols,false));
        m=matrix;
        n=strlen(str);
      for(int i=0;i<rows;i++)
      {
          for(int j=0;j<cols;j++)
          {
              if(matrix[i*cols+j]!=str[0])
                  continue;
              else{
                   vis[i][j]=true;
                if (dfs(1,i,j,rows,cols,str))
                  return true;
                 vis[i][j]=false;
              }
          }
      }
        return false;
    }

};
```

# 41 机器人的运动范围

地上有一个m行n列的方格，从坐标 `[0,0]` 到坐标 `[m-1,n-1]` 。一个机器人从坐标 `[0, 0] `的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？ 

```c++
class Solution {
public:
    int getnum(int x)
    {
        int sum=0;
        while(x)
        {
            sum+=x%10;
            x/=10;
        }
        return sum;
    }
    int dfs(int x,int y, int rows, int cols,int threshold,vector<vector<bool>>& vis)
    {
        if(x<0||x>=rows||y<0||y>=cols||vis[x][y]==true||(getnum(x)+getnum(y))>threshold)
            return 0;
        vis[x][y]=true;
        return 1+dfs(x+1,y,rows,cols,threshold,vis)+dfs(x-1,y,rows,cols,threshold,vis)
            +dfs(x,y+1,rows,cols,threshold,vis)+dfs(x,y-1,rows,cols,threshold,vis);
    }
    int movingCount(int threshold, int rows, int cols)
    {
        if(rows<0||cols<0)
            return 0;
        vector<vector<bool>> vis(rows,vector<bool>(cols,false));
        return dfs(0,0,rows,cols,threshold,vis);
    }
};

```

```c++
class Solution {
public:
  //1+dfs(i-1,j)+dfs(i,j-1)+dfs(i+1,j)+dfs(i,j+1)
  int getnum(int x)
  {
      int sum=0;
      while(x)
      {
          sum+=x%10;
          x/=10;
      }
      return sum;
  }
  vector<vector<bool>> vis;
    int movingCount(int m, int n, int k) {
       // vis.assign(m,vector<bool>(n,false));
       vector<vector<bool>> vis(m,vector<bool>(n,false));
        int ans=0;
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        queue<pair<int,int>> que;
        que.push(make_pair(0,0));
        ans++;
        vis[0][0]=true;
        while(!que.empty())
        {
            auto [x,y]=que.front();
            que.pop();
            for(int i=0;i<4;i++)
            {
                x=x+dx[i];
                y=y+dy[i];
                if(x>=m||x<0||y>=n||y<0||vis[x][y]==true||(getnum(x)+getnum(y))>k)
                continue;
                que.push(make_pair(x,y));
                vis[x][y]=true;
                ans++;
            }
        }
        return ans;
    }
};
```



# 42 剪绳子 /[343. 整数拆分](https://leetcode-cn.com/problems/integer-break/)

给定一个正整数 *n*，将其拆分为**至少**两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。 

```
class Solution {
public:
/*   f(n)=max(1*f(n-1),2*f(n-2),...)
   res=max(res,i*integerBreak(n-i))
   dp[i]=max(dp[i],1*dp[i-1],2*dp[i-2],...j*dp[i-j]...)
   需要注意：i*integerBreak(n - i)不一定比i*(n-i)大，所以需要去其中最大值
*/
/*
    int integerBreak(int n) {
     //解法1 递归
         if(n==2)
         return 1;
      int res=-1;
      for(int i=1;i<n;i++)
      {
      	res = max(res, max(i * (n - i), i * integerBreak(n - i)));
      }
      return res;
    }
    */
    /*
     int integerBreak(int n) {
     //解法2 带备忘录的递归
         if(n==2)
         return 1;
         vector<int> memo(n+1,0);
       int res=-1;
       if(memo[n]!=0)
       return memo[n];
       for(int i=1;i<n;i++)
       {
       	res = max(res, max(i * (n - i), i * integerBreak(n - i)));
       }
       memo[n]=res;
       return res;
    }
    */
/*
     int integerBreak(int n) {
     //解法3 动态规划 dp[i]=max(dp[i],max(j*(i-j),j*dp[i-j]))
         if(n==2)
         return 1;
         vector<int> dp(n+1,0);
         dp[2]=1;
         for(int i=3;i<=n;i++)
         {
             for(int j=1;j<i;j++)
             {
                 dp[i]=max(dp[i],max(j*(i-j),j*dp[i-j]));
             }
         }
         return dp[n];
    }
    */
     int integerBreak(int n) {
          if (n == 2) return 1;
          if (n == 3) return 2;//这里3必须进行划分，不然b=0,返回的是3^1=3，这个结果时没有进行划分
         int b=n%3;
         if(b==0)
            {
                int a=n/3;
                return pow(3,a);
            }
         if(b==1)
            {
                int a=n/3;
                return pow(3,a-1)*4;
            }
         int a=n/3;
                return pow(3,a)*2;
     
     }
};
```

# 43 [142. 环形链表 II](https://leetcode-cn.com/problems/linked-list-cycle-ii/)

给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
/*  设链表 无环长度为a  有环长度为b
两种方法：第一种，使用hash表，multiset，当count==2是就找到了相交节点
第二种：快慢指针：fast和slow同时指向头节点，fast走两步，slow走一步，如果有环，则两个指针相遇，
第一次相遇时，fast走了f步， slow走了s步，f=2s=s+nb,则f=2nb,s=nb
随后，将fast指针指向头节点，接下来和slow指针一步一步的移动，如果再次相遇则就是环的入口
这是因为当 slow走了 a+nb步(nb是n个环的长度，slow走了n个环意味着
当他从起点出发，走了n圈后，必定他还会在起点)，fast走了a步，相遇，
*/
    ListNode *detectCycle(ListNode *head) {
        /* 
          multiset<ListNode*> ms;
        ListNode* p=head;
        while(p)
        {
            ms.insert(p);
            if(ms.count(p)==2)
            return p;
            p=p->next;
        }
        return nullptr;
        */
        if(head==NULL||head->next==NULL)
        return NULL;
         ListNode* p=head;
         ListNode* q=head;
         //先找到两个指针相交的位置
         while(q!=NULL)
         {
             if(q->next==NULL) return NULL;
             q=q->next->next;
             p=p->next;
             if(p==q)
             break;
         }
         if(q==NULL)//说明没有环
            return NULL;
         //说明是有环 q重新指向头节点，然后和p一步一步的走
         q=head;
         while(p!=q)
         {
              p=p->next;
              q=q->next;
         }
         return p;
    }
};
```

# 44 滑动窗口的最大值 

给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

```
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
       if(num.size()==0)
           return {};
        vector<int> ret;
        //一共num.size()-size+1个滑动窗口
        for(int i=0;i<num.size()-size+1;i++)
        {
            int Max=-1;
            for(int j=i;j<size+i;j++)
            {
                 Max=max(num[j],Max);
            }
            ret.push_back(Max);
        }
        return ret;
    }
};
```

单调队列优化	

```c++
class MonotonicQueue 
{
public:
  void push(int x)
  {
      //保持单调性，删除比新元素x小的所有元素
      while(!dq.empty()&&x>dq.back())
        dq.pop_back();
    dq.push_back(x);
  }
  int getmax()
  {
    return dq.front();
  }
  void pop()
  {
      dq.pop_front();
  }
 private:
  deque<int> dq;
};
class Solution {
public:
//单调队列优化
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         if(nums.size()==0)
              return {};
       MonotonicQueue mq;
        vector<int> ans;
          for(int i=0;i<nums.size();i++)
          {
              mq.push(nums[i]);
              if(i-k+1>=0)
              {
                  ans.push_back(mq.getmax());
                  if(mq.getmax()==nums[i-k+1])
                  mq.pop();
              }
          }
          return ans;
    }

};
```

# 47 [剑指 Offer 47. 礼物的最大价值](https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/)

![1598754948058](E:\duzhiqiang\我的编程资料和代码\github\picture\47.png)

```
//动态规划(我真的太菜了，难受)
//dp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i][j]
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        //dp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i][j]
        int m=grid.size();
        int n=grid[0].size();
        if(m==0||n==0) return 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++)
        dp[i][0]=dp[i-1][0]+grid[i][0];
        for(int i=1;i<n;i++)
        dp[0][i]=dp[0][i-1]+grid[0][i];
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
//也可以dfs求出所有的解，找出最大的，这里只给出所有的解的dfs
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>> nans;
vector<int> tmp;
int n;
vector<int>dx = { 0,1 };
vector<int>dy = { 1,0 };
vector<vector<int>> vis;
void dfs(vector<vector<int>>&v, int i, int j)
{

	if (i == n - 1 && j == n - 1)
	{
		int t = 0;
		for (auto e : tmp)
		{
			t += e;
		}
		t = t + v[0][0] + v[n - 1][n - 1];
		nans.push_back(tmp);
		return;
	}

	for (int d = 0; d < 2; d++)
	{
		int ii = i + dx[d];
		int jj = j + dy[d];
		if (ii >= v.size() || jj >= v.size() || vis[ii][jj] == 1) continue;
		vis[ii][jj] = 1;
		tmp.push_back(v[ii][jj]);
		dfs(v, ii, jj);
		tmp.pop_back();
		vis[ii][jj] = 0;
	}
}
/*
{2,3,1}
 {1,5,1}
 {4,2,1}
*/
int main()
{
	vector<vector<int>> v = {
		{2,3,1}, {1,5,1},{4,2,1}
	};
	n = v.size();
	vis.assign(n, vector<int>(n, 0));
	vis[0][0] = 1;
	tmp.push_back(v[0][0]);
	dfs(v, 0, 0);
	int res = 0;
	/*for (int i = 0; i < n; i++)
	{
		res = max(res, ans[i]);
	}*/
	//cout << res << endl;
	for (auto e : nans)
	{
		for (auto ele : e)
			cout << ele << " ";
		cout << endl;
	}
	
}
```

