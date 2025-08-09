#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    MyStack() {
        // stack<int> stacks;
    }
    stack<int> stacks;
    void push(int x) {
        stacks.push(x);
    }
    
    int pop() {
        int top = stacks.top();
        stacks.pop();
        return top;
    }
    
    int top() {
        return stacks.top();
    }
    
    bool empty() {
        return stacks.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */