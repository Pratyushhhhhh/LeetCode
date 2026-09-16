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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>>que;
        que.push({root,0});
        ll maxWidth=0;
        while(!que.empty()){
            int n=que.size();
            ll L=que.front().second;
            ll R=que.back().second;
            maxWidth = max(maxWidth,R-L+1);
            while(n--){
                pair<TreeNode*, ll> node = que.front();
                que.pop();
                if(node.first->left)
                    que.push({node.first->left,node.second*2+1});
                if(node.first->right)
                    que.push({node.first->right,node.second*2+2});
            }
        }
        return maxWidth;
    }
};