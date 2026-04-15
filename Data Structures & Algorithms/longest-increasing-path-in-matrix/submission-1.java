class Solution {
    int[] di = {1,-1,0,0};
    int[] dj = {0,0,1,-1};
    int n, m;
    boolean isValid(int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        return true;
    }
    int lcs(int[][] mat, int i, int j, int prev, int[][]dp) {
        if (!isValid(i,j) || mat[i][j] <= prev) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int res = 1;
        for (int k = 0; k < 4; k++) {
            int ni = di[k] + i;
            int nj = dj[k] + j;
            res = Math.max(res,lcs(mat,ni,nj,mat[i][j],dp) + 1);
        }
        return dp[i][j] = res;
    }
    public int longestIncreasingPath(int[][] matrix) {
        if(matrix == null) {
            return 0;
        }
        n = matrix.length;
        m = matrix[0].length;
        int[][] dp = new int[n][m];
        for (int i =  0;  i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = -1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = Math.max(ans, lcs(matrix,i,j,-1,dp));
            }
        }
        return ans;
    }
}
