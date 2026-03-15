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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next)
            return NULL;

        int n = 0;
        ListNode* slow = head;
        while (slow) {
            slow = slow->next;
            n++;
        }
        n = n / 2;

        ListNode* temp = head;
        ListNode* prev = head;

        while (n--) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        return head;
    }
};