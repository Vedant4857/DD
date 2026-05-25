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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* a_1 = list1;
        ListNode* b_1 = list1;
        a--;
        b++;

        while(b--&&b_1){
            if(a&&a_1){
                a_1 = a_1->next;
                a--;
            }
            b_1 = b_1->next;
        }
        ListNode* sec = list2;
        while (sec->next) {
            sec = sec->next;
        }

        a_1->next = list2;
        sec->next = b_1;
        return list1;
    }
};