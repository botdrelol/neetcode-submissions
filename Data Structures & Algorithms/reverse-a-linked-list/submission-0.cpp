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
//stack approach, stack the values, then rewrite the values
//0(n) time but O(n) space
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        
        stack<int> reverseOrder;
        ListNode* temp = head;
        while (temp != nullptr)
        {
            reverseOrder.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp != nullptr)
        {
            temp->val = reverseOrder.top();
            reverseOrder.pop();
            temp = temp->next;
        }
        return head;
    }
};
