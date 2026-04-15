class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefixMax(n);
        vector<int> postMax(n);

        prefixMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(height[i], prefixMax[i-1]);
        }

        postMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            postMax[i] = max(postMax[i + 1], height[i]);
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            int mini = min(prefixMax[i], postMax[i]);
            ans += mini - height[i];
        }

        return ans;
    }
};

