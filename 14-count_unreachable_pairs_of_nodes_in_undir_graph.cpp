//1. Using DFS
// class Solution {
// public:
//     void dfs(unordered_map<int, vector<int> >& adj, int node, long long & temp, vector<bool>& visited){

//         visited[node] = true;
//         temp++;

//         for(auto &v : adj[node]){
//             if(!visited[v])
//                 dfs(adj, v, temp, visited);
//         }
//     }

//     long long countPairs(int n, vector<vector<int>>& edges) {
//         unordered_map<int, vector<int> > adj;
//         for(auto &it : edges){
//             int u = it[0];
//             int v = it[1];

//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         vector<bool> visited(n, false);

//         long long result = 0;
//         int prev_node_count = 0;
//         for(int i=0; i<n; i++){ // may have disconnected component
//             if(!visited[i]){
//                 long long temp = 0;
//                 dfs(adj, i, temp, visited);
                
//                 result += temp * (n - temp - prev_node_count);
//                 prev_node_count += temp;
//             }
//         }

//         return result;
//     }
// };


//2. Using DSU
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

class Solution{
public:
    long long countPairs(int n, vector<vector<int>>& edges) {

        DisjointSet ds(n);

        for(auto &it: edges){
            int u = it[0];
            int v = it[1];

            if(ds.findUPar(u) != ds.findUPar(v))
                ds.unionBySize(u, v); 
        }

        //store ulp_parent and its component size
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++){
            int ulp = ds.findUPar(i);
            mp[ulp]++;
        }

        long long result = 0;
        long long remaining = 0;
        for(auto &it: mp){
            int size = it.second;

            result += size*(n - size - remaining);
            remaining += size;
        }
        return result;
    }
};
