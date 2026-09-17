class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<int> coursesList(numCourses);
        vector<vector<int>> adj(numCourses);
        queue<int> q;

        for (auto& pre : prerequisites) {
            indegree[pre[1]]++;
            adj[pre[0]].push_back(pre[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty()) {
            int curNode = q.front();
            q.pop();
            coursesList[numCourses - count - 1] = curNode;
            count++;
            for (auto nei : adj[curNode]) {
                indegree[nei]--;
                if (indegree[nei] == 0) q.push(nei);
            }
        }

        if (count != numCourses) {
            return {};
        }

        return coursesList;
    }
};
