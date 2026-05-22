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
    int GCD(int a, int b) {
        int result = min(a, b);
        while (result > 0) {
            if (a % result == 0 && b % result == 0) {
                return result;
            }
            result--;
        }
        return 0;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* prev = head;

        while (curr) {
            int x = GCD(curr->val, prev->val);
            ListNode* GCDnode = new ListNode(x);
            prev->next = GCDnode;
            GCDnode->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};