class Solution {
    
    vector<vector<int>> graph;
    vector<bool> visited;

    void constructGraph(int n,  vector<vector<int>>& edges,  vector<vector<int>>& graph) {
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
    }

    bool hasCycle(int node, int parent) {
        visited[node] = true;

        for (int neighbour : graph[node]) {
            if (neighbour == parent) {
                continue;
            }

            if (visited[neighbour]) {
                return true;
            }

            if (hasCycle(neighbour, node)) {
                return true;
            }
        }

        return false;
    }
    
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n == 0) { return false; }

        if (edges.size() != static_cast<size_t>(n - 1)) { return false; }

        graph = vector<vector<int>>(n);
        visited = vector<bool>(n, false);

        constructGraph(edges.size(), edges, graph);

         if (hasCycle(0, -1)) {
            return false;
        }

        for (bool wasVisited : visited) {
            if (!wasVisited) {
                return false;
            }
        }

        return true;

    }


};
