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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* prev = head;

        while (curr) {
            int x = gcd(curr->val, prev->val);
            ListNode* GCDnode = new ListNode(x);
            prev->next = GCDnode;
            GCDnode->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};