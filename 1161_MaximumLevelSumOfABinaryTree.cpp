/*
    Given the root of a binary tree, the level of its root is 1, the level of its children is 2, 
    and so on.
    Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

    Example 1:

    Input: root = [1,7,0,7,-8,null,null]
    Output: 2
    Explanation: 
    Level 1 sum = 1.
    Level 2 sum = 7 + 0 = 7.
    Level 3 sum = 7 + -8 = -1.
    So we return the level with the maximum sum which is level 2.
*/

int maxLevelSum(TreeNode* root) {
    queue<TreeNode*>q;
    q.push(root);
    int ans=-1,maxsum=INT_MIN,cnt=1;
    while(!q.empty()){
        int n=q.size();
        int temp=0;
        for(int i=0;i<n;i++){
            TreeNode* node = q.front();
            q.pop();
            temp+=node->val;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        if(maxsum<temp){
            ans=cnt;
            maxsum=temp;
        }
        cnt++;
    }
    return ans;
}