class MinStack {
public:
    stack<int> currStack;
    stack<int> minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        currStack.push(val);
        if (minStack.empty())
            minStack.push(val);
        else
            minStack.push(std::min (val, minStack.top()));
        
    }
    
    void pop() {
        currStack.pop();
        minStack.pop();
    }
    
    int top() {
        return currStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
