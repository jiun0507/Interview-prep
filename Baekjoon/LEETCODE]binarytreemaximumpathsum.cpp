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
    int dfs(TreeNode* node, int &total){
        int cur = node->val;
        int ans = cur;
        int left = -1000000000;
        int right = -1000000000;
        if(node->left){
            left = dfs(node->left, total);
            if(total<left) total = max(total, left);
            ans = max(cur, cur+left);
        }
        if(node->right){
            right = dfs(node->right, total);
            if(total < right) total = max(total, right);
            ans = max(ans, cur+right);
        }
        if(cur + left + right > total) total = cur+left+right;
        
        return ans;
    }
    int maxPathSum(TreeNode* root) {
        int total = -2000000000;
        int ans = dfs(root, total);
        return max(ans, total);
    }
};