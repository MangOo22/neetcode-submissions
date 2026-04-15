class Solution {
    bool isMatch(char open, char close) {
        if (open == '(' and close == ')') return true;
        if (open == '[' and close == ']') return true;
        if (open == '{' and close == '}') return true;
        return false;
    }
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            while(st.size() and i < s.size() and isMatch(st.top(), s[i])) {
                st.pop();
                i++;
            }
            if (i == s.size()) break;
            st.push(s[i]);
        }
        return st.empty();
    }
};
