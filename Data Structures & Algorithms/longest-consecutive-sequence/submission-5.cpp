class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        // nums=[9,1,4,7,3,-1,0,5,8,-1,6]
        // nums=[-1,-1,0,3,4,5,6,7,8,9]
        unordered_set<int> comp(nums.begin(), nums.end());
        for (auto &num : comp) {
            if (comp.find(num - 1) == comp.end()) {
                int len = 1;
                while(comp.find(len + num) != comp.end()) {
                    len++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
