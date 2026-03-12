class MyLinkedList {
public:
    struct node {
        int val;
        node* next;
        node* prev;
        node(int value) {
            val = value;
            next = prev = nullptr;
        }
    };

    node* head;
    int size;

    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size)
            return -1;
        node* curr = head;

        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }

    void addAtHead(int val) {
        node* newHead = new node(val);
        newHead->next = head;
        if (head)
            head->prev = newHead;
        head = newHead;
        size++;
    }

    void addAtTail(int val) {
        node* temp = new node(val);
        if (!head) {
            head = temp;
            size++;
            return;
        }
        node* curr = head;

        while (curr->next) {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size)
            return;

        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        node* newnode = new node(val);
        node* curr = head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }

        newnode->next = curr->next;
        newnode->prev = curr;

        if (curr->next) {
            curr->next->prev = newnode;
        }
        curr->next = newnode;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;

        node* curr = head;
        if (index == 0) {
            head = head->next;
            if (head)
                head->prev = NULL;
            delete curr;
            size--;
            return;
        }

        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        if (curr->next) {
            curr->next->prev = curr->prev;
        }
        delete curr;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */