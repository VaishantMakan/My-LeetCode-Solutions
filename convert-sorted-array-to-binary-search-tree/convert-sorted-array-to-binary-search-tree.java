/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    TreeNode helper(int nums[], int l, int h)
    {
        if(l>h)
            return null;
        
        int mid = l+(h-l)/2;
        TreeNode current = new TreeNode(nums[mid]);
        current.left = helper(nums,l,mid-1);
        current.right = helper(nums,mid+1,h);
        return current;
        
    }
    
    public TreeNode sortedArrayToBST(int[] nums) {
        
        int n = nums.length;
        if(nums == null || n == 0)
            return null;
        
        return helper(nums,0,n-1);
    }
}