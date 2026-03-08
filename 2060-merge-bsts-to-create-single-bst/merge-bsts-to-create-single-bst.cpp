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
    
    bool dfs(TreeNode* node, long minVal, long maxVal,
             unordered_map<int, TreeNode*>& roots) {
        
        if (!node) return true;
        
        if (node->val <= minVal || node->val >= maxVal)
            return false;
        
        // If leaf and matches another root -> merge
        if (!node->left && !node->right && roots.count(node->val)) {
            
            TreeNode* mergeTree = roots[node->val];
            roots.erase(node->val);
            
            node->left = mergeTree->left;
            node->right = mergeTree->right;
        }
        
        return dfs(node->left, minVal, node->val, roots) &&
               dfs(node->right, node->val, maxVal, roots);
    }
    
    
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        
        unordered_map<int, TreeNode*> roots;
        unordered_map<int, int> leafCount;
        
        // store roots
        for (auto t : trees) {
            roots[t->val] = t;
            
            if (t->left)
                leafCount[t->left->val]++;
            if (t->right)
                leafCount[t->right->val]++;
        }
        
        TreeNode* root = nullptr;
        
        // find global root
        for (auto t : trees) {
            if (!leafCount.count(t->val)) {
                root = t;
                break;
            }
        }
        
        if (!root) return nullptr;
        
        roots.erase(root->val);
        
        if (!dfs(root, LONG_MIN, LONG_MAX, roots))
            return nullptr;
        
        // all trees must be used
        if (!roots.empty())
            return nullptr;
        
        return root;
    }
};