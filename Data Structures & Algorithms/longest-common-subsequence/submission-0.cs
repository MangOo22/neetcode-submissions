public class Solution {
    private int[,] dp;

    private int LCS(int i, int j, string s, string t) {
        if (i == s.Length || j == t.Length) {
            return 0;
        }

        if (dp[i,j] != -1) {
            return dp[i,j];
        }

        if (s[i] == t[j]) {
            dp[i,j] = 1 + LCS(i + 1, j + 1, s, t);
        } else {
            dp[i,j] = Math.Max(LCS(i + 1, j, s, t), LCS(i, j + 1, s, t));
        }
        return dp[i,j];
    }

    public int LongestCommonSubsequence(string text1, string text2) {
        dp = new int [text1.Length, text2.Length];

        for (int i = 0; i < text1.Length; i++) {
            for (int j = 0; j < text2.Length; j++) {
                dp[i,j] = -1;
            }
        }
        return LCS(0, 0, text1, text2);
    }
}
