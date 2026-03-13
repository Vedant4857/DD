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
    ListNode* merge2sorted(ListNode* head1, ListNode* head2) {
        if (!head1)
            return head2;
        if (!head2)
            return head1;
        ListNode* c;

        if (head1->val <= head2->val) {
            c = head1;
            c->next = merge2sorted(head1->next, head2);
        } else {
            c = head2;
            c->next = merge2sorted(head1, head2->next);
        }

        return c;
    }
    ListNode* merge(vector<ListNode*>& lists, int start, int end) {
        if (start == end)
            return lists[end];
        int mid = start + (end - start) / 2;

        ListNode* head1 = merge(lists, start, mid);
        ListNode* head2 = merge(lists, mid + 1, end);

        return merge2sorted(head1, head2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        return merge(lists, 0, lists.size() - 1);
    }
};