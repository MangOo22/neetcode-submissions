class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,10000);
        dp[n-1] = 0;
        for (int i = n-1; ~i; i--) {
            for (int j = 0; j <= nums[i]; j++) {
                if (i + j < n) {
                    dp[i] = min(dp[i+j] + 1, dp[i]);
                }
            }
        }
        return dp[0];
    }
};