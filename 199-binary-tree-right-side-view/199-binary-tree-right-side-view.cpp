/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// DFS Solution : 

class Solution {
public:
    
    void recursion(TreeNode *root, int level, vector<int> &ans)
    {
        if(root==NULL) 
            return;
        
        if(ans.size()==level) 
            ans.push_back(root->val);
        
        recursion(root->right, level+1, ans);
        recursion(root->left, level+1, ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int>ans;
        if(root == NULL)
            return ans;
        
        recursion(root, 0, ans);
        
        return ans;
    }
};

// BFS Solution : 

// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
        
//         vector<int>ans;
//         if(root == NULL)
//             return ans;
        
//         vector<vector<int>>bfs;
        
//         queue<TreeNode*>q;
//         q.push(root);
        
//         while(!q.empty())
//         {
//             int n = q.size();
//             vector<int>level;
//             for(int i=0;i<n;i++)
//             {
//                 TreeNode* node = q.front();
//                 q.pop();
                
//                 if(node->left != NULL)
//                     q.push(node->left);
                
//                 if(node->right != NULL)
//                     q.push(node->right);
                
//                 level.push_back(node->val);
//             }
//             bfs.push_back(level);
//         }
        
//         int n=bfs.size();
//         for(int i=0;i<n;i++)
//         {
//             int m=bfs[i].size();
//             ans.push_back(bfs[i][m-1]);
//         }
        
//         return ans;
//     }
// };