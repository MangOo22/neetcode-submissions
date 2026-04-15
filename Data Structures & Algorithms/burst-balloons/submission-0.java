class Solution {
    int brust(int[] arr, int l, int r , int[][]dp) {
        if (l > r) {
            return 0;
        }
        
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        // 1 2 4 3 5
        for (int i = l; i <= r; i++) {
            int coins = arr[l-1] * arr[i] * arr[r+1];
            coins += brust(arr, l, i - 1, dp);
            coins += brust(arr, i + 1, r, dp);
            dp[l][r] = Math.max(dp[l][r], coins);
        }
        return dp[l][r];
    }
    public int maxCoins(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        
        int n = nums.length;
        int[] newNums = new int[n + 2];
        newNums[0] = newNums[n + 1] = 1;
        for (int i = 0; i < n; i++) {
            newNums[i + 1] = nums[i];
        }

        int[][] dp = new int[n + 2][n + 2];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = -1;
            }
        }

        return brust(newNums, 1, newNums.length - 2, dp);
    }
}
