class Solution {
public:
     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        ans.push_back(*max_element(nums.begin(), nums.begin() + k));
        multiset<int> st(nums.begin(), nums.begin() + k);
        for (int i = k; i < nums.size(); i++) {
        st.erase(st.find(nums[i - k]));
        st.insert(nums[i]);
        ans.push_back(*st.rbegin());
        }
        return ans;
  }
};
