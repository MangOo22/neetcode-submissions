class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<char> visit;
            int len = 0;
            for (int j = i; j < n; j++) {
                if (visit.count(s[j]) == 0) {
                    len++;
                    visit.insert(s[j]);
                } else {break;}
            }
            ans = max(ans, len);
        }
        return ans;
    }
};
