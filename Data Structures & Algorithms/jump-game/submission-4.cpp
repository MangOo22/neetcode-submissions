class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int dp[n] = {0};
        dp[n-1] = 1;
        for (int i = n-2; ~i; i--) {
            for (int j = 0; j <= nums[i]; j++) {
                if (i + j < n) {
                    dp[i] |= dp[i+j];
                }
            }
        }
        return dp[0];
    }
};
