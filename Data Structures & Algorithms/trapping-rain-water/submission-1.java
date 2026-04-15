class Solution {
    public int trap(int[] height) {
        int n = height.length;
        if (height == null || n == 0) {
            return 0;
        }

        int l = 0, r = n-1;
        int left_max = height[l], right_max = height[r];
        int ans = 0;
        while(l < r) {
            if (left_max < right_max) {
                l++;
                left_max = Math.max(left_max, height[l]);
                ans += left_max - height[l];
            } else {
                r--;
                right_max = Math.max(right_max, height[r]);
                ans += right_max - height[r];
            }
        }
        return ans;
        
    }
}
