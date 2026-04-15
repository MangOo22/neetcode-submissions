class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> visit;
        int l = 0, r = 0, ans = 0;
        while(r < n) {
            while(r < n and visit.count(s[r]) == 0) {
                visit.insert(s[r]);
                r++;
            }
            ans = max(ans, r - l);
            visit.erase(s[l]);
            l++;
        } 
        return ans;
    }
};
