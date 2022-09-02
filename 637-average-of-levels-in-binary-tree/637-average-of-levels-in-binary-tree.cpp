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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<vector<int>>bfs;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            vector<int>level;
            
            for(int i=0;i<n;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                level.push_back(node->val);
                
                if(node->left != NULL)
                    q.push(node->left);
                
                if(node->right != NULL)
                    q.push(node->right);
            }
            
            bfs.push_back(level);
        }
        
        vector<double>ans;
        
        for(int i=0;i<bfs.size();i++)
        {
            int m = bfs[i].size();
            double sum=0;
            for(int j=0;j<m;j++)
            {
                sum += bfs[i][j];
            }
            
            double avg = sum/m;
            ans.push_back(avg);
        }
        
        // for(int i=0;i<ans.size(); i++)
        //     cout<<ans[i]<<" ";
        
        return ans;
    }
};





