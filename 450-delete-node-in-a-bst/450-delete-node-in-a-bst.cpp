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

// RECURSIVE SOLUTION : 

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root) 
            return root;
        
        if(root->val == key)
        {
            if(root->right)
            {
                TreeNode* left = root->left;
                root = root->right;
                TreeNode* temp = root;
                
                while(temp->left) 
                    temp = temp->left;
                
                temp->left = left;
            } 
            else 
                root = root->left;
        }
        
        else if(key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            root->right = deleteNode(root->right, key);
        }
        
        return root;
    }
};
  
// ITERATIVE SOLUTION : 

// If you dont want to change values and instead change the whole node , the below code can be easily modified to do so .....
// in the deletion section , instead of changing the value of delNode , create a new node with the curr root's value and then first join this newnode with delNodeParent node using temp variable to see which direction to join , then to the left of this newNode add delNode's left pointer and to the right of newNode add right pointer of delNode . Then delete delNode pointer. ( the task done with prev pointer remains same , dont change that )

// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
           
        
//         if(root == NULL)
//             return root;
        
//         TreeNode* head = root;
        
//         TreeNode* prev = NULL;
//         int temp; // 0->left, 1->right
        
//         while(root != NULL)
//         {
//             if(key > root->val)
//             {
//                 prev = root;
//                 root = root->right;
//                 temp=1;
//             }
//             else if(key < root->val)
//             {
//                 prev = root;
//                 root = root->left;
//                 temp=0;
//             }
//             else
//             {
//                 break;
//             }
//         }
        
//         if(root == NULL)
//             return head;
        
//         TreeNode* delNode = root;
//         TreeNode* delNodeParent = prev;
        
//         // finding the node to replace this delNode
        
//         if(root->right != NULL)
//         {
//             temp=1;
//             prev = root;
//             root=root->right;
//             while(root->left != NULL)
//             {
//                 temp=0;
//                 prev = root;
//                 root = root->left;
//             }
//         }
//         else if(root->left != NULL)
//         {
//             temp=0;
//             prev = root;
//             root=root->left;
//             while(root->right != NULL)
//             {
//                 temp=1;
//                 prev = root;
//                 root = root->right;
//             }
//         }
        
//         // deletion
        
//         if(root->left == NULL && root->right == NULL) // leaf node
//         {
//             if(root == delNode && delNodeParent == NULL) // if the tree has a single node only and it is to be deleted ...
//             {
//                 return NULL;
//             }
            
//             delNode->val = root->val;
            
//             if(temp == 1)
//                 prev->right = NULL;
//             else
//                 prev->left = NULL;
//         }
//         else  // middle or head node 
//         {
//             if(root->right != NULL)
//             {
//                 delNode->val = root->val;
                
//                 if(temp == 1)
//                     prev->right = root->right;
//                 else
//                     prev->left = root->right;
//             }
//             else
//             {
//                 delNode->val = root->val;
                
//                 if(temp == 1)
//                     prev->right = root->left;
//                 else
//                     prev->left = root->left;
//             }
    
//         }
//         return head;
//     }
// };