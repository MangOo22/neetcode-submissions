public class Solution {
    public int[][] Merge(int[][] intervals) {
        Array.Sort(intervals, (a, b) => a[0].CompareTo(b[0]));
        int n = intervals.Length;
        var result = new List<int[]>();
        result.Add(intervals[0]);

        foreach (int[] interval in intervals) {
            int start = interval[0], end = interval[1];
            int last = result[result.Count - 1][1];

            if (start <= last) {
                result[result.Count - 1][1] = Math.Max(last, end);
            } else {
                result.Add(interval);
            }
        }

        return result.ToArray();
    }
}
