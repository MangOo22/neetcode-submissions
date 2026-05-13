class Solution {
    bool canReplaceChar(int k, int currentReplacementChars) {
        return currentReplacementChars <= k;
    }
public:
    int characterReplacement(string s, int k) {
        int currentMaxCount = 0;
        int l = 0, r = 0;
        int ans = 0;
        map<char, int> frequency;
        while (r < s.size()) {
           frequency[s[r]]++;
           currentMaxCount = max(currentMaxCount, frequency[s[r]]);
           if (r - l + 1 - currentMaxCount > k) {
              frequency[s[l]]--;
              l++;
           }
           ans = max(ans, r - l + 1);
           r++;
        }

        return ans;
    }
};

