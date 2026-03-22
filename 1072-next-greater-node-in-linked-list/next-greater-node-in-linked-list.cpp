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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size();
        vector<int> NGR(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] > arr[st.top()]) {
                NGR[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return NGR;
    }
};