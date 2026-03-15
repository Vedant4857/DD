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
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if (!head1)
            return head2;
        if (!head2)
            return head1;

        ListNode* c;

        if (head1->val <= head2->val) {
            c = head1;
            c->next = merge(head1->next, head2);
        } else {
            c = head2;
            c->next = merge(head1, head2->next);
        }
        return c;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* mid = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = mid;
            mid = mid->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;
        ListNode* head1 = sortList(head);
        ListNode* head2 = sortList(mid);

        return merge(head1, head2);
    }
};