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

