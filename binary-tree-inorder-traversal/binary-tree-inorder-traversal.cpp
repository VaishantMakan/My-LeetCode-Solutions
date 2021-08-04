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
    
    vector<int> helper(TreeNode* root, vector<int> &v)
    {
        if(root == nullptr)
            return v;
        
        //left
        if(root->left != nullptr)
        {
            helper(root->left,v);
        }
        
        //root
        v.push_back(root->val);
        
        //right
        if(root->right != nullptr)
        {
            helper(root->right,v);
        }
        
        return v;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> v;
        helper(root,v);
        return v;
    }
};