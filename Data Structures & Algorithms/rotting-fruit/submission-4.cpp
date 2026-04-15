class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector < pair < int, int >> dir = {
    {
        -1, 0
    },
    {
        1,
        0
    },
    {
        0,
        -1
    },
    {
        0,
        1
    }
};
    int n = grid.size();
    int m = grid[0].size();

    int ones = 0;
    queue < pair < int, int >> pq;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) ones++;
            if (grid[i][j] == 2)
                pq.push({
                    i,
                    j
                });
        }
    }
    if (!ones){
      return 0;
    } 
    /*
     1 1 0
     0 2 2
     0 2 2
    */
    int ans = 0;
    while (pq.size()) {
        int len = pq.size();
        bool ok = 0;
        for (int i = 0; i < len; i++) {
            pair < int, int > cur = pq.front();
            pq.pop();
            for (auto &it: dir) {
                int dx = cur.first + it.first;
                int dy = cur.second + it.second;
                if (dx < n and dx >= 0 and dy < m and dy >= 0 and grid[dx][dy] == 1) {
                    ones--;
                    ok = 1;
                    grid[dx][dy] = 2;
                    pq.push({
                        dx,
                        dy
                    });
                }
            }
        }
        if (ok)
        ans++;
    }
    if (ones) return -1 ;
    return ans;

    }
};
