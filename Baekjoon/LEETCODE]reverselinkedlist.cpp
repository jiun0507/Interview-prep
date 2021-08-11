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
    ListNode* reverseList(ListNode* head) {
        vector<ListNode*> heads;
        while(head){
            heads.push_back(head);
            head = head->next;
            
        }
        cout<<heads.size();
        ListNode* prehead = new ListNode();
        ListNode** node = &(prehead);
        for(int i = heads.size()-1;i>=0;i--){
            (*node)->next = heads[i];
            node = &((*node)->next);
            if(i==0){
                (*node)->next = NULL;
            }
        }
        return prehead->next;
    }
};