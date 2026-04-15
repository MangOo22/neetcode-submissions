class Solution {
public:
   
    void f(int i, const vector<int> &nums, vector<int>& ans, vector<vector<int>> &res) {
        if (i >= nums.size()) {
            res.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        f(i+1, nums, ans,res);
        ans.pop_back();
        f(i+1, nums, ans,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> res;
        f(0, nums, ans, res);
        return res;
    }
};
