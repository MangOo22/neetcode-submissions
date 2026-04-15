class Solution {
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int n, m;

    bool isValid(int i, int j) {
        return i >= 0 and i < n and j >= 0 and j < m;
    }

    void dfs(int i, int j, const vector<vector<char>>& grid, vector<vector<bool>> &vis, char match) {
        vis[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int ni = dx[k] + i;
            int nj = dy[k] + j;
            if (isValid(ni,nj) and !vis[ni][nj] and match == grid[ni][nj]) {
                dfs(ni,nj, grid, vis, match);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] and grid[i][j] == '1') {
                    ans++;
                    dfs(i,j,grid,vis, grid[i][j]);
                }
            }
        }
        return ans;
    }
};
