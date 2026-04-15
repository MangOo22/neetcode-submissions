class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        // nums=[9,1,4,7,3,-1,0,5,8,-1,6]
        // nums=[-1,-1,0,3,4,5,6,7,8,9]
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int len = 1;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] == nums[j - 1]) continue;
                if (nums[j] == nums[j - 1] + 1) {
                    len++;
                } else break;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};
