/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * runner1 = head;
        ListNode * runner2 = head;

        while(runner1 and runner2 and runner1->next){
            runner1 = runner1->next->next;
            runner2 = runner2->next;
            if(runner1==runner2){
                return true;
            }
    }
    return false;
    }
};