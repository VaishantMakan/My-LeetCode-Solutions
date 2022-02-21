// Approach : https://www.youtube.com/watch?v=q_a6lpbKJdw&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=23  (striver graph series)

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, map<int, multiset<int>>> m;
        queue<pair<TreeNode*, pair<int,int>>> q;
                
        q.push({root, {0,0}});

        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            TreeNode* node = temp.first;
            int x = temp.second.first;    //vertical 
            int y = temp.second.second;   //level
            
            m[x][y].insert(node->val);
            
            if(node->left != NULL)
                q.push({node->left, {x-1, y+1}});
            
            if(node->right != NULL)
                q.push({node->right, {x+1, y+1}});
        }
        
        vector<vector<int>>ans;
        
        for(auto i:m)
        {
            vector<int>col;
            for(auto j:i.second)
            {
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};