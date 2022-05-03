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
    
    // recursive soln
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == NULL)
            return root;
        
        invertTree(root->left);
        invertTree(root->right);
        
        swap(root->left, root->right);
        
        return root;
    }
    
    // iterative soln i.e using bfs 
//     TreeNode* invertTree(TreeNode* root) {
        
//         if(root == NULL)
//             return root;
        
//         queue<TreeNode*> q;
//         q.push(root);
        
//         while(!q.empty())
//         {
//             TreeNode* node = q.front();
//             q.pop();
            
//             if(node->left != NULL)
//                 q.push(node->left);
            
//             if(node->right != NULL)
//                 q.push(node->right);
            
//             swap(node->left, node->right);
//         }
        
//         return root;
//     }
    
};