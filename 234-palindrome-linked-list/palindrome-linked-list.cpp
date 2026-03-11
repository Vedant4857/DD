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
    bool isPalindrome(ListNode* head) {
        if (!head)
            return 0;
        if (!head->next)
            return 1;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = NULL;
        ListNode* curr = slow;
        while (curr) {
            ListNode* future = curr->next;
            curr->next = prev;
            prev = curr;
            curr = future;
        }
        ListNode* temp = head;
        while (prev) {
            if (temp->val != prev->val) {
                return 0;
            }
            temp = temp->next;
            prev = prev->next;
        }
        return 1;
    }
};