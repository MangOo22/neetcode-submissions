class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        for (int i : st) {
            if (st.find(i - 1) == st.end()) {
                int len = 1;
                while(st.find(i + len) != st.end()) {
                    len++;
                }
                longest = max(longest, len);
            }
        }
        return longest;
    }
};
