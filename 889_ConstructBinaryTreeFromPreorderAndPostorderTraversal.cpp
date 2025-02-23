/*
    Given two integer arrays, preorder and postorder where preorder is the preorder traversal 
    of a binary tree of distinct values and postorder is the postorder traversal of the same 
    tree, reconstruct and return the binary tree.

    If there exist multiple answers, you can return any of them.
*/

class Solution {
    public:
        unordered_map<int,int>mp;
        TreeNode* recur(int i1,int i2,int j1,int j2,vector<int>& preorder, vector<int>& postorder){
            if(j1>j2 || i1>i2){
                return NULL;
            }
            TreeNode* node = new TreeNode(preorder[i1]);
            if(i1==i2) return node;
            int r = mp[preorder[i1+1]];
            int size = r-j1+1;
            node->left = recur(i1+1,i1+size,j1,r,preorder,postorder);
            node->right = recur(i1+size+1,i2,r+1,j2-1,preorder,postorder);
            return node;
        }
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            int n=preorder.size();
            for(int i=0;i<n;i++){
                mp[postorder[i]] = i;
            }
            return recur(0,n-1,0,n-1,preorder,postorder);
        }
    };