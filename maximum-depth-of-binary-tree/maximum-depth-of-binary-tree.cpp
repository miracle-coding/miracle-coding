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
    void dfs(TreeNode* node, int cnt, int& ans) {
        if (!node) {
            ans = max(ans, cnt);
            return;
        }
        dfs(node->left, cnt+1, ans);
        dfs(node->right, cnt+1, ans);
    }
    int maxDepth(TreeNode* root) {
        int answer = 0;
        dfs(root, 0, answer);
        return answer;
    }
};