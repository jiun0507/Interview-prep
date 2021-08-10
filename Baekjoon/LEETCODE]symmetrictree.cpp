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
    bool isSymmetric(TreeNode* root) {
        map<vector<bool>, int> original;
        vector<bool> track;
        track.push_back(false);
        queue<pair<vector<bool>, TreeNode*>> q;
        if(root->left) q.push(make_pair(track, root->left));
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            vector<bool> cur_track = cur.first;
            auto cur_node = cur.second;
            original[cur_track] = cur_node->val;
            if(cur_node->left){
                cur_track.push_back(false);
                q.push(make_pair(cur_track, cur_node->left));
                cur_track.pop_back();
            }
            if(cur_node->right){
                cur_track.push_back(true);
                q.push(make_pair(cur_track, cur_node->right));
                cur_track.pop_back();
            }
        }
        if(root->right) q.push(make_pair(track, root->right));
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            vector<bool> cur_track = cur.first;
            auto cur_node = cur.second;
            if(original.count(cur_track)==0){
                return false;
            }
            if(original[cur_track]!=cur_node->val){
                return false;
            }
            original.erase(cur_track);
            if(cur_node->left){
                cur_track.push_back(true);
                q.push(make_pair(cur_track, cur_node->left));
                cur_track.pop_back();
            }
            if(cur_node->right){
                cur_track.push_back(false);
                q.push(make_pair(cur_track, cur_node->right));
                cur_track.pop_back();
            } 
            
        }
        if(!original.empty()) return false;
        return true;
    }
};