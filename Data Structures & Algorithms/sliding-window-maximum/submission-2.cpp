class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        res.push_back(*max_element(nums.begin(), nums.begin() + k));
        multiset<int> ms(nums.begin(), nums.begin() + k);
        for (int i = k; i < nums.size(); i++) {
            ms.erase(ms.find(nums[i - k]));
            ms.insert(nums[i]);
            res.push_back(*ms.rbegin());
        }
        return res;
    }
};
