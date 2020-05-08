#### 面试题32 - I. 从上到下打印二叉树

从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

 <https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/> 

bfs大法，需要队列，因为二叉树只有根节点和子节点，不牵扯重复访问的问题，所以不需要vis数组记录

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
    vector<int> levelOrder(TreeNode* root) {
         //bfs大法  队列
         vector<int> ans;
         if(root==NULL)
         return ans;
         queue<TreeNode*> que;
         que.push(root);
         while(!que.empty())
         {
             TreeNode *tmp=que.front();
             que.pop();
             ans.push_back(tmp->val);
             if(tmp->left!=NULL) que.push(tmp->left);
             if(tmp->right!=NULL) que.push(tmp->right);
         }
         return ans;
    }
};
```

#### [面试题32 - II. 从上到下打印二叉树 II](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/)

从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。 

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
    vector<vector<int>> levelOrder(TreeNode* root) {
          //bfs大法，和之前普通的层序遍历差不多，只需要加入一个depth队列记录层数
           vector<vector<int>> ans;
           if(root==NULL)
           return ans;
           queue<TreeNode*> que;
           que.push(root);
           queue<int> depth;
           depth.push(0);
           while(!que.empty())
           {
               TreeNode* tmp=que.front(); que.pop();
               int d=depth.front(); depth.pop();
               if(d==ans.size())
               ans.emplace_back();
               ans[d].push_back(tmp->val);
               if(tmp->left!=NULL)  
               {
                   que.push(tmp->left); 
                    depth.push(d+1);
               }
               if(tmp->right!=NULL) 
               {
                   que.push(tmp->right); 
                    depth.push(d+1);
               }
           }
           return ans;
    }
};
//bfs也可以这样 使用pair(TreeNode*,int depth)
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
          //bfs大法，和之前普通的层序遍历差不多，只需要加入一个depth队列记录层数
           vector<vector<int>> ans;
           if(root==NULL)
           return ans;
           queue<pair<TreeNode*, int>> que;//ThreeNode*代表节点，int代表层数
           que.push(make_pair(root,0));
           while(!que.empty())
           {
               TreeNode* tmp=que.front().first;
               int d=que.front().second;  
               que.pop();
               if(d==ans.size())
               ans.emplace_back();
               ans[d].push_back(tmp->val);
               if(tmp->left!=NULL)  
               {
                   que.push(make_pair(tmp->left,d+1)); 
               }
               if(tmp->right!=NULL) 
               {
                   que.push(make_pair(tmp->right,d+1)); 
               }
           }
           return ans;
    }
};



//dfs大法
class Solution {
public:
   vector<vector<int>> ans;
   void dfs(TreeNode* t,int dep)
   {
       if(t==NULL)
       return ;
       if(ans.size()==dep)
              ans.emplace_back();
      ans[dep].push_back(t->val);
    dfs(t->left,dep+1);
    dfs(t->right,dep+1);
   }
    vector<vector<int>> levelOrder(TreeNode* root) {
          //dfs大法
          dfs(root,0);
          return ans;
    }
};
```

#### [47. 全排列 II](https://leetcode-cn.com/problems/permutations-ii/)

给定一个可包含重复数字的序列，返回所有不重复的全排列。 

![asd2](E:\duzhiqiang\比特51c语言\github\picture\asd2.jpg)

```c++
class Solution {
public:
vector<int> nu;
vector<int> nans;
vector<vector<int>> ans;
vector<int> vis;
int n;
void dfs(int cur){
    if(cur==n) {
        ans.push_back(nans);
        return;
    }
    else{
        for(int i=0;i<n;i++){
            if(vis[i]==1) continue;
            //如果当前节点和前一节点一样并且前一节点已经被遍历过，则跳过
            if(i>0&&nu[i-1]==nu[i]&&!vis[i-1]) continue;
            vis[i]=1;
            nans[cur]=nu[i];
            dfs(cur+1);
            vis[i]=0;
        }
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size()==0)
        return ans;
        n=nums.size();
        sort(nums.begin(),nums.end());
        nu=nums;
        nans.assign(n,0);
         vis.assign(n,0);
        dfs(0);
        return ans;
    }
};
```

#### [112. 路径总和](https://leetcode-cn.com/problems/path-sum/)

给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

**说明:** 叶子节点是指没有子节点的节点。

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
 bool hasPathSum(TreeNode* root, int sum) {
        return DFS(root, sum);
    }
    bool DFS(TreeNode* root, int sum) {
        if(root==NULL)
        return false;
        if(root->left==NULL&&root->right==NULL)
        return sum==root->val;
        return  DFS(root->left,sum-root->val)||DFS(root->right,sum-root->val);
    }
};
```

#### 二叉树中和为某一值的路径 

输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。 <https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&tqId=11177&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking> 

思路：dfs+回溯

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
    vector<vector<int> > ans;
    vector<int> path;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
         dfs(root,expectNumber);
        return ans;
    }
    void dfs(TreeNode* root,int sum)
    {
        if(root==NULL)
            return ;
        if(root->left==NULL&&root->right==NULL){
            sum-=root->val;
            if(sum==0)
            {
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
            }
            return;
        }
        path.push_back(root->val);
        dfs( root->left, sum-root->val);
        path.pop_back();
         path.push_back(root->val);
        dfs( root->right, sum-root->val);
        path.pop_back();
    }
};

```

#### [46. 全排列](https://leetcode-cn.com/problems/permutations/)

给定一个 **没有重复** 数字的序列，返回其所有可能的全排列。 

```c++
class Solution {
public:
/*
void dfs()
{
    if(nans.size()==n)
    {
        ans.push_back(nans);
        return;
    }
   for(int i=0; i<n; i++)
        {
           if(vis[i]==0)
           {
               vis[i]=1;
               nans.push_back(nu[i]);
               dfs();
               nans.pop_back();
               vis[i]=0;
           }
        }
}
*/
vector<vector<int>> ans;
vector<int> nans;
vector<int> nu;
void dfs(int pos)
{
    if(nans.size()==nu.size())
    {
        ans.push_back(nans);
        return;
    }
   for(int i=pos; i<nu.size(); i++)
        {
            nans.push_back(nu[i]);
           std:: swap(nu[i], nu[pos]);
            dfs(pos+1);
             std:: swap(nu[i], nu[pos]);
             nans.pop_back();
           }
       
}
    vector<vector<int>> permute(vector<int>& nums) {
        nu=nums;
        dfs(0);
        return ans;
    }
};
```

#### [77. 组合](https://leetcode-cn.com/problems/combinations/)

给定两个整数 *n* 和 *k*，返回 1 ... *n* 中所有可能的 *k* 个数的组合。 

回溯法解决组合问题。和排序问题不同的是，在组合问题中元素的顺序不考虑，只需要从当前位置向后寻找。排序问题每次都需要从头寻找，需要用visited数组记录访问过的元素。

常规bfs模板，第一种方法对于元素只是选和不选的问题 时间复杂度高（2^n）

```c++
class Solution {
public:
  vector<vector<int>>  ans;
    vector<int> nans;
    vector<vector<int>> combine(int n, int k) {
         dfs(1,n,k);
         return ans;
    }
    void dfs(int pos, int n,int k)
    {
        if(nans.size()==k)
         {
             ans.push_back(nans);
             return;
         }
         if(pos>n)
           return;
           nans.push_back(pos);
           dfs(pos+1,n,k);
           nans.pop_back();
             dfs(pos+1,n,k);
    }
};
第二种方法，利用一个for循环，可以避免重复 （即如果出现1 ，则后面再也不会出现1）
class Solution {
public:
  vector<vector<int>>  ans;
    vector<int> nans;
    vector<vector<int>> combine(int n, int k) {
         dfs(1,n,k);
         return ans;
    }
    void dfs(int pos, int n,int k)
    {
        if(nans.size()==k)
         {
             ans.push_back(nans);
             return;
         }
        for(int i=pos; i<=n; i++)
             {
                 nans.push_back(i);
                 dfs(i+1,n,k);
                  nans.pop_back();
             }
    }
};
```

 [79. 单词搜索](https://leetcode-cn.com/problems/word-search/)

给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

//dfs  标准模板   

在矩阵中先找到这个单词的起始位置，再进行dfS(要用vis数组记录), 从上下左右四个方向去比较（需要回溯）

```c++
class Solution {
public:
    vector<vector<int>> vis;
    int m,n;
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    bool dfs(int pos,int i, int j,vector<vector<char>>&  board,string word)
    {
        if(pos==word.size()-1)
        return true;
        for(int d=0;d<4;d++)
        {
            //从上下左右四个方向去比较
            int ii=i+dx[d];
            int jj=j+dy[d];
            if(ii<0||ii>=m||jj<0||jj>=n)
            continue;
            if(vis[ii][jj]==1||board[ii][jj]!=word[pos])
            continue;
            vis[ii][jj]=1;
            if(dfs(pos+1,ii,jj,board,word))
            return true;
            vis[ii][jj]=0;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
         if(board.size()==0||board[0].size()==0)
         return false;
         m=board.size();
          n=board[0].size();
         vis.assign(m,vector<int>(n,0));
         for(int i=0;i<m;i++)
         {
             for(int j=0;j<n;j++)
             {              
                 if(board[i][j]!=word[0])
                 continue;
                 else if(board[i][j]==word[0])
                 {
                    vis[i][j]=1;
                     if(dfs(1,i,j,board,word)){
                     return true;}
                    vis[i][j]=0;
                 }
             }
         }
         return false;
    }
};
```

