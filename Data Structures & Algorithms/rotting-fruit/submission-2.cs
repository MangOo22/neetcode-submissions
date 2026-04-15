public class Solution {
    bool IsValid(int i, int j , int n , int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    public int OrangesRotting(int[][] grid) {
        int n = grid.Length;
        int m = grid[0].Length;
        Queue<int[]> q = new Queue<int[]>();
        int fresh = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.Enqueue(new int[]{i,j});
                }
                if (grid[i][j] == 1) fresh++;
            }
        }
     

        int[]dx = {1,-1,0,0};
        int[]dy = {0,0,1,-1};
        int ans = 0;

        while(fresh > 0 && q.Count > 0) {
            int len = q.Count;
            for (int j = 0; j < len; j++) {
                var cur = q.Dequeue();
                int row = cur[0], col = cur[1];

                for (int i = 0; i < 4; i++) {
                    int nr = row + dx[i];
                    int nc = col + dy[i];
                    if (IsValid(nr,nc,n,m) && grid[nr][nc] == 1) {
                        fresh--;
                        grid[nr][nc] = 2;
                        q.Enqueue(new int[]{nr,nc});
                    }
                }
            }
            ans++;
            
        }
        return (fresh == 0 ? ans : -1);
    }
}
