class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int> indegree(numCourses, 0);
       vector<vector<int>> adj(numCourses);

       for (auto& pre : prerequisites) {
          indegree[pre[1]]++;
          adj[pre[0]].push_back(pre[1]);
       }

       queue<int> order;
       for (int i = 0; i < numCourses; i++) {
          if (!indegree[i]) {
            order.push(i);
          }
       }
       
       int result = 0;
       while(!order.empty()) {
           int node = order.front();
           order.pop();
           result++;
           for (auto& nei : adj[node]) {
               indegree[nei]--;
               if (!indegree[nei]) {
                  order.push(nei);
               }
           }
       }

       return result == numCourses;
    }
};
