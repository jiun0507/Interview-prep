class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *even = NULL;
        ListNode **node = &even;
        ListNode **oddnode = &head;
        while((*oddnode)!=NULL){
            if((*oddnode)->next){
                *node = new ListNode((*oddnode)->next->val);
                node = &((*node)->next);
                if((*oddnode)->next->next){
                    (*oddnode)->next = (*oddnode)->next->next;   
                    oddnode = &((*oddnode)->next);
                }
                else{
                    break;
                }
                
            }
            else{ 
                break;
            }
        }
        if(even!=NULL) (*oddnode)->next = even;
        return head;
    }
};