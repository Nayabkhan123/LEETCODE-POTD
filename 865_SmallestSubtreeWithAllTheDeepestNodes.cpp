/*
    Given the root of a binary tree, the depth of each node is the shortest distance to the root.
    Return the smallest subtree such that it contains all the deepest nodes in the original tree.
    A node is called the deepest if it has the largest depth possible among any node in the entire tree.
    The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.

    Example 1:
    Input: root = [3,5,1,6,2,0,8,null,null,7,4]
    Output: [2,7,4]
    Explanation: We return the node with value 2, colored in yellow in the diagram.
    The nodes coloured in blue are the deepest nodes of the tree.
    Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest 
    subtree among them, so we return it.
*/

// My Approach
int func(TreeNode* node, TreeNode* &ans, int& len, int currlen){
    if(!node) return 0;
    if(currlen>len){
        len=currlen;
        ans=node;
    }
    int left = func(node->left,ans,len,currlen+1);
    int right = func(node->right,ans,len,currlen+1);
    if(left==right && left==len-currlen){
        ans=node;
    }
    return max(left,right) + 1;
}
TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    int len=0;
    TreeNode *ans=root;
    func(root,ans,len,0);
    return ans;
}

// Chatgpt Approach
pair<int , TreeNode*> dfs(TreeNode* root){
    if(!root){
        return {0 , NULL};
    }
    auto left = dfs(root -> left);
    auto right = dfs(root -> right);

    if(left.first == right.first){
        return {left.first + 1  , root};
    }
    else if(left.first > right.first){
        return {left.first + 1 , left.second};
    }
    else{
        return {right.first + 1 , right.second};
    }
}
TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    return dfs(root).second;
}