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
    
    vector<TreeNode*> helper(int start, int end)
    {
        vector<TreeNode*> res;
        
        if(start > end)
        {
            res.push_back(nullptr);
                return res;
        }
        
        if(start == end)
        {
            res.push_back(new TreeNode(start));
            return res;
        }
        
        vector<TreeNode*> left,right;
        
        for(int i=start;i<=end;i++)
        {
            left = helper(start,i-1);
            right = helper(i+1, end);
            
            for(auto l:left)
            {
                for(auto r:right)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        
        return helper(1,n);
    }
};