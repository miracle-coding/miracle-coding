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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.emplace(root);
        while(!q.empty()) {
            ++res;
            for (int i=0, n=q.size() ; i<n ; ++i) {
                TreeNode* node = q.front(); q.pop();
                if (node->left)
                    q.emplace(node->left);
                if (node->right)
                    q.emplace(node->right);
            }
        }
        return res;
    }
    /*
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
    */
};