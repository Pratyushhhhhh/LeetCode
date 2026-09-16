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
class Solution {//KADANNE+ TREE DIAMETER
public:
    // int maxi=INT_MIN;
    int maxSum=INT_MIN;
    int solve(TreeNode* root){
        if(root== NULL) return 0;

        int leftSum = root->val + max(0,solve(root->left));// as higher -ve values arent helping us we can just avoid them
        int rightSum = root->val + max(0,solve(root->right));// If the previous contribution is negative, throw it away and start fresh.

        int maxi = max(leftSum, rightSum);
        maxSum=max({maxi, leftSum+rightSum - root->val, maxSum});
        return maxi;//returning maxi as: if max sum path is at upper node we have to connect it to max of left and right paths of lower nodes

    }
    int maxPathSum(TreeNode* root) {
        maxSum=root->val;
        int ans = solve(root);
        return maxSum;
    }
};