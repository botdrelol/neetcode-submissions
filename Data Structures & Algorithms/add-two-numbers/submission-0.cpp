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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
          int carry=0;
          //simply to start the LL, build from it
          ListNode* dummy = new ListNode();
          ListNode* curr =dummy;
          //iterate through the LLs
          while (l1 != nullptr || l2 != nullptr || carry!=0){
            //if node isn't null, get val, otherwise 0
            int num1 = (l1!=nullptr) ? l1->val : 0;
            int num2 = (l2!=nullptr) ? l2->val : 0;
            int sum = num1+num2+carry;
            //get the tens digits to carry
            carry = sum/10;
            //get the ones digits to keep
            sum = sum%10;
            //create next node, and then move to it
            curr->next =new ListNode(sum);
            curr=curr->next;
            //if node isn't nullptr, go to next , otherwise null
            l1=(l1!=nullptr) ? l1->next : nullptr;
            l2=(l2!=nullptr) ? l2->next : nullptr;
          }
          ListNode* res= dummy->next;
          delete dummy;
          return res;
    }
};
