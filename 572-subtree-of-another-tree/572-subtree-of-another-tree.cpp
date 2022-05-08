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
    
    // brute force solution , tc -> O(n^2)
    
    // helper function 
    bool checkSubtree(TreeNode* root1, TreeNode* root2)
    {
         if(root1 == NULL && root2 == NULL)
            return true;
        
        if(root1 == NULL || root2 == NULL)
            return false;
        
        if(root1->val == root2->val)
        {
            return checkSubtree(root1->left, root2->left) && checkSubtree(root1->right, root2->right);
        }
        
        return false;
    }
    
    // main function 
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
       if(subRoot == NULL)  // then it will always exist in root tree even if root tree is null
            return true;
        
        if(root == NULL)   // if root tree is null and sub root tree is not null then it will always be false 
            return false; 
        
        // check for current nodes 
        if(checkSubtree(root, subRoot))
            return true;
        
        //else check for other nodes in root 
        return (isSubtree(root->left, subRoot)) || (isSubtree(root->right, subRoot));
    }
};