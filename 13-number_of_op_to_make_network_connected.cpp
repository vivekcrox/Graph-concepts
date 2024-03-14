class DisjointSet{
public:
    vector<int> parent, rank, size;

    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1);

        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node){
        if(parent[node] == node)
            return node;
        
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v)
            return ;
    
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v)
            return ;
        
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

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < (n-1))
            return -1;

        DisjointSet ds(n);

        int component = n;

        for(auto &it: connections){
            int u = it[0];
            int v = it[1];

            if(ds.findUPar(u) != ds.findUPar(v)){
                ds.unionBySize(u, v);
                component--;
            }
        }

        return component-1;


        // DisjointSet ds(n);
        // int extraEdge = 0;

        // for(auto &it: connections){
        //     int u = it[0];
        //     int v = it[1];

        //     if(ds.findUPar(u) != ds.findUPar(v)){
        //         ds.unionBySize(u, v);
        //     }
        //     else{
        //         extraEdge++;
        //     }
        // }

        // int nC = 0;
        // for(int i=0; i<n; i++){
        //     if(ds.parent[i] == i)
        //         nC++;
        // }
        // int ans = nC - 1;
        
        // return extraEdge >= ans ? ans : -1;
    }
};
