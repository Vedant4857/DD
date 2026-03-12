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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode* c;
        if (list1->val <= list2->val) {
            c = list1;
            c->next = mergeTwoLists(list1->next, list2);
        } else {
            c = list2;
            c->next = mergeTwoLists(list1, list2->next);
        }
        return c;
    }
};

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode* temp = list1;
//         ListNode* Head = new ListNode(0);
//         ListNode* Tail = Head;

//         while (list1 && list2) {
//             if (list1->val <= list2->val) {
//                 Tail->next = list1;
//                 list1 = list1->next;
//                 Tail = Tail->next;
//                 Tail->next = NULL;
//             } else {
//                 Tail->next = list2;
//                 list2 = list2->next;
//                 Tail = Tail->next;
//                 Tail->next = NULL;
//             }
//         }
//         while (list1) {
//             Tail->next = list1;
//             list1 = list1->next;
//             Tail = Tail->next;
//             Tail->next = NULL;
//         }
//         while (list2) {
//             Tail->next = list2;
//             list2 = list2->next;
//             Tail = Tail->next;
//             Tail->next = NULL;
//         }

//         Head = Head->next;
//         return Head;
//     }
// };