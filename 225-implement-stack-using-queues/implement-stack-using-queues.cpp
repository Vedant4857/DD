class MyStack {
public:
    queue<int> q;
    MyStack() {}

    void push(int x) {
        q.push(x);
        int n = q.size();
        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int r = q.front();
        q.pop();
        return r;
    }

    int top() { return q.front(); }

    bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// USING TWO QUEUE::::
//  class MyStack {
//      public:
//      queue<int>q1;
//      queue<int>q2;
//      MyStack() {

//     }

//     void push(int x) {
//         if(!q1.empty()){
//             q1.push(x);
//         }
//         else{
//             q2.push(x);
//         }
//     }

//     int pop() {
//         if(!q1.empty()){

//             while(q1.size()>1){
//                 q2.push(q1.front());
//                 q1.pop();
//             }

//             int number = q1.front();
//             q1.pop();
//             return number;

//         }
//         else{

//             while(q2.size()>1){
//                 q1.push(q2.front());
//                 q2.pop();
//             }

//             int number = q2.front();
//             q2.pop();
//             return number;
//         }
//     }

//     int top() {
//         if(!q1.empty()){
//             return q1.back();
//         }
//         else{
//             return q2.back();
//         }
//     }

//     bool empty() {
//         return q1.empty()&&q2.empty();

//     }
// };
