#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    MyQueue() {
        
    }
    queue<int> queues;
    void push(int x) {
        queues.push(x);
    }
    
    int pop() {
        int top = queues.front();
        queues.pop();
        return top;
    }
    
    int peek() {
        return queues.front();
    }
    
    bool empty() {
        return queues.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */