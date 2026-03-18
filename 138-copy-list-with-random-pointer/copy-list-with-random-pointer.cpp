/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;

        // Create a clone list inside the real list
        Node* curr = head;
        while (curr) {
            Node* temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;
        }

        // To copy the random nodes int the new nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Remove both the lists;
        curr = head;
        Node* temp = head->next;
        Node* head2 = head->next;

        while (curr) {
            curr->next = temp->next;
            curr = temp->next;
            if (curr) {
                temp->next = curr->next;
                temp = curr->next;
            }
        }
        return head2;
    }
};