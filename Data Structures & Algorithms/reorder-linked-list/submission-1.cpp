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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        //this will split the LL into two halves
        //when fast reaches the end, slow will be at the midpoint
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //get the second half
        ListNode* second = slow->next;
        ListNode* prev = slow->next = nullptr; //disconnect the two halves
        //then reverse LL
        while (second != nullptr){
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }
        //combine both lists by interweaving
        ListNode* first = head;
        second = prev;
        while (second!=nullptr){
            ListNode* tmp1=first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first=tmp1;
            second=tmp2;
        }

    }
};
