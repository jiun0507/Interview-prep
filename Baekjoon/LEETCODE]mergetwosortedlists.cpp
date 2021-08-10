/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* prehead = new ListNode();
        ListNode** ans_node = &prehead;
        while(l1 || l2){
            if(l1 && l2){
                bool move;
                if(l1->val <= l2->val){
                    (*ans_node)->next = l1;
                    move = false;
                } 
                else if(l1->val > l2->val){
                    (*ans_node)->next = l2;
                    move = true;
                }               
                if(move){
                    l2 = l2->next;
                } else{
                    l1 = l1->next;
                }
            }
            else if(l1){
                (*ans_node)->next = l1;
                l1 = l1->next;   
            }
            else if(l2){
                (*ans_node)->next = l2;
                l2 = l2->next;  
            }
            ans_node = &((*ans_node)->next);
        }
        return prehead->next;
    }
};