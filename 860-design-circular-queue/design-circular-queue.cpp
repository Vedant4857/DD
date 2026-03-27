class MyCircularQueue {
public:
    int front,rear,size,capacity;
    int * arr;
    MyCircularQueue(int k) {
        arr = new int[k];
        capacity = k;
        size = 0;
        front = rear = -1;
    }
    
    bool enQueue(int value) {
        if(isEmpty()){
            front = rear = 0;
            arr[rear] = value;
            size++;
            return true;
        }
        else if(isFull()){
            return false;
        }
        else{
            rear = (rear+1)%capacity;
            arr[rear] = value;
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
            front = (front+1)%capacity;
            size--;
            return true;
        }
        return 0;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
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