class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& adj, int u, vector<bool>& visited){

        visited[u] = true;

        for(auto & v: adj[u]){
            if(!visited[v])
                dfs(adj, v, visited);
        }
    }

    void bfs(unordered_map<int,vector<int>>& adj, int u, vector<bool>& visited){

        queue<int> q;
        q.push(u);

        visited[u] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto &v: adj[u]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        unordered_map<int,vector<int>> adj;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j && isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                // dfs(adj, i, visited);
                bfs(adj, i, visited);
                cnt++;
            }
        }
        return cnt;
    }
};
