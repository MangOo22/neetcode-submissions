class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = 0;
        int n = heights.size();
        for (int i = 0; i < n; i++) {
            int mn = heights[i];
            for (int j = i; j < n; j++) {
                mn = min(mn, heights[j]);
                int temp_area = (j - i + 1) * mn;
                area = max(area, temp_area);
            }
        }
        return area;
    }
};
