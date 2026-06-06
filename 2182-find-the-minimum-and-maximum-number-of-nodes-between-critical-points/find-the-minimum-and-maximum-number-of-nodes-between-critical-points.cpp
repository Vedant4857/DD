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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalpts;
        int index = 2;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        if (!head->next->next) {
            return {-1, -1};
        }

        while (next) {
            if (curr->val < next->val && curr->val < prev->val) {
                criticalpts.push_back(index);
            } else if (curr->val > next->val && curr->val > prev->val) {
                criticalpts.push_back(index);
            }
            index++;
            prev = curr;
            curr = next;
            next = next->next;
        }
        if (criticalpts.size() < 2) {
            return {-1, -1};
        }
        sort(criticalpts.begin(), criticalpts.end());
        int mini = INT_MAX;
        for (int i = criticalpts.size() - 1; i > 0; i--) {
            mini = min(mini, criticalpts[i] - criticalpts[i - 1]);
        }
        int maxi = criticalpts[criticalpts.size() - 1] - criticalpts[0];

        return {mini, maxi};
    }
};