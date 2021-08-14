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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        int check=0;
        //if check even -> right to left 
        //if check odd -> left to right
        
        vector<vector<int>> ans;
        
         if(root == nullptr)
            return ans;
        
        deque<TreeNode*> q;
        q.push_front(root);
        
        int n = q.size();
        
        while(!q.empty())
        {
            n = q.size();
            vector<int> v;
            
            for(int i=0;i<n;i++)
            {
                if(check == 0)
                {
                    TreeNode* temp = q.front();
                    q.pop_front();
                
                    v.push_back(temp->val);
                    
                    if(temp->right != nullptr)
                        q.push_back(temp->right);
                    
                    if(temp->left != nullptr)
                        q.push_back(temp->left);
                    
                    break;
                }
                
                if(check & 1)
                {
                    //odd
                    
                    TreeNode* temp = q.front();
                    q.pop_front();
                
                    v.push_back(temp->val);
                    
                    if(temp->right != nullptr)
                        q.push_back(temp->right);
                    
                    if(temp->left != nullptr)
                        q.push_back(temp->left);
                }
                else
                {
                    //even 
                    
                    TreeNode* temp = q.back();
                    q.pop_back();
                
                    v.push_back(temp->val);
                    
                    if(temp->left != nullptr)
                        q.push_front(temp->left);
                    
                    if(temp->right != nullptr)
                        q.push_front(temp->right);
                }
            }
            
            ans.push_back(v);
            check++;
        }
        return ans;
    }
};