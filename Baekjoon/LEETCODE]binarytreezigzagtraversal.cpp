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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> bfs;
        if(root) bfs.push(make_pair(root, 0));
        while(!bfs.empty()){
            auto cur = bfs.front();
            bfs.pop();
            TreeNode* cur_node = cur.first;
            int level = cur.second;
            if(ans.size()<=level){
                ans.push_back(vector<int>(1, cur_node->val));
            } else{
                ans[level].push_back(cur_node->val);
            }
            if(cur_node->left){
                bfs.push(make_pair(cur_node->left, level+1));
            } 
            if(cur_node->right){
                bfs.push(make_pair(cur_node->right, level+1));
            }
        }
        for(int i = 0;i<ans.size();i++){
            if(i%2==1){
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        return ans;
    }
};