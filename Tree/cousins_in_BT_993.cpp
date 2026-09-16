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
    bool isCousins(TreeNode* root, int x, int y) {
        //Level Sum using BFS
         queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            int cnt = 0;

            while (n--) {
                TreeNode* node = q.front();
                q.pop();

                int c = 0;

                if (node->left) {
                    if (node->left->val == x || node->left->val == y)
                        c++, cnt++; //c=2 means that x and y are siblings not cousins
                    q.push(node->left);
                }

                if (node->right) {
                    if (node->right->val == x || node->right->val == y)
                        c++, cnt++;//cnt=2 means we found x,y as cousins on same level
                    q.push(node->right);
                }

                if (c == 2) return false; // siblings
            }

            if (cnt == 2) return true;   // same level, different parents
            if (cnt == 1) return false;  // different levels
        }

        return false;
    }
};