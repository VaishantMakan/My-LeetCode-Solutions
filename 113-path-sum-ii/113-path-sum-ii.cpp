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
    
    void helper(vector<vector<int>>& ans, vector<int>& temp, TreeNode* node, int sum, int target)
    {
     
        temp.push_back(node->val);
        sum += node->val;
        
        if(node->left != NULL && node->right != NULL)
        {
            helper(ans, temp, node->left, sum, target);

            helper(ans, temp, node->right, sum, target);           
        }
        else if(node->left == NULL && node->right == NULL) // leaf node
        {
            if(sum == target)
                ans.push_back(temp);
        }
        else if(node->left != NULL)
        {
            helper(ans, temp, node->left, sum, target);
        }
        else if(node->right != NULL)
        {
            helper(ans, temp, node->right, sum, target); 
        }
    
        //backtrack 
        temp.pop_back();
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>>ans;
        
        if(root == NULL)
            return ans;
        
        vector<int>temp;
        
        helper(ans, temp, root, 0, targetSum);
            
        return ans;
    }
};