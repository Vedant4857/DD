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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next)
            return head;
        ListNode fdummy(0);
        ListNode sdummy(0);
        ListNode* first = &fdummy;
        ListNode* second = &sdummy;
        ListNode* temp = head;

        while (temp) {
            if (temp->val < x) {
                first->next = temp;
                first = first->next;
            } else {
                second->next = temp;
                second = second->next;
            }
            temp = temp->next;
        }
        first->next = sdummy.next;
        second->next = NULL;

        return fdummy.next;
    }
};