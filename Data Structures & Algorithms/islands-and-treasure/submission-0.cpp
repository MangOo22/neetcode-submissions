class Solution {
    const int INF = 2147483647;
    bool IsValid(int i, int j, int n, int m, int val) {
        return 1;
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }

        if (q.size() == 0) {
            return;
        }
        int dx[4]  = {1,-1,0,0}; 
        int dy[4]  = {0,0,1,-1}; 
        while(q.size() > 0) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = row + dx[i];
                int nc = col + dy[i];
                if ((nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] != INT_MAX)) {
                    continue;
                }
                q.push({nr,nc});
                grid[nr][nc] = grid[row][col] + 1;
            }
        }

    }
};




/// make a bfs to travese on the grid and update each cell 
//  with the new value 