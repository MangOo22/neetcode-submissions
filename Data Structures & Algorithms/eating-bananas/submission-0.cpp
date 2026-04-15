class Solution {
    int canEat(int k, const vector<int> &piles) {
        int sum = 0;
        for (int i = 0; i < piles.size(); i++) {
            sum += (piles[i] + k - 1) / k;
        }
        return sum;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = r;
        while(l <= r) {
            int mid = l + (r-l) / 2;
            if (canEat(mid, piles) <= h) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
