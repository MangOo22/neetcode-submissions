public class Solution {
    private bool IsValid(int i, int j, int n, int m) {
        return !(i < 0 || i >= n || j < 0 || j >= m);
    }
    public void islandsAndTreasure(int[][] grid) {
        int n = grid.Length;
        int m = grid[0].Length;
        
        Queue<int[]> q = new Queue<int[]>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.Enqueue(new int[] {i,j});
                }
            }
        }

        if (q.Count == 0) {
            return;
        }
        int[] dx = {1,-1,0,0}; 
        int[] dy = {0,0,1,-1}; 
        while(q.Count > 0) {
            int[] cur = q.Dequeue();
            int row = cur[0];
            int col = cur[1];
            for (int i = 0; i < 4; i++) {
                int nr = row + dx[i];
                int nc = col + dy[i];
                if (!IsValid(nr, nc, n, m) || grid[nr][nc] != int.MaxValue) {
                    continue;
                }
                q.Enqueue(new int[] {nr,nc});
                grid[nr][nc] = grid[row][col] + 1;
            }
        }

    }


}

