class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(unordered_map<int,vector<int>>& adj, int u, vector<bool>& visited, vector<int>& result){
        
        queue<int> q;
        q.push(u);
        
        visited[u] = true;
        result.push_back(u);
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(auto &v: adj[u]){
                if(!visited[v]){
                    visited[v] = true;
                    result.push_back(v);
                    q.push(v);
                }
            }
        }
        
    }
    
    vector<int> bfsOfGraph(int V, vector<int> mp[]) {
        
        unordered_map<int,vector<int>> adj;
        
        for(int u=0; u<V; u++){
            for(auto &v: mp[u]){
                adj[u].push_back(v);
            }
        }
        
        vector<int> result;
        vector<bool> visited(V, false);
        
        bfs(adj, 0, visited, result);
        
        return result;
    }
};
