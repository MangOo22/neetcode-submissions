class Solution {
public:
    vector<int>parent;
    int getParent(int node) {
        if (parent[node] == node)return node;
        return parent[node] = getParent(parent[node]);
    }
    void connect(int n1 , int n2) {
        
        parent[getParent(n1)] = getParent(n2);
        //cout << n1 << " " << parent[n1] << endl;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent = vector<int>(n+1);
        for (int i = 1; i <= n; i++){
            parent[i] = i;
        }
        vector<int>ans;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (getParent(u) == getParent(v)) {
                return {u, v};
                
            }
            else connect(u,v);
        }
        return ans;

    }
};
