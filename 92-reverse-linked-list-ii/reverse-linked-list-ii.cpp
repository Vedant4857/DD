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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head)
            return head;
        ListNode dummy(0);
        dummy.next = head;
        int n = 0;
        ListNode* curr = &dummy;
        ListNode* temp = &dummy;
        while (n != left - 1) {
            curr = curr->next;
            temp = temp->next;
            n++;
        }
        ListNode* start = curr;
        temp = curr->next;
        curr = curr->next;
        while (n != right-1  && temp->next) {
            temp = temp->next;
            n++;
        }
        ListNode* prev = temp->next;
        temp->next = NULL;

        while (curr) {
            ListNode* future = curr->next;
            curr->next = prev;
            prev = curr;
            curr = future;
        }
        start->next = prev;

        return dummy.next;
    }
};