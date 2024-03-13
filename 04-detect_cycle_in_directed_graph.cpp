//1. Using DFS traversal
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCycleDfs(vector<int> adj[], int u, vector<bool>& visited, vector<bool>& inRecursion){
        
        visited[u] = true;
        inRecursion[u] = true;
        
        for(auto &v: adj[u]){
            if(visited[v] == false && isCycleDfs(adj, v, visited, inRecursion))
                return true;
            else if(inRecursion[v] == true)
                return true;
        }
        
        inRecursion[u] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);
        
        for(int i=0; i<V; i++){
            if(!visited[i] && isCycleDfs(adj, i, visited, inRecursion))
                return true;
        }
        return false;
    }
};
//2. Using BFS: topo sort (or kahn's algo)
