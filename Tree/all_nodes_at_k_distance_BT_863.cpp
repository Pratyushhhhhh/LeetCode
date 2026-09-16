/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mp;

    void inOrder(TreeNode* root){
        if(!root)
            return;
        
        if(root->left!=NULL){
            mp[root->left]=root;
        }
        inOrder(root->left);

        if(root->right!=NULL){
            mp[root->right]=root;
        }
        inOrder(root->right);
    }

    void BFS(TreeNode* target, int k, vector<int>& result){
        queue<TreeNode*>Q;
        Q.push(target);

        unordered_set<int> vis;
        vis.insert(target->val);

        while(!Q.empty()){
            int n= Q.size();

            if(k==0)
                break;
            
            while(n--){
                TreeNode* node=Q.front();
                Q.pop();

                if(node->left!=NULL && !vis.count(node->left->val)){
                    Q.push(node->left);
                    vis.insert(node->left->val);
                }

                //right
                if(node->right!=NULL && !vis.count(node->right->val)){
                    Q.push(node->right);
                    vis.insert(node->right->val);
                }

                //parent
                if(mp.count(node) && !vis.count(mp[node]->val)){
                    Q.push(mp[node]);
                    vis.insert(mp[node]->val);
                }
            }
            k--;
        }
        while(!Q.empty()){
            TreeNode* node=Q.front();
            Q.pop();
            result.push_back(node->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL)
            return {};
        inOrder(root);
        vector<int>result;
        BFS(target,k,result);
        return result;
    }
};