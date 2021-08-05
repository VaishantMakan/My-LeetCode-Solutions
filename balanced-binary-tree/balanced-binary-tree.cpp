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
    
    bool helper(TreeNode* root, int *height)
    {
        if(root == nullptr)
        {
            *height = 0;
            return true;
        }
        
        // lh and rh are the height of left and right subtrees
        int lh=0,rh=0;
        
        //lb and rb are to check whether left subtree and right subtree are balanced or not .
        bool lb = false , rb = false;
        
        lb = helper(root->left, &lh);
        rb = helper(root->right, &rh);
        
        *height = max(lh,rh)+1;
        
        if((abs(lh-rh) <= 1) && lb && rb)
        {
            return true;
        }
        
        return false;
    }
    
    bool isBalanced(TreeNode* root) {
        
        int height=0;
        return helper(root, &height);
    }
};