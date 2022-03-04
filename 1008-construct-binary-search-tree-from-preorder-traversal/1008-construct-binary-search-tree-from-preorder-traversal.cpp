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
    
    int helper(TreeNode* root, long minV, long maxV, vector<int>& preorder, int &itr)
    {
        if(itr >= preorder.size())
            return itr;
        
        int val = preorder[itr];
        
        // check if val in range 
        if(val > minV && val < maxV)
        {
            int newItr = itr;
            TreeNode* newNode = new TreeNode(val);
            if(val < root->val)
            {
                root->left = newNode;
                int temp = itr+1;
                newItr = helper(root->left, minV, root->val, preorder, temp);
            }
            
            if(newItr >= preorder.size())
                return itr;
            
            itr = newItr;
            val = preorder[itr];
            newNode = new TreeNode(val);
            
            if(val > minV && val < maxV)
            {
                if(val > root->val)
                {
                    root->right = newNode;
                    int temp = itr+1;
                    itr = helper(root->right, root->val, maxV, preorder, temp);
                }
            }
        }
        
        return itr;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        if(preorder.size() == 0)
            return NULL;
        
        int val = preorder[0];
        TreeNode* root = new TreeNode(val);
        
        int itr=1;
        
        helper(root, LONG_MIN, LONG_MAX, preorder, itr);
        
        return root;
    }
};