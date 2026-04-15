public class Solution {
    public int FindDuplicate(int[] nums) {
        return FindDuplicateNumber(nums);
    }
    private int FindDuplicateNumber(int[] nums) {
        for (int i = 0; i < nums.Length; i++) {
            int idx = Math.Abs(nums[i]) - 1;
            if (nums[idx] < 0) return Math.Abs(nums[i]);
            nums[idx] *= -1;
        }
        return -1;
    }
}

