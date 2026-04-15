class Solution {
    int dp[102][2];
    int f(int i, int valid, const vector<int>& nums) {
        if(i == nums.size()) return 0;
        int &ret = dp[i][valid];
        if (~ret) return ret;
        int leave = f(i + 1, 1, nums);
        int take = 0;
        if (valid) {
            take = nums[i] + f(i + 1, 0, nums);
        }
        return ret = max(leave, take);
    }
public:
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return f(0, 1, nums);
    }
};
