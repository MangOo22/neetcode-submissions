class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    int n = tokens.size(), result = 0;
    stack <int> st;
    for (auto& ch : tokens) {
        if (ch == "+") {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            st.push(a + b);
        }
        else if (ch == "-") {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            st.push(b - a);
        }
        else if (ch == "*") {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            st.push(a * b);
        }
        else if (ch == "/") {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            st.push(b/a);
        }
        else st.push(stoi(ch));
    }
    return st.top();
}

};

