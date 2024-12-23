/*
You are given the root of a binary tree with unique values.

In one operation, you can choose any two nodes at the same level and swap their values.

Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.

The level of a node is the number of edges along the path between it and the root node.
*/


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
    void minsort(vector<TreeNode*>&v,int& cnt){
        int n=v.size();
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++){
            p.push_back({v[i]->val,i});
        }
        sort(p.begin(),p.end());
        int i=0;
        while(i<n){
            if(p[i].second==i){
                i++;
                continue;
            }
            else{
                cnt++;
                swap(p[i],p[p[i].second]);
            }
        }
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            int n=q.size();
            vector<TreeNode*>v;
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left){ 
                    v.push_back(temp->left);
                    q.push(temp->left);
                }
                if(temp->right){
                    v.push_back(temp->right);
                    q.push(temp->right);
                }
            }
            minsort(v,cnt);
        }
        return cnt;
    }
};