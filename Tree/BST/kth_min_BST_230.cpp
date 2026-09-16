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
    void solve(TreeNode* root, int&ct, int&ans, int k){
        if(root==NULL)//INORDER
            return;
        solve(root->left,ct,ans,k);
        ct++;
        if(ct==k){
            ans=root->val;
            return;
        }
        solve(root->right,ct,ans,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ct=0;
        int ans;
        solve(root,ct,ans,k); 
        return ans;
    }
};
