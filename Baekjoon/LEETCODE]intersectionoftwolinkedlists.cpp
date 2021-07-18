/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<int> avector, bvector;
        ListNode** node = &headA;
        while((*node)!=NULL){
            avector.push_back((*node)->val);
            node= &(*node)->next;
        }
        node = &headB;
        while((*node)!=NULL){
            bvector.push_back((*node)->val);
            node= &(*node)->next;
        }
        int len = 0;
        int alen = avector.size();
        int blen = bvector.size();
        while(alen>len && blen>len){
            if(avector[alen-1-len]!=bvector[blen-1-len]){
                break;
            } else{
                len++;
            }
        }
        if(len == 0){
            return NULL;
        }
        else{
            alen = alen-len;
            for(int i = 0;i<alen;i++){
                headA = headA->next;
            }
            blen = blen-len;
            for(int i = 0;i<blen;i++){
                headB = headB->next;
            }
            cout<<alen<<" "<<blen<<"\n";
            for(int i = 0;i<len;i++){
                if(headA==headB){
                    return headA;
                } else{
                    headA = headA->next;
                    headB = headB->next;
                }
            }
            return NULL;
        }
    }
};