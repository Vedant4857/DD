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
    ListNode* insertionSortList(ListNode* head) {
        if (!head)
            return NULL;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = head;
        ListNode* temp2 = head->next;

        while (temp2) {
            if (temp2->val >= prev->val) {
                prev = temp2;
                temp2 = temp2->next;
                continue;
            }

            ListNode* temp1 = &dummy;

            while (temp1->next->val < temp2->val) {
                temp1 = temp1->next;
            }

            prev->next = temp2->next;
            temp2->next = temp1->next;
            temp1->next = temp2;

            temp2 = prev->next;
        }

        return dummy.next;
    }
};