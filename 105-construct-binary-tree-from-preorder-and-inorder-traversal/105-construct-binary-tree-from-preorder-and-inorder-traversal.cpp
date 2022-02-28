// Approach : https://www.youtube.com/watch?v=aZNaLrVebKQ&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=36

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
    
    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int,int>&m)
    {
        if(preStart > preEnd || inStart > inEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int inRoot = m[root->val];
        int inLeftElements = inRoot - inStart;
        
        root->left = helper(preorder, preStart+1, preStart+inLeftElements, inorder, inStart, inRoot-1, m);
        root->right = helper(preorder, preStart+inLeftElements+1, preEnd, inorder, inRoot+1, inEnd, m);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int,int>m;
        
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]] = i;
        
        return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, m);
    }
};