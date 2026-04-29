public class Solution {
    public int LargestRectangleArea(int[] heights) {
        int n = heights.Length;
        int ans = 0;
        for (int i = 0 ; i < n; ++i) {
            int currentMin = heights[i];
            int currentAns = 0;
            int currentWidth = 0;
            for (int j = i; j < n; j++) {
                currentMin = Math.Min(currentMin, heights[j]);
                currentWidth++;
                currentAns = Math.Max(currentAns, currentMin * currentWidth);
            }
            ans = Math.Max(ans, currentAns);
        }
        return ans;
    }
}
