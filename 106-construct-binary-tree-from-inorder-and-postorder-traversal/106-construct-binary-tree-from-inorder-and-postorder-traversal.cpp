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
    
    TreeNode* helper(vector<int>& postorder, int postS, int postE, vector<int>& inorder, int inS, int inE, unordered_map<int,int>& m)
    {
        if(postS > postE || inS > inE)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[postE]);
        
        int inRoot = m[root->val];
        int numLeft = inRoot - inS;
        
        root->left = helper(postorder, postS, postS+numLeft-1, inorder, inS, inRoot-1, m);
        root->right = helper(postorder, postS+numLeft, postE-1, inorder, inRoot+1, inE, m);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map<int,int>m;
        
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]] = i;
        
        return helper(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, m);
    }
};