class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        unordered_map<int,int> complement;
        for (int i = 0; i < n; i++) {
            complement[nums[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x = nums[i] + nums[j];
                auto it = complement.find(-x);
                if (it != complement.end()) {
                    int pos = it->second;
                    int idx = it->first;
                    if (pos != i and pos != j) {
                      vector<int> ss = {nums[i], nums[j], -x};
                      sort(ss.begin(), ss.end());
                      res.insert(ss);
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};
