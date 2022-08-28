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
    
    int sum=0;
    int helper(TreeNode* root, bool lefty)
    {
        if(!root)
            return sum;
        
        helper(root->left, true);
        helper(root->right, false);
        
        if(root->left == NULL && root->right == NULL && lefty == true)
        {
            sum += root->val;
        }
        
        return sum;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        
        return helper(root, false);
    }
};