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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (!head)
            return NULL;
        int n = nums.size();
        unordered_set<int> vedant;
        for (int i = 0; i < n; i++) {
            vedant.insert(nums[i]);
        }
        while (head && vedant.count(head->val)) {
            head = head->next;
        }
        if (!head)
            return NULL;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr) {
            if (vedant.count(curr->val)) {
                prev->next = curr->next;
            } else {
                prev = prev->next;
            }
            curr = curr->next;
        }
        return head;
    }
};