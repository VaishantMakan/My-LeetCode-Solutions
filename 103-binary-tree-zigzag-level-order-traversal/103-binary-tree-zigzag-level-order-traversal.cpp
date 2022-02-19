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
        
        vector<vector<int>>ans;
        
        if(root == NULL)
            return ans;
        
        deque<TreeNode*>q;
        q.push_back(root);
        
        bool oddLevel = true;
        while(!q.empty())
        {
            int n = q.size();
            vector<int>level;
            deque<TreeNode*>tempQ;
            
            for(int i=0;i<n;i++)
            {
                TreeNode* node = q.front();
                q.pop_front();
                
                if(oddLevel)
                {
                    if(node->left != NULL)
                        tempQ.push_front(node->left);
                    
                    if(node->right != NULL)
                        tempQ.push_front(node->right);
                }
                else
                {
                    if(node->right != NULL)
                        tempQ.push_front(node->right);
                
                    if(node->left != NULL)
                        tempQ.push_front(node->left);
                }
                
                level.push_back(node->val);
            }
            
            q = tempQ;
            oddLevel = !oddLevel;
            ans.push_back(level);
        }
        return ans;
    }
};