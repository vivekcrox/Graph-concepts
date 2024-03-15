class DisjointSet{
public: 
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
        
    int findUPar(int u){
        if(u == parent[u])
            return u;
        
        return parent[u] = findUPar(parent[u]);
    }
    
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if(ulp_u == ulp_v)
            return;
        
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int kruskalAlgo(int V, vector<vector<int>>& edges){
	    
	    DisjointSet ds(V);
	    int sum = 0;
	    // O(E*4*alpha)
	    for(auto &it: edges){
	        int u = it[0];
	        int v = it[1];
	        int w = it[2];
	        
	        if(ds.findUPar(u) != ds.findUPar(v)){
	            ds.unionBySize(u, v);
	            sum += w;
	        }
	    }
	    return sum;
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        vector<vector<int>> edges;
        
        // O(V+E)
        for(int u=0; u<V; u++){
            
            for(auto &it: adj[u]){
                int v = it[0];
                int w = it[1];
                
                edges.push_back({u,v,w});
            }
        }
        
        auto comp = [&](vector<int>& v1, vector<int>& v2){
            return v1[2] < v2[2];
        };
        // O(ElogE)
        sort(begin(edges), end(edges), comp); //sort w.r.t ascending wt
        
        return kruskalAlgo(V, edges);
    }
};
