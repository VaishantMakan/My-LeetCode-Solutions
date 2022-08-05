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
    
    bool helper(TreeNode* root, int targetSum, int curr)
    {
        
        curr += root->val;
        
        if(root->left == NULL && root->right == NULL)
        {
            return curr == targetSum ? true : false;    
        }
        
        bool lefty = false;
        bool righty = false;
        
        if(root->left != NULL)
            lefty = helper(root->left, targetSum, curr);
        
        if(root->right != NULL)
            righty = helper(root->right, targetSum, curr);
        
        return lefty || righty;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root == NULL)
        {
            return false;    
        }
        
        return helper(root, targetSum, 0);
    }
};