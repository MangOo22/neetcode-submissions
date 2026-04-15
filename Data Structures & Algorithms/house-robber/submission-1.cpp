class Solution {
public:
    int dp[101][2];
    bool lastIsValid = true;
    int n;
    int f(int i, int valid, const vector<int>& nums) {
        if (i >= n) return 0;
        int &ret = dp[i][valid];
        if (~ret) return ret;
        int leave = f(i + 1, valid, nums);
        int take = 0;
        if (valid) {
            take = nums[i] + f(i + 2, valid, nums);
        }
        return ret = max(leave, take);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        int ans = f(0,1,nums);
        return ans;
    }
};
