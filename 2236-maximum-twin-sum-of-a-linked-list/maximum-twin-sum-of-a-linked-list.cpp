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
    int pairSum(ListNode* head) {
        int size = 0;
        vector<int> sums;
        ListNode* slow = head;
        sums.push_back(head->val);
        ListNode* fast = head->next;

        while (fast->next) {
            slow = slow->next;
            sums.push_back(slow->val);
            fast = fast->next->next;
        }
        slow = slow->next;
        int n = sums.size();
        for (int i = n - 1; i >= 0; i--) {
            if (slow) {
                sums[i] += slow->val;
                slow = slow->next;
            }
        }
        return *max_element(sums.begin(), sums.end());
    }
};