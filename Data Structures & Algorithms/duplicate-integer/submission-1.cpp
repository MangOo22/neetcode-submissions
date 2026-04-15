class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> frq;
        for (int i = 0; i < nums.size(); i++) {
            if (frq[nums[i]]) return true;
            frq[nums[i]]++;
        }
        return false;
    }
};
