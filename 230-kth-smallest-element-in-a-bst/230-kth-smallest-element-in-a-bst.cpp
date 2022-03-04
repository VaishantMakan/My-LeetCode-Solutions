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
    
    void helper(TreeNode* root, int &k, int &ans)
    {
        if(!root)
            return;
        
        helper(root->left, k, ans);
        
        if(k==0)
            return;
        
        ans = root->val;
        
        helper(root->right, --k, ans);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        int ans;
        
        helper(root, k, ans);
        
        return ans;
    }
};