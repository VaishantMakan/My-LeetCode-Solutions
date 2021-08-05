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
class Solution {
public:
    
    //optimised solution
    
    int minDepth(TreeNode* root) {
    
        if(root == nullptr)
            return 0;
    
        queue<TreeNode*> q;
        q.push(root);
        int depth=1;
    
        while(!q.empty())
        {
            int level_nodes = q.size();
            for(int i=0;i<level_nodes;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
            
                if(temp->left == nullptr && temp->right == nullptr)
                    return depth;
            
                if(temp->left != nullptr)
                     q.push(temp->left);
            
                if(temp->right != nullptr)
                    q.push(temp->right);
            }
         depth++;
        }
        return depth;
    }
};
    
    
    
// This below solution is O(n) becasue even if the leaf node i.e min depth is just next of root node even then it will check all the tree nodes .....  To make it better use bfs instead of dfs.....
    
// int minDepth(TreeNode* root) {
    
//         if(root==nullptr)
//         {
//             return 0;
//         }
        
//         int l = minDepth(root->left);
//         int r = minDepth(root->right);
        
//         if(l==0 && r!=0)
//             return r+1;
//         else if(l!=0 && r==0)
//             return l+1;
//         else if(l==0 && r==0)
//             return 1;
//         else
//             return min(l,r)+1;
//     }
// };