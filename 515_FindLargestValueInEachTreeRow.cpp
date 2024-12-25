/*
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]

Example 2:
Input: root = [1,2,3]
Output: [1,3]
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

vector<int> largestValues(TreeNode* root) {
    if(!root) return {};
    queue<TreeNode*>q;
    vector<int>ans;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int>v;
        for(int i=0;i<size;i++){
            TreeNode* temp=q.front();
            v.push_back(temp->val);
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        ans.push_back(*max_element(v.begin(),v.end()));
    }
    return ans;
}

class Solution {
public:
    int findMax(queue<TreeNode*>&q){
        int maxi=INT_MIN;
        for(int i=0;i<q.size();i++){
            TreeNode* temp=q.front();
            if(maxi<temp->val){
                maxi=temp->val;
            }
            q.pop();
            q.push(temp);
        }
        return maxi;
    }
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        vector<int>ans;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            ans.push_back(findMax(q));
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            } 
        }
        return ans;
    }
};