class Node{
    public:
    int val;
    Node * next;

    Node(int value){
        val = value;
        next = NULL;
    }
};

class MyCircularQueue {
public:
    int size,capacity;
    Node * front, * rear;
    MyCircularQueue(int k) {
        size = 0;
        capacity = k;
        front = rear = NULL;
    }
    
    bool enQueue(int value) {
        if(isEmpty()){
            rear = front = new Node(value);
            rear->next = rear;
            size++;
            return true;
        }
        else if(isFull()){
            return false;
        }
        else{
            rear->next = new Node(value);
            rear = rear->next;
            rear->next = front;
            size++;
            return true;
        }
        return 0;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        else{
            //if size ==1
            if(size==1){
                delete rear;
                rear = front = NULL;
                size--;
                return true;
            }
            front = front->next;
            delete rear->next;
            rear->next = front;
            size--;
            return true;
        }
        return 0;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return front->val;
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return rear->val;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */