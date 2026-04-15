class Solution {
private:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            while(st.size() and st.top() == '(' and s[i] == ')') i++,st.pop();
            if (i < s.size()) st.push(s[i]);
        }
        return st.empty();
    }
public:
    vector<string> generateParenthesis(int n) {
        string s = {};
        for (int i = 0; i < 2*n ; i++) {
            if (i < n) s.push_back('(');
            else s.push_back(')');
        }
        vector<string> ans;
        do {
            if (!isValid(s)) continue;
            ans.push_back(s);
        } while(next_permutation(s.begin(), s.end()));    
        return ans;
    }
};
