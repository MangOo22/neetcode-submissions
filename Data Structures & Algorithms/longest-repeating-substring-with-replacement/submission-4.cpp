class Solution {
public:
  int characterReplacement(string s, int k) {
    int l = 0, r = 0, n = s.size(), ans = 0, max_cnt = 0;
    map<char,int> frq;
    while(r  < n) {
        frq[s[r]]++;
        max_cnt = max(max_cnt, frq[s[r]]);
        if (r - l  + 1 - max_cnt > k) {
            frq[s[l++]]--;
        }
        ans = max(ans, r - l + 1);
        r++;
    }
    return ans;
  }
};

