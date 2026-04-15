class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);
        dp[n-1] = cost[n-1];
        for (int i = n - 2; ~i; i--) {
            dp[i] = min(dp[i + 1], dp[i + 2]) + cost[i];
        }
        return min(dp[1],dp[0]);
    }
};