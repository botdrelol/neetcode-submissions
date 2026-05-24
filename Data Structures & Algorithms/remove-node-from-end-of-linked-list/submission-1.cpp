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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int size =0;
        //iterate through the LL and count the size
        while (curr!= nullptr){
            size ++;
            curr = curr->next;
        }
        curr = head;
        int removeIndex = size -n;
        // remove head if target is 0
        if (removeIndex ==0){
            return head ->next;
        }
        //iterate through the LL again, get to the node before
        for (int i =0; i < size-1; i++){
            //if next node is target, cut out middle
            if ((i+1)==removeIndex){
                curr->next = curr->next->next;
                break;
            }
            curr = curr->next;
        }
        return head;
    }
    
};
