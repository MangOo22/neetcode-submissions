public class Solution {
    public int FindDuplicate(int[] nums) {
        return FindDuplicateNumber(nums);
    }
    private int FindDuplicateNumber(int[] nums) {
        var visited = new HashSet<int>();
        foreach (int num in nums) {
            if (visited.Contains(num)) {
                return num;
            }
            visited.Add(num);
        }
        return 0;
    }
}
