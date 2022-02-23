// Approach 1 : https://www.youtube.com/watch?v=fmflMqVOC7k&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=27  ( TC -> O(N) & SC -> O(N+N))
// Approach 2 : https://www.youtube.com/watch?v=_-QHfMDde90&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=28  ( TC -> O(N) & SC -> O(N))


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// Approach 1 : 

class Solution {
public:
    
    bool helper(TreeNode* node, TreeNode* p, vector<TreeNode*>& path)
    {
        if(node == NULL)
            return false;
        
        path.push_back(node);
        
        if(node == p)
            return true;
        
        if(helper(node->left, p, path) || helper(node->right, p, path))
            return true;
        
        path.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*>a;
        vector<TreeNode*>b;
        
        helper(root, p, a);  // to get path from root to node p in vector a 
        helper(root, q, b);  // to get path from root to node q in vector b
        
        int n = a.size();
        int m = b.size();
        
        int i=0;
        TreeNode* ans;
        while(i<n && i<m)
        {
            if(a[i]==b[i])
                ans = a[i];
            
            i++;
        }
        return ans;
    }
};

// Approach 2 : 

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         //base case
//         if (root == NULL || root == p || root == q) {
//             return root;
//         }
//         TreeNode* left = lowestCommonAncestor(root->left, p, q);
//         TreeNode* right = lowestCommonAncestor(root->right, p, q);

//         //result
//         if(left == NULL) {
//             return right;
//         }
//         else if(right == NULL) {
//             return left;
//         }
//         else { //both left and right are not null, we found our result
//             return root;
//         }
//     }
// };