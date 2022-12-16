class MyStack {
    std::queue<int> q1;
    std::queue<int> q2;
    void TrasferQ1ToQ2() {
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
    }
    void TrasferQ2ToQ1() {
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
public:
    MyStack() { }
    
    void push(int x) {
        TrasferQ1ToQ2();
        q1.push(x);
        TrasferQ2ToQ1();
    }
    
    int pop() {
        if (!q1.empty()) {
            int ret = q1.front();
            q1.pop();
            return ret;
        }
        return 0;
    }
    
    int top() {
        return q1.empty() ? 0 : q1.front();
    }
    
    bool empty() {
        return q1.empty() ? true : false;
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
