class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	void dfs(vector<int> adj[], int u, vector<bool>& visited, stack<int>& st){
	    
	    visited[u] = true;
	    
	    for(auto &v: adj[u]){
	        if(!visited[v])
	            dfs(adj, v, visited, st);
	    }
	    
	    st.push(u);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    
	    vector<bool> visited(V, false);
	    stack<int> st;
	    for(int i=0; i<V; i++){
	        if(!visited[i])
	            dfs(adj, i, visited, st);
	    }
	    
	    vector<int> result;
	    while(!st.empty()){
	        result.push_back(st.top());
	        st.pop();
	    }
	    return result;
	}
};
