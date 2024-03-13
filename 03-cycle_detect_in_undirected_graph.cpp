// 1. Using DFS traversal
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfsCycle(vector<int> adj[], int u, int parent, vector<bool>& visited){
        
        visited[u] = true;
        
        for(auto &v: adj[u]){
            if(v == parent)
                continue;
            
            else if(visited[v])
                return true;
                
            else if(dfsCycle(adj, v, u, visited) == true)
                return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
            
        vector<bool> visited(V, false);
        
        for(int i=0; i<V; i++){
            if(!visited[i] && dfsCycle(adj, i, -1, visited) == true)
                return true;
        }
        return false;
    }
};

/*********************************/
//2. Using BFS traversal
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfsCycle(vector<int> adj[], int u, vector<bool>& visited){
        
        queue<pair<int,int>> q;   //{node,parent}
        q.push({u, -1});
        
        visited[u] = true;
        
        while(!q.empty()){
            auto P = q.front();
            q.pop();
            
            int u = P.first;
            int parent = P.second;
            
            for(auto &v: adj[u]){
                if(visited[v] == false){
                    visited[v] = true;
                    q.push({v, u});
                }
                else if(v != parent)
                    return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
            
        vector<bool> visited(V, false);
        
        for(int i=0; i<V; i++){
            if(!visited[i] && bfsCycle(adj, i, visited) == true)
                return true;
        }
        return false;
    }
};
