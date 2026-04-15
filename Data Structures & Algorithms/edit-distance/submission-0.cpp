class Solution {
     vector<vector<int>> dp;

    int dfs(int i, int j, string w1, string w2, int n, int m)
    {
        if (i == n) return m - j;
        if (j == m) return n - i;

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (w1[i] == w2[j]) {
           return dp[i][j] = dfs(i + 1, j + 1, w1, w2, n, m);
        }
        else {
            int res = min(dfs(i + 1, j, w1, w2, n, m),
            dfs(i, j + 1, w1, w2, n, m));
            res = min(res, dfs(i + 1, j + 1, w1, w2, n, m));

            return dp[i][j] = res + 1;
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
       
        return dfs(0,0,word1,word2, n , m);
    }
};
