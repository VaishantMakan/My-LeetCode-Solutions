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
    
    void helper(TreeNode* node, int max, int& ans)
    {
        if(node == NULL)
            return;
        
        if(node->val >= max)
        {
            ans += 1;
            max = node->val;
        }
        
        helper(node->left, max, ans);
        helper(node->right, max, ans);
        
        return;
    }
    
    int goodNodes(TreeNode* root) 
    {
        int ans=0;
        
        helper(root, root->val, ans);
        
        return ans;
    }
};