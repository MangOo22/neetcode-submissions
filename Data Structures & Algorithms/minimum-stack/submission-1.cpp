class MinStack {
private:
  stack <int> reg_stack;
  stack <int> min_stack;
public:
  MinStack() {
  }

  void push(int val) {
    reg_stack.push(val);
    val = min(val, min_stack.empty() ? val : min_stack.top());    
    min_stack.push(val);
  }

  void pop() {
    reg_stack.pop();
    min_stack.pop();
  }

  int top() {
    return reg_stack.top();
  }

  int getMin() {
    return min_stack.top();
  }
};

