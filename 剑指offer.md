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

2、 请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。 

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

3、从尾到头打印链表 

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

