/*
    We run a preorder depth-first search (DFS) on the root of a binary tree.

    At each node in this traversal, we output D dashes (where D is the depth of this node), 
    then we output the value of this node.  If the depth of a node is D, the depth of its 
    immediate child is D + 1.  The depth of the root node is 0.

    If a node has only one child, that child is guaranteed to be the left child.

    Given the output traversal of this traversal, recover the tree and return its root.
*/

class Solution {
    public:
        int index = 0;
        int n;
        TreeNode* dfs(string &traversal,int depth){
            if(index>=n) return NULL;
            int count = 0;
            int tempIdx = index;
            while(tempIdx<n && !isdigit(traversal[tempIdx])){
                tempIdx++;
                count++;
            }
            if(count!=depth) return NULL;
            index = tempIdx;
            int val=0;
    
            while(index<n && isdigit(traversal[index])){
                val = val*10 + (traversal[index] - '0');
                index++;
            }
            TreeNode* newNode = new TreeNode(val);
            newNode->left = dfs(traversal,depth+1);
            newNode->right = dfs(traversal,depth+1);
            return newNode;
        }
        TreeNode* recoverFromPreorder(string traversal) {
               n=traversal.size();
               return dfs(traversal,0);
        }
    };