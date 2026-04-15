class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> st;
        int area = 0;
        for (int i = 0; i < n; i++) {
            // first next smaller
            int startIdx = i;
            while (st.size() and heights[i] < st.top().second) {
                auto top = st.top();
                int idx = top.first;
                int height = top.second;
                area = max(area,  height * (i - idx));
                startIdx = idx;
                st.pop();
            }
            st.push({startIdx, heights[i]});
        }
        while (st.size()) {auto top = st.top();
            int idx = top.first;
            int height = top.second;
            area = max(area,  height * (n - idx));
            st.pop();
        }
        return area;
    }
};