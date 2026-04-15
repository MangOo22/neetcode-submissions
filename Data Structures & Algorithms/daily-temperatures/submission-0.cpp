class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<pair<int, int>> st;
        for (int i = 0; i < n; i++) {
            int cur_temp = temperatures[i];
            while (st.size() and cur_temp > st.top().first) {
                int idx = st.top().second;
                res[idx] = i - idx;
                st.pop();
            }
            st.push({ cur_temp,i });
        }
        return res;
    }
};
