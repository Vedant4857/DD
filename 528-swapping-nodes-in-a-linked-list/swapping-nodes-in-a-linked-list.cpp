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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* num1 = &dummy;
        ListNode* num2 = &dummy;
        int k1 = k;
        while (k1-- && num1) {
            num1 = num1->next;
        }
        ListNode* num1real = num1;

        while (num1 && num2) {
            num1 = num1->next;
            num2 = num2->next;
        }
        int fvalue = num2->val;
        num2->val = num1real->val;
        num1real->val = fvalue;
        return head;
    }
};