class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void dfsFill(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st){
	    
	    visited[node] = true;
	    
	    for(auto& v: adj[node]){
	        if(!visited[v])
	            dfsFill(v, adj, visited, st);
	    }
	    st.push(node);
	}
	
	void dfsTraversal(int node, vector<vector<int>>& revAdj, vector<bool>& visited){
	    
	    visited[node] = true;
	    
	    for(auto &v: revAdj[node]){
	        if(!visited[v])
	            dfsTraversal(v, revAdj, visited);
	    }
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        
        //1. store topo order
        stack<int> st;
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++){
            if(!visited[i])
                dfsFill(i, adj, visited, st);
        }
        
        //2. reverse edges
        vector<vector<int>> revAdj(V);
        for(int u=0; u<V; u++){
            for(auto &v: adj[u]){
                revAdj[v].push_back(u);
            }
        }
        
        //3. count scc in topo sort
        visited = vector<bool>(V, false);
        int scc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                scc++;
                dfsTraversal(node, revAdj, visited);
            }
        }
        return scc;
        
    }
};
