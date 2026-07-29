class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";
        vector<int> frq(27);
        for (int i = 0; i < s.size(); i++) {
            frq[s[i] - 'a']++;
        }

        for ( int i = 0; i < order.size(); i++) {
            while (frq[order[i] - 'a']) {
                ans += order[i];
                frq[order[i] - 'a']--;
            }
        }

        for (int i = 0; i < s.size(); i++) {
            while(frq[s[i] - 'a']) {
                ans += s[i];
                frq[s[i] - 'a']--;
            }
        }

        return ans;
    }
};

