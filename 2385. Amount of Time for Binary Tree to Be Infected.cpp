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
    #define f first
    #define s second
    void f(TreeNode* root,vector<vector<int>> &v){
        if(root){
            if(root->left){
                v[root->val].push_back(root->left->val);
                v[root->left->val].push_back(root->val);
            }
            if(root->right){
                v[root->val].push_back(root->right->val);
                v[root->right->val].push_back(root->val);
            }
            f(root->left,v);
            f(root->right,v);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> v(1e5+1);
        vector<int> vis(1e5+1,0);
        f(root,v);
        queue<pair<int,int>> q;
        q.push({start,0});
        int mx=0;
        while(!q.empty()){
            int node=q.front().f;
            int d=q.front().s;
            mx=max(mx,d);
            vis[node]=1;
            q.pop();
            for(auto x:v[node]){
                if(!vis[x]){
                    q.push({x,d+1});
                }
            }
        }
        return mx;
    }
};