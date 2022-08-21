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
    
    void dfs(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, vector<TreeNode*>>& m, unordered_map<TreeNode*, int>& infected)
    {
        if(root == NULL)
            return;
        
        // if(root-> val == start)
        //     begin = root;
        
        infected[root] = 0;
        
        m[root].push_back(parent);
        
        if(root->left != NULL)
        {
            m[root].push_back(root->left);
            dfs(root->left, root, m, infected);
        }
        else
            m[root].push_back(NULL);
        
        if(root->right != NULL)
        {
            m[root].push_back(root->right);
            dfs(root->right, root, m, infected);
        }
        else
            m[root].push_back(NULL);
    }
    
    int amountOfTime(TreeNode* root, int start) {
        
        unordered_map<TreeNode*, vector<TreeNode*>>m;
        TreeNode* parent = NULL;
        
        unordered_map<TreeNode*, int>infected;
        
        TreeNode* begin = NULL;
        
        queue<TreeNode*>q2;
        q2.push(root);
        
        while(!q2.empty())
        {
            TreeNode* top = q2.front();
            q2.pop();
            
            if(top->val == start)
            {
                begin = top;
                break;
            }
            
            if(top->left != NULL)
                q2.push(top->left);
            
            if(top->right != NULL)
                q2.push(top->right);
        }
        
        while(!q2.empty())
            q2.pop();
        
        dfs(root, parent, m, infected);
        
        // queue<TreeNode*>q;
        q2.push(begin);
        
        int ans = 0;
        infected[begin] = 1;
        
        if(root->left == NULL && root->right == NULL)
            return 0;
        
        while(!q2.empty())
        {
             int n = q2.size();
             bool flag=0;
            for(int i=0; i<n; i++)
            {
                TreeNode* top = q2.front();
                q2.pop();
                
                // cout<<top->val<<endl;
            
            if(m[top][0] != NULL && infected[m[top][0]] == 0)
            {
             
                q2.push(m[top][0]);
                infected[m[top][0]] = 1;
                flag=1;
            }
            
            if(m[top][1] != NULL && infected[m[top][1]] == 0)
            {
                q2.push(m[top][1]);
                infected[m[top][1]] = 1;
                flag=1;
            }
            
            if(m[top][2] != NULL && infected[m[top][2]] == 0)
            {
                q2.push(m[top][2]);
                infected[m[top][2]] = 1;
                flag=1;
            }
            }
            
            if(flag)
                ans++;
            
            
        }
        return ans;
    }
};