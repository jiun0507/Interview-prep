/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<pair<int, TreeNode*>> ancestors;
    pair<bool, bool> commonAncestor(TreeNode* cur, int p, int q, int depth){
        pair<bool, bool> ans = make_pair(false, false);
        if(cur->val == p) ans.first = true;
        if(cur->val == q) ans.second = true;
        if(cur->left){
            auto left = commonAncestor(cur->left, p, q, depth+1);
            if(left.first) ans.first = true;
            if(left.second) ans.second = true;
        }
        if(cur->right){
            auto right = commonAncestor(cur->right, p, q, depth+1);
            if(right.first) ans.first = true;
            if(right.second) ans.second = true;
        }
        if(ans.first && ans.second){
            ancestors.push_back(make_pair(depth, cur));
        }
        return ans;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto ret = commonAncestor(root, p->val, q->val, 0);
        if(ret.first && ret.second){
            return ancestors[0].second;
        }
        return new TreeNode();
    
    }
};