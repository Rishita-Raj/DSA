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
    void inorder(TreeNode* root, vector<int>& values) {
        if (!root) return;
        inorder(root->left, values);
        values.push_back(root->val);
        inorder(root->right, values);
    }

    TreeNode* buildBST(vector<int>& values, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(values[mid]);

        root->left = buildBST(values, left, mid - 1);
        root->right = buildBST(values, mid + 1, right);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> values;
        inorder(root, values);

        return buildBST(values, 0, values.size() - 1);
    }
};

