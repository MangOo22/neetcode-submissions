class MinStack {
    vector<int> st;
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push_back(val);
    }
    
    void pop() {
        if (st.size())
          st.pop_back();
    }
    
    int top() {
        if (st.size())
          return st.back();
    }
    
    int getMin() {
        if (st.size())
           return *min_element(st.begin(), st.end());
    }
};
