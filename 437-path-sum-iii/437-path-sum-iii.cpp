// O( N ) solution 

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

#define ll long long 
class Solution {
public:
    
    unordered_map<ll, ll>m;
    int ans=0;
    
    void helper(TreeNode* root, int target, ll curr)
    {
        if(root == NULL)
            return;
        
        curr += root->val;
        
        if(curr == target)
            ans += 1;
        
        if(m.find(curr-target) != m.end())
            ans += m[curr-target];
        
        m[curr]++;
        
        helper(root->left, target, curr);
        helper(root->right, target, curr);
        
        m[curr]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root == NULL)
            return ans;
        
        ll curr = 0;
        helper(root, targetSum, curr);
        
        return ans;
    }
};