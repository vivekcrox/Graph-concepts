class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(auto &it : prerequisites){
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
        }

        // topological sort
        vector<int> indegree(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            for(auto &v: adj[i]){
                indegree[v]++;
            }
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(auto &v : adj[node]){
                indegree[v]--;
                if(indegree[v] == 0)
                    q.push(v);
            }
        }

        return cnt == numCourses ? true : false;
    }
};
