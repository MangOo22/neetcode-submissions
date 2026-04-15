class Solution {
   
public:
    string minWindow(string s, string t) {
       map<char,int> frq;
       for (char &c : t) frq[c]++;

       int l = 0, r = 0, minL = 0, dist = INT_MAX;
       int cnt = t.size();

       while(r < s.size()) {
          if (frq[s[r]] > 0) {
            cnt--;
          }

          frq[s[r]]--;
          r++;

          while (cnt == 0) {
            if (r - l < dist) {
                dist = r - l;
                minL = l;
            }
            if (frq[s[l]] == 0) {
                cnt++;
            }
            frq[s[l]]++;
            l++;
          }
       }
       return dist == INT_MAX ? "" : s.substr(minL, dist);
    }
};
