class Solution {
  public:
    /*  Function to implement Bellman Ford */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        
        for(int count=1; count<=V-1; count++){
            
            for(auto& it: edges){
                int u = it[0];
                int v = it[1];
                int w = it[2];
                
                if(dist[u] != 1e8 && dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }
        
        //detect negative cycle: relax one more time if change in dist[] then (-)ve cycle present.
        for(auto& it: edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            if(dist[u] != 1e8 && dist[u] + w < dist[v])
                return {-1};
        }
        
        return dist;
    }
};
