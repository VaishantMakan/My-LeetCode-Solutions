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


// Approach 1 - Using ranges - https://www.youtube.com/watch?v=f-sj7I5oXEI&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=48
// TC -> O(N) , SC -> O(1)

class Solution {
public:
    bool helper(TreeNode* root, long minV, long maxV) {
        
        if(root == NULL)
            return true;
        
        if(root->val >= maxV || root->val <= minV)
            return false;
        
        return helper(root->left, minV, root->val) && helper(root->right, root->val, maxV) ;
    }
    
    bool isValidBST(TreeNode* root) {
        
        return helper(root, LONG_MIN, LONG_MAX);
    }
};


// Approach 2 - Using Inorder 
// TC -> O(N) , SC -> O(N)

// class Solution {
// public:
    
//     void inOrder(TreeNode* root, vector<int>&v)
//     {
//         if(root == nullptr)
//             return;
        
//         inOrder(root->left,v);
//         v.push_back(root->val);
//         inOrder(root->right,v);
//     }
    
//     bool isValidBST(TreeNode* root) {
        
//         if(root==nullptr)
//             return false;
        
//         vector<int>v;
        
//         inOrder(root,v);
        
//         int n=v.size();
//         for(int i=1;i<n;i++)
//         {
//             if(v[i] <= v[i-1])
//                 return false;
//         }
        
//         return true;
//     }
// };