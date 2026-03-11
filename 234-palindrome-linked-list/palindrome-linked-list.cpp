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
        if(!head) return 0;
        if(head->next==NULL) return 1;
        vector<int>arr;
        ListNode * temp = head;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        int j = arr.size()-1;
        while(temp){
            if(temp->val!=arr[j]){
                return 0;
            }
            j--;
            temp = temp->next;
        }
        return 1;
    }
};