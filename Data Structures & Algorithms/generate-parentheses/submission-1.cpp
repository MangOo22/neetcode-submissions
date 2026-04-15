class Solution {
    bool isValid(const string &s) {
        int open = 0;
        for (char c : s) {
            open += (c == '(' ? 1 : -1);
            if (open < 0) return false;
        }
        return open == 0;
    }
    void generate(int n, string cur, vector<string> &ans) {
        if (cur.size() == 2*n) {
            
            if(isValid(cur)) ans.push_back(cur);
            return;
        }
        generate(n, cur + '(', ans);
        generate(n, cur + ')', ans);
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n, "", ans);
        return ans;
    }
};
