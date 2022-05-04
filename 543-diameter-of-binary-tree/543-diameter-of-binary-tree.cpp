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
    
    int helper(TreeNode* root, int &dm)
    {
        if(root == NULL)
            return 0;
        
        int left_max_height = helper(root->left, dm);
        int right_max_height = helper(root->right, dm);
        
        dm = max(dm, left_max_height+right_max_height); // calculates and stores max diameter
        
        return 1 + max(left_max_height, right_max_height); // this returns the max height of the tree at this point
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        int dm=0;
        helper(root, dm);
        return dm;
    }
};