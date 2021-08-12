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
    pair<int,int> diameter(TreeNode* cur){
        pair<int,int> ans = make_pair(0, 0);
        pair<int,int> left = make_pair(0, 0);
        pair<int,int> right = make_pair(0, 0);
        if(cur->left){
            left = diameter(cur->left);
            left.first = left.first + 1;
        }
        if(cur->right){
            right = diameter(cur->right);
            right.first = right.first + 1;
        }
        int dia = left.first + right.first;
        ans.first = max(left.first, right.first);
        ans.second = max(dia, max(left.second, right.second));
        
        cout<<cur->val<<" : "<<left.first<<" "<<right.first<<" "<<ans.first<<" "<<ans.second<<"\n";
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> ret = diameter(root);
        if(ret.first < ret.second) return ret.second;
        return ret.first;
    }
};