class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = *max_element(heights.begin(), heights.end());
        int n = heights.size();
        stack<pair<int,int>> st;
        st.push({heights[0],0});
        for (int i = 0; i < n; i++ ) {
            int idx = i;
            while(st.size() and heights[i] < st.top().first) {
                idx = st.top().second;
                int h = st.top().first;
                ans = max(ans, h * (i - idx));
                st.pop();
            }
            st.push({heights[i],idx});
        }
        while(st.size()) {
            int val = st.top().first;
            int idx = st.top().second;
            ans = max(ans, (n - idx) * val);
            st.pop();
        }
        return ans;
    }
};
