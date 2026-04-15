public class Solution {
    void dfs(int node, List<List<int>> g, bool[] visit) {
        
        visit[node] = true;

        foreach(int v in g[node]) {
            if (!visit[v]) {
                dfs(v, g, visit);
            }
        }
    }

    public int CountComponents(int n, int[][] edges) {
        int ans = 0;
        List<List<int>>g = new List<List<int>>();
        bool[]visit = new bool[n];
        for (int i = 0; i < n; i++) {
            g.Add(new List<int>());
        }
        foreach (var edge in edges) {
            g[edge[0]].Add(edge[1]);
            g[edge[1]].Add(edge[0]);
        }

        for (int node = 0; node < n; node++) {
            if (!visit[node]) {
                ans++;
                dfs(node, g, visit);
            }
        }

        return ans;
        
    }
}
