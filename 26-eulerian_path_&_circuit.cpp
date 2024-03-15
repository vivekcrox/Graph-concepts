class Solution {
public:
    void DFS(vector<int> adj[], int node, vector<bool>& visited){
        visited[node] = true;
        
        for(auto it=adj[node].begin(); it!=adj[node].end(); it++){
            int v = *it;
            if(!visited[v])
                DFS(adj, v, visited);
        }
    }

    bool isConnected(int V, vector<int> adj[]){
        
        int nonZeroDegreeVertex = -1;
        for(int i=0; i<V; i++){
            if(adj[i].size() != 0){
                nonZeroDegreeVertex = i;
                break;
            }
        }
        
        vector<bool> visited(V, false);
        //start DFS from nonZeroDegreeVertex
        DFS(adj, nonZeroDegreeVertex, visited);
        
        //check if all non-zero degree wale vertices are visited
        for(int i=0; i<V; i++){
            if(visited[i] == false && adj[i].size() > 0)
                return false;
        }
        return true;
    }

	int isEulerCircuit(int V, vector<int>adj[]){
	    // check connected h ya nhi
	    if(isConnected(V, adj) == false)
	        return 0;  // neither EP nor EC
	        
	   // Count odd degree wle vertices
	   int oddDegreeCount = 0;
	   for(int i=0; i<V; i++){
	       if(adj[i].size() % 2 != 0)
	            oddDegreeCount++;
	   }
	   
	   if(oddDegreeCount > 2)
	        return 0;   // neither EP nor EC
	   
	   if(oddDegreeCount == 2)
	        return 1;  // EP
	   
	   return 2;  // EC
	}
};
