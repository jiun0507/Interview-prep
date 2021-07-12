class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode**> dq;
        vector<vector<int>> ret;
        if(root==NULL){
            return ret;
        }
        TreeNode **rootnode = &root;
        dq.push_back(rootnode);
        bool zigzag = true;
        while(!dq.empty()){
            vector<int> temp;
            deque<TreeNode**> temp_node;
            while(!dq.empty()){
                TreeNode **node = dq.back();
                temp.push_back((*node)->val);
                dq.pop_back();                
                if(zigzag){
                    if((*node)->left){
                        temp_node.push_back(&((*node)->left));
                    }
                    if((*node)->right){
                        temp_node.push_back(&((*node)->right));
                    }
                } else{
                    if((*node)->right){
                        temp_node.push_back(&((*node)->right));
                    }
                    if((*node)->left){
                        temp_node.push_back(&((*node)->left));
                    }
                }
            }
            ret.push_back(temp);
            dq = temp_node;
            zigzag = !zigzag;
        }
        return ret;
    }
};