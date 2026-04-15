class Solution {
   
public:
    string minWindow(string s, string t) {
       map<char,int> mp, frq;
       for (char &c : t) mp[c]++;

       int l = 0, r = 0, minL = 0, dist = INT_MAX;
       int cnt = t.size();
       while(r < s.size()) {
          if (mp[s[r]] > 0) {
            cnt--;
          }
          mp[s[r]]--;
          r++;
        //   s = "ADOBECODEBANC"
        //   t = "ABC"
          while (cnt == 0) {
            if (r - l < dist) {
                dist = r - l;
                minL = l;
            }
            if (mp[s[l]] == 0) {
                cnt++;
            }
            mp[s[l]]++;
            l++;
          }
       }
       return dist == INT_MAX ? "" : s.substr(minL, dist);
    }
};
