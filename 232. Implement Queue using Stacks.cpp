/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

class MyQueue {
    // Implementation is pop heavy
    // push in O(1)
    // pop/peek is O(n)
    std::stack<int> s1;
    std::stack<int> s2;
    void transferS1toS2() {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
public:
    MyQueue() { }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if (s2.empty()) {
            transferS1toS2();
        }
        int ret = s2.empty() ? 0 : s2.top();
        if (!s2.empty()) s2.pop();
        return ret;
    }
    
    int peek() {
        if (s2.empty()) {
            transferS1toS2();
        }
        return s2.empty() ? 0 : s2.top();
    }
    
    bool empty() {
        if (s1.empty() && s2.empty()) return true;
        return false;
    }
};


class MyQueue {
    // Implementation is push heavy
    // push in O(n)
    // pop/peek is O(1)
    std::stack <int> input, output;
    void transferOutputToInput() {
        while (output.empty()) {
            input.push( output.top() );
            output.pop();
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while (!output.empty()) {
            input.push ( output.top() );
            output.pop();
        }
        output.push (x);
        while (!input.empty()) {
            output.push (input.top() );
            input.pop();
        }
    }
    
    int pop() {
        if (output.empty()) return -1;
        int ret = output.top();
        output.pop();
        return ret;
    }
    
    int peek() {
        return (output.empty()) ? -1 : output.top();
    }
    
    bool empty() {
        return output.empty();
    }
};
