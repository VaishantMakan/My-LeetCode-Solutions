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
    
    TreeNode *first, *second, *prev;
    
    void inOrder(TreeNode* root)
    {
        if(root==nullptr)
            return;
        
        //left
        inOrder(root->left);
        
        if(prev != nullptr && prev->val > root->val)
        {
            if(first == nullptr)
                first = prev;
            second = root;
        }
        prev = root;
      
        
        //right
        inOrder(root->right);
        
        return;
    }
    
    void recoverTree(TreeNode* root) {
    
        inOrder(root);
        
        swap(first->val, second->val);
        return;
    }
};