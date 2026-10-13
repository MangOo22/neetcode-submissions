/**
 * Definition of Interval:
 * public class Interval {
 *     public int start, end;
 *     public Interval(int start, int end) {
 *         this.start = start;
 *         this.end = end;
 *     }
 * }
 */

public class Solution {
    public bool CanAttendMeetings(List<Interval> intervals) {
        intervals.Sort((i1, i2) => i1.start.CompareTo(i2.start));

        for (int i = 1; i < intervals.Count; i++) {
            if(intervals[i - 1].end > intervals[i].start) {
                return false;
            }
        }
        return true;
    }

}
