/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        vector<Node*> copy_heads;
        map<Node*, int> original_heads;
        Node** original_node;
        original_node = &head;
        Node* copy_head;
        Node** copy_node = &copy_head;
        
        if(head==NULL) return NULL;
        
        int index =0;
        while(*original_node){
            *copy_node = new Node((*original_node)->val);
            copy_heads.push_back((*copy_node));
            original_heads[(*original_node)] = index;
            original_node = &((*original_node)->next);
            copy_node = &((*copy_node)->next);
            index++;
        }
        
        copy_node = &copy_head;
        while(head){
            if(head->random){
                (*copy_node)->random = copy_heads[original_heads[head->random]];
            }
            head = head->next;
            copy_node = &((*copy_node)->next);
        }
        
        return copy_head;
    }
};