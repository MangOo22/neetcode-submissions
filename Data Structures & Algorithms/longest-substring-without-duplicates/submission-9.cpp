class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int ans = 0;
        int n = s.size();

        unordered_map<char,bool> visited;
        while(r < n) {
            if(visited[s[r]] == false) {
                visited[s[r]] = true;
                r++;
            }
            else {
                visited[s[l]] = false;
                l++;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};
