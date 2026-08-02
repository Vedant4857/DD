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
    ListNode* mergeNodes(ListNode* head) {
        vector<int> sum;
        ListNode* temp = head->next;
        int value = 0;
        while (temp) {
            value += temp->val;
            if (temp->val == 0) {
                sum.push_back(value);
                value = 0;
            }
            temp = temp->next;
        }

        ListNode* head1 = new ListNode(sum[0]);
        ListNode* temp1 = head1;
        for (int i = 1; i < sum.size(); i++) {
            temp1->next = new ListNode(sum[i]);
            temp1 = temp1->next;
        }
        temp1->next = NULL;
        return head1;
    }
};