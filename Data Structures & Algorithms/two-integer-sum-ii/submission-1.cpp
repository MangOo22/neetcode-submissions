class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // [num, index of this num]
        unordered_map<int, int> compliment;
        int n = numbers.size();
        for (int i = 0; i < n; i++) {
            int comp = target - numbers[i];
            if (compliment.find(comp) != compliment.end()) {
                return {compliment[comp], i + 1};
            }
            compliment.insert({numbers[i], i + 1});
        }
    }
};
