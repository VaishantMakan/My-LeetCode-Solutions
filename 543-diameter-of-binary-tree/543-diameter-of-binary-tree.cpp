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
    
    int maxSoFar = 0;
    
    int helper(TreeNode* node)
    {
        if(node == NULL)
            return 0;
        
        int left = helper(node->left);
        int right = helper(node->right);
        
        maxSoFar = max(maxSoFar, left + right + 1);
        
        return 1 + max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        helper(root);
        return maxSoFar-1;
    }
};