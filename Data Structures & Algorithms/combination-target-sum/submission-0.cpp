class Solution {
public:
    void f(int i, int target, const vector<int>& nums, vector<int>&set, vector<vector<int>>& res) {
        if (i >= nums.size() or target < 0) {
            return;
        }
        if (target == 0) {
           res.push_back(set);
            return;
        }
        set.push_back(nums[i]);
        f(i, target - nums[i], nums, set, res);
        set.pop_back();
        f(i + 1, target, nums, set, res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       vector<int> set;
       vector<vector<int>> res;
       f(0, target, nums, set, res);
       return res;   
    }
};
