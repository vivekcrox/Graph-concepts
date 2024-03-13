// Detect cycle using BFS (Kahn's algo)
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V, 0);
	    
	    for(int i=0; i<V; i++){
	        for(auto &v: adj[i]){
	            indegree[v]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0; i<V; i++){
	        if(indegree[i] == 0){
	           q.push(i);
	        }
	    }
	    
	    vector<int> result;
	    while(!q.empty()){
	        int u = q.front();
	        q.pop();
	        
	        result.push_back(u);
	        
	        for(auto &v : adj[u]){
	            indegree[v]--;
	            if(indegree[v] == 0)
	                q.push(v);
	        }
	    }
	    
	    if(result.size() != V)
	        return {};
	    
	    return result;
	}
};
