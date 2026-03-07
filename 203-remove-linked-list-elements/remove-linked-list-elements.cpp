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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return NULL;

        while (head && head->val == val) {
            head = head->next;
        }
        if (!head)
            return NULL;
        ListNode *temp = head->next, *temp2 = head;
        while (temp) {
            if (temp->val == val) {
                temp2->next = temp->next;
                temp = temp->next;
            } else {
                temp = temp->next;
                temp2 = temp2->next;
            }
        }
        return head;
    }
};