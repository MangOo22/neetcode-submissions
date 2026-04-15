class Solution {
private:
  bool canCloseIt(char top, char ch) {
    return (top == '[' and ch == ']') ||
      (top == '{' and ch == '}') ||
      (top == '(' and ch == ')');
  }
public:
  bool isValid(string s) {
   stack<char> st;
    for (int i = 0; i < s.size(); i++) {
      while (st.size() and canCloseIt(st.top(), s[i])) i++, st.pop();
      if (i < s.size()) st.push(s[i]);
    }
    return st.empty();
  }
};
