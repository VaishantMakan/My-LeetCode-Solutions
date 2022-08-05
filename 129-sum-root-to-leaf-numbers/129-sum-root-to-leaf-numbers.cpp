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
    
    void helper(TreeNode* node, int currNum, int& ans)
    {
        if(node == NULL)
            return;
        
        currNum = (currNum * 10) + node->val;
        
        if(node->left == NULL && node->right == NULL)
        {
            ans += currNum;
            return;
        }
        
        helper(node->left, currNum, ans);
        
        helper(node->right, currNum, ans);
        
    }
    
    int sumNumbers(TreeNode* root) {
        
        int ans = 0;
        
        helper(root, 0, ans);
        
        return ans;
    }
};