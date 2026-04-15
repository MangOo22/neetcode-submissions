class Solution {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int n, m;

    bool is_valid(int i, int j) {
        return i >= 0 and i < n and j >= 0 and j < m;
    }

    bool is_on_board(int i, int j) {
        return i == 0 or i == n - 1 or j == 0 or j == m - 1;
    }

    void dfs(int i, int j, vector<vector<char>>& board) {
        if (not is_valid(i,j) || board[i][j] != 'O') {
            return;
        }
        board[i][j] = 'S';
        for (int d = 0; d < 4; d++) {
            int ni = dx[d] + i;
            int nj = dy[d] + j;
            dfs(ni, nj, board);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        if (n == 0) return;
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {     
                if (board[i][j] == 'O' and is_on_board(i,j))
                    dfs(i, j, board);
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'S') board[i][j] = 'O';
            }
        }
        
    }
};