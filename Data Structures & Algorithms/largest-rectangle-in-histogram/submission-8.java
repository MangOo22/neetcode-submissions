class Solution {
    public int largestRectangleArea(int[] heights) {
        //       pair<height, index>
        Stack<int[]> st = new Stack<>();
        int ans = 0;
        int n = heights.length;
        for (int i = 0; i < n; i++) {
            int idx = i;
            while (!st.isEmpty() && heights[i] < st.peek()[0]) {
                idx = st.peek()[1];
                int h = st.peek()[0];
                ans = Math.max(ans, h * (i - idx));
                st.pop();
            }
            
            st.push(new int[]{heights[i],idx});
        }
        while (!st.isEmpty()) {
            int val = st.peek()[0];
            int idx = st.peek()[1];
            ans = Math.max(ans, val * (n - idx));
            st.pop();
        }
        return ans;
    }
}
