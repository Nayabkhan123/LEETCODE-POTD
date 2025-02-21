/*
    Given a binary tree with the following rules:

    root.val == 0
    For any treeNode:
    If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
    If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
    Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

    Implement the FindElements class:

    FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
    bool find(int target) Returns true if the target value exists in the recovered binary tree.
*/

class FindElements {
    set<int>s;
public:
    void makeTree(TreeNode* root,int data){
        if(!root) return;
        root->val = data;
        s.insert(data);    
        makeTree(root->left,2*(root->val)+1);
        makeTree(root->right,2*(root->val)+2);
    }
    FindElements(TreeNode* root) {
        makeTree(root,0);
    }
    bool find(int target) {
        return s.contains(target);
    }
};


class FindElements {
    TreeNode* rootNode;
public:
    void makeTree(TreeNode* root,int data){
        if(!root) return;
        root->val = data;
        if(root->left){
            makeTree(root->left,2*(root->val)+1);
        }
        if(root->right){
            makeTree(root->right,2*(root->val)+2);
        }
    }
    FindElements(TreeNode* root) {
        rootNode = root;
        makeTree(root,0);
    }
    bool inorder(TreeNode* root,int target){
        if(!root) return false;
        if(root->val==target){
            return true;
        }
        return inorder(root->left,target) || inorder(root->right,target);
    }
    bool find(int target) {
        return inorder(rootNode,target);
    }
};