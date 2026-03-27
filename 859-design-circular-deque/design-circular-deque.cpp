class Node {
public:
    int val;
    Node *next, *prev;

    Node(int value) {
        val = value;
        next = prev = NULL;
    }
};

class MyCircularDeque {
public:
    Node *front, *rear;
    int size, capacity;
    MyCircularDeque(int k) {
        capacity = k;
        size = 0;
        front = rear = NULL;
    }

    bool insertFront(int value) {
        if (isEmpty()) {
            rear = front = new Node(value);
            size++;
            return true;
        } else if (isFull()) {
            return false;
        } else {
            front->prev = new Node(value);
            front->prev->next = front;
            front = front->prev;
            size++;
            return true;
        }
        return false;
    }

    bool insertLast(int value) {
        if (isEmpty()) {
            rear = front = new Node(value);
            size++;
            return true;
        } else if (isFull()) {
            return false;
        } else {
            rear->next = new Node(value);
            rear->next->prev = rear;
            rear = rear->next;
            size++;
            return true;
        }
        return false;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;
            return true;
        }
        return false;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        } else {
            Node* temp = rear;
            rear = rear->prev;
            delete temp;
            size--;
            return true;
        }
        return false;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return front->val;
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return rear->val;
    }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == capacity; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */