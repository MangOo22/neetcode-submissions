class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int []left = new int[n];
        int []right = new int[n];
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                left[i] = height[i];
                continue;
            }
            left[i] = Math.max(left[i - 1] , height[i]);
        }
        for (int i = n-1; i >= 0; i--) {
            if (i == n-1) {
                right[i] = height[i];
                continue;
            }
            right[i] = Math.max(right[i + 1], height[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (Math.min(left[i], right[i]) - height[i]);
        }
        return ans;
    }
}
