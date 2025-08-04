class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        //if there is not root 
        if(!root) return NULL;

        //if the node is the leaf node than we have return the node val
        if(root->left == NULL && root->right == NULL) {
            return root->val;
        }
        //First we will go till complete left of Binary Tree and the complete right of BT
        //using recursion
        bool leftVal = evaluateTree(root->left);
        bool rightVal = evaluateTree(root->right);

        //now for the node which is not a leaf node 
        if(root->val == 3) {
            return leftVal & rightVal;
        }
        else if(root->val == 2) {
            return leftVal | rightVal;
        }

        return NULL;
    }
};
