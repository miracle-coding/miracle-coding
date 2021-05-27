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
    void in(TreeNode* node, vector<int>& v) {
        if (!node) return;
        if (node->left) in(node->left, v);
        if (node) v.emplace_back(node->val);
        if (node->right) in(node->right, v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> v;
        if (root->left) in(root->left, v);
        if (root) v.emplace_back(root->val);
        if (root->right) in(root->right, v);
        return v;
    }
};