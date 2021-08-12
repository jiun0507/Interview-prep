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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* prehead;
        ListNode** node = &prehead;
        int prev = -1000001;
        while(true){
            int current_min = 10000001;
            int index = -1;
            for(int i = 0;i<k;i++){
                if(lists[i]){
                    if(current_min > lists[i]->val && prev < lists[i]->val){
                        current_min = lists[i]->val;
                        index = i;
                    }
                }
            }
            if(index == -1) break;
            *node = new ListNode(current_min);
            node = &((*node)->next);
            lists[index] = lists[index]->next;
        }
        return prehead;
    }
};