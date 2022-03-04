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

// Approach 1 : Using single upper bound range ... https://www.youtube.com/watch?v=UmJT3j26t1I&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=49
class Solution {
public:
    
    TreeNode* build(vector<int>& preorder, int& i, int bound) {
        
        if (i == preorder.size() || preorder[i] > bound) 
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[i++]);
        
        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }
};

// Approach 2 : Using Both upper bound and lower bound ranges .....
// class Solution {
// public:
    
//     int helper(TreeNode* root, long minV, long maxV, vector<int>& preorder, int &itr)
//     {
//         if(itr >= preorder.size())
//             return itr;
        
//         int val = preorder[itr];
        
//         // check if val in range 
//         if(val > minV && val < maxV)
//         {
//             int newItr = itr;
//             TreeNode* newNode = new TreeNode(val);
//             if(val < root->val)
//             {
//                 root->left = newNode;
//                 int temp = itr+1;
//                 newItr = helper(root->left, minV, root->val, preorder, temp);
//             }
            
//             if(newItr >= preorder.size())
//                 return itr;
            
//             itr = newItr;
//             val = preorder[itr];
//             newNode = new TreeNode(val);
            
//             if(val > minV && val < maxV)
//             {
//                 if(val > root->val)
//                 {
//                     root->right = newNode;
//                     int temp = itr+1;
//                     itr = helper(root->right, root->val, maxV, preorder, temp);
//                 }
//             }
//         }
        
//         return itr;
//     }
    
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
        
//         if(preorder.size() == 0)
//             return NULL;
        
//         int val = preorder[0];
//         TreeNode* root = new TreeNode(val);
        
//         int itr=1;
        
//         helper(root, LONG_MIN, LONG_MAX, preorder, itr);
        
//         return root;
//     }
// };