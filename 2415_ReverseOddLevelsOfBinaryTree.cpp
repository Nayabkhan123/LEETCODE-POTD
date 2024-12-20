/*
Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.

For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
Return the root of the reversed tree.

A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.

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
    void reverse(vector<TreeNode*>levelNodes){
        int n=levelNodes.size();
        for(int i=0;i<n/2;i++){
            int temp=levelNodes[i]->val;
            levelNodes[i]->val=levelNodes[n-i-1]->val;
            levelNodes[n-i-1]->val=temp;
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int size = q.size();
            vector<TreeNode*>levelNodes;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                levelNodes.push_back(node);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(level%2==1) reverse(levelNodes);
            level++;
        }
        return root;
    }
};