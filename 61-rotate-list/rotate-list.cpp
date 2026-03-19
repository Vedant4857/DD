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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next or k==0) return head;
        ListNode * temp = head;
        int count=1;

        while(temp->next){
            temp = temp->next;
            count++;
        }
         k = k % count;

        temp->next = head;

        ListNode * newtail = head;
        int steps = count-k-1;

        while(steps--){
            newtail = newtail->next;
        }

        ListNode * newhead = newtail->next;
        newtail->next = nullptr;
        return newhead;
    }
};