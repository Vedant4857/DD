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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m, vector<int>(n, -1));
        ListNode* temp = head;
        int top = 0, left = 0, right = n - 1, bottom = m - 1;

        while (top <= bottom && left <= right && temp) {
            // Left to Right
            for (int i = left; i <= right && temp; i++) {
                mat[top][i] = temp->val;
                temp = temp->next;
            }
            top++;

            // Top to Bottom
            for (int i = top; i <= bottom && temp; i++) {
                mat[i][right] = temp->val;
                temp = temp->next;
            }
            right--;

            // Right to Left
            for (int i = right; i >= left && temp; i--) {
                mat[bottom][i] = temp->val;
                temp = temp->next;
            }
            bottom--;

            // Bottom to top
            for (int i = bottom; i >= top && temp; i--) {
                mat[i][left] = temp->val;
                temp = temp->next;
            }
            left++;
        }
        return mat;
    }
};