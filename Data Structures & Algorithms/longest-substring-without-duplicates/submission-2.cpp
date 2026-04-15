
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int l = 0, r = 0, ans = 0;
    map<char,int> frq;
    while(r < n) {
       if(not frq[s[r]]) {
        frq[s[r++]]++;
       }
       else frq[s[l++]]--;
       ans = max(ans, r - l);
    }
    return ans;
  }
};
