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
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
private:
    int inorder(TreeNode* node, int& k){
        if(!node) return -1;

        int left = inorder(node->left, k);
        if(left != -1) return left;
        k--;

        if(k == 0) return node->val;
        return inorder(node->right, k); 
    }
};