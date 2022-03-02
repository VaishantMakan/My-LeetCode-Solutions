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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL)
            return root;
        
        TreeNode* head = root;
        
        TreeNode* prev = NULL;
        int temp; // 0->left, 1->right
        
        while(root != NULL)
        {
            if(key > root->val)
            {
                prev = root;
                root = root->right;
                temp=1;
            }
            else if(key < root->val)
            {
                prev = root;
                root = root->left;
                temp=0;
            }
            else
            {
                break;
            }
        }
        
        if(root == NULL)
            return head;
        
        TreeNode* delNode = root;
        TreeNode* delNodeParent = prev;
        
        // finding the node to replace this delNode
        
        if(root->right != NULL)
        {
            temp=1;
            prev = root;
            root=root->right;
            while(root->left != NULL)
            {
                temp=0;
                prev = root;
                root = root->left;
            }
        }
        else if(root->left != NULL)
        {
            temp=0;
            prev = root;
            root=root->left;
            while(root->right != NULL)
            {
                temp=1;
                prev = root;
                root = root->right;
            }
        }
        
        // deletion
        
        if(root->left == NULL && root->right == NULL) // leaf node
        {
            if(root == delNode && delNodeParent == NULL)
            {
                return NULL;
            }
            
            delNode->val = root->val;
            
            if(temp == 1)
                prev->right = NULL;
            else
                prev->left = NULL;
        }
        else  // middle or head node 
        {
            if(root->right != NULL)
            {
                delNode->val = root->val;
                
                if(temp == 1)
                    prev->right = root->right;
                else
                    prev->left = root->right;
            }
            else
            {
                delNode->val = root->val;
                
                if(temp == 1)
                    prev->right = root->left;
                else
                    prev->left = root->left;
            }
    
        }
        return head;
    }
};