// Approach : https://www.youtube.com/watch?v=i9ORlEy6EsI&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=31

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parents)
    {
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left)
            {
                q.push(node->left);
                parents[node->left] = node;
            }
            
            if(node->right)
            {
                q.push(node->right);
                parents[node->right] = node;
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*, TreeNode*> parents;
        markParents(root, parents);
        
        unordered_map<TreeNode*, bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        
        int curr=0;
        while(!q.empty())
        {
            if(curr++ == k)
                break;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left && !visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                
                if(node->right && !visited[node->right])
                {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                
                if(parents[node] && !visited[parents[node]])
                {
                    q.push(parents[node]);
                    visited[parents[node]] = true;
                }
            }
        }
        
        vector<int>ans;
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp->val);
        }
        return ans;
    }
};