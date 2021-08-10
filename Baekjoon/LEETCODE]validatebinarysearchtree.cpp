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
    bool isValidBST(TreeNode* root) {
        queue<tuple<long long, long long, TreeNode*>> nodes;
        nodes.push(make_tuple((long long)-3000000000, (long long)3000000000, root));
        while(!nodes.empty()){
            auto cur = nodes.front();
            nodes.pop();
            long long mini = get<0>(cur);
            long long maxi = get<1>(cur);
            TreeNode* cur_node = get<2>(cur);
            long long val = cur_node->val;
            if(mini>=cur_node->val || maxi<=cur_node->val){
                return false;
            }
            if(cur_node->left){
                nodes.push(make_tuple(mini, min(maxi, (long long)val), cur_node->left));
            } 
            if(cur_node->right){
                nodes.push(make_tuple(max(mini, (long long)val), maxi, cur_node->right));
            }
        }
        return true;
        
    }
};