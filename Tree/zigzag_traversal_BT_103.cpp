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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) { //ZigZag
        if(root==NULL)
            return {}; 

        vector<vector<int>>res;

        queue<TreeNode*>NQ;
        NQ.push(root);

        bool LtoR=true; // Flag 

        while(!NQ.empty()){
            int size = NQ.size();
            vector<int>temp(size);

            for(int i=0;i<size;i++){
                TreeNode* node = NQ.front();
                NQ.pop();

                int idx = (LtoR)?i:(size-1-i);

                temp[idx]=node->val;
                if(node->left)
                    NQ.push(node->left);
                if(node->right)
                    NQ.push(node->right);
            }
            LtoR = !LtoR;
            res.push_back(temp);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) { // NORMAL TRAVERSAL
        if(root == NULL)
            return {};

        vector<vector<int>> res;

        queue<TreeNode*> Q;
        Q.push(root);

        while(!Q.empty()) {

            int size = Q.size();
            vector<int> temp;

            for(int i = 0; i < size; i++) {

                TreeNode* node = Q.front();
                Q.pop();

                temp.push_back(node->val);

                if(node->left)
                    Q.push(node->left);

                if(node->right)
                    Q.push(node->right);
            }

            res.push_back(temp);
        }

        return res;
    }
};

