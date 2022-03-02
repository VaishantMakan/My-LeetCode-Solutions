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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode* head = root;
        TreeNode* prev;
        int temp; // 0-> left , 1-> right
        
        if(root == NULL)
        {
            TreeNode* newRoot = new TreeNode(val);
            return newRoot;
        }
        
        while(root != NULL)
        {
            if(val > root->val)
            {
                prev = root;
                temp=1;
                root = root->right;
            }
            else
            {
                prev = root;
                temp=0;
                root = root->left;
            }
        }
        
        TreeNode* child = new TreeNode(val);
        
        if(temp==1)
        {
            prev->right = child;    
        }
        else
        {
            prev->left = child;
        }
        
        return head;
    }
};