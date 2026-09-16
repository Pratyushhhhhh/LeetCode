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
    void preorder(TreeNode*  root, vector<int>&res){ //NLR //Useful when Copying tree
            if(root==NULL)
                return;
            res.push_back(root->val);//N
            preorder(root->left, res);//L
            preorder(root->right, res);//R
        }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        preorder(root,res);
        return res;
    }
};