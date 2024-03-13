https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(unordered_map<int,vector<int>>& adj, int u, vector<bool>& visited, vector<int>& result){
        if(visited[u])
            return;
        
        visited[u] = true;
        result.push_back(u);
        
        for(auto &v: adj[u]){
            if(!visited[v])
                dfs(adj, v, visited, result);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> mp[]) {
        //connected undirected graph
        unordered_map<int,vector<int>> adj;
        
        for(int u=0; u<V; u++){
            for(auto & v: mp[u]){
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        vector<int> result;
        vector<bool> visited(V,false);
        
        dfs(adj, 0, visited, result);
        
        return result;
        
    }
};
