class Solution {
    string fixS(string &s) {
        string res;
        for (char &ch : s) {
            if (isalpha(ch) or isdigit(ch)) {
                res.push_back(tolower(ch));
            }
        }
        return res;
    }
    bool isAPalindrome(const string &s) {
        int len = s.size();
        for (int i = 0; i < len/2; i++) {
            if (s[i] != s[len - i - 1]) {
                return false;
            }
        }
        return true;
    }
public:
    bool isPalindrome(string s) {
        string newS = fixS(s);
        return isAPalindrome(newS);
    }
};
