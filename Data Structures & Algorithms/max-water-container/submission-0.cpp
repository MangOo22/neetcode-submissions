class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int answer = 0;
        while (l < r) {
            int len = r - l;
            int leftHeight = heights[l], rightHeight = heights[r];
            int curMax = len * min(leftHeight, rightHeight);
            answer = max(answer, curMax);
            if (leftHeight < rightHeight) {l++;}
            else {r--;}
        }
        return answer;
    }
};
