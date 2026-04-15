public class Solution {
    public int MinEatingSpeed(int[] piles, int h) {
        
        int l = 1;
        int r = piles.Max();
        int ans = r;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if (CanEat(mid, piles, h)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    private bool CanEat(int x, int[] piles, int h) {
        long sum = 0;
        foreach (int pile in piles) {
            sum += ((pile + x - 1)/x);
        }
        return sum <= h;
    }
}
