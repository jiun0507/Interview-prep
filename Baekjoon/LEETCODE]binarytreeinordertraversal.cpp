class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode**> st;
        TreeNode **node = &root;
        vector<int> ret;
        if(root==NULL){
            return ret;
        }
        while(true){
            if(node == NULL){
                if(st.empty()) break;
                else{
                    node = st.top();
                    st.pop();
                    ret.push_back((*node)->val);
                    if((*node)->right){
                        node = &((*node)->right);
                    } else{
                        node = NULL;
                    }
                }
            }
            else if((*node)->left){
                st.push(node);
                node = &((*node)->left);
            } else{
                ret.push_back((*node)->val);
                if((*node)->right){
                    node = &((*node)->right);
                } else{
                    node = NULL;
                }
            }
        }
        return ret;
    }
};