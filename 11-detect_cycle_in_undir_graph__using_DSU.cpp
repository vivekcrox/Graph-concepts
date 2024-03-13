class DisjointSet{
public: 
    vector<int> rank, parent, size;

    DisjointSet(int n){
        rank.resize(n+1, 0);   //n+1 -> so that can handle both 0 and 1 base indexing graph.
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node){   // find Ultimate parent of the node.
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);  // Path Compression -> by storing the parent[node];
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return ;   // already connected to same component.
        if(rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if(rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else{ //when rank same then add to anyone.
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return ;   // already connected to same component.
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{ // in case of rank(u) > rank(v) or equal.
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    
	    DisjointSet ds(V);
	    
	    for(int u=0; u<V; u++){
	        for(auto &v: adj[u]){
	            
	            if(u < v){   //check only 1 time same edge: (i.e 0 -> 1 & not 1 -> 0 as already checked)
	                
	                int u_par = ds.findUPar(u);
	                int v_par = ds.findUPar(v);
	                
	                if(u_par == v_par)
	                    return true;
	                   
	                ds.unionBySize(u_par, v_par);
	            }
	        }
	    }
	    return false;
	}
};
