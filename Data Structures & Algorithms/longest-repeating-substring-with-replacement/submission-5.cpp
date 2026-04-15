class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, ans = 0;
        int n = s.size();
        unordered_map<char,int> count;
        for (int r = 0; r < n; r++) {
            count[s[r]]++;
            int maxFrqChar = max(maxFrqChar, count[s[r]]);
            while((r - l + 1) - maxFrqChar > k) {
                count[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;

    }
};
