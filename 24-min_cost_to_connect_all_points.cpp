//1. Using Prim's Algo
// class Solution {
// public:
//     typedef pair<int,int> P;
//     int primAlgo(int V, vector<vector<P>>& adj){

//         priority_queue<P,vector<P>,greater<P>> pq;
//         pq.push({0, 0});
//         vector<bool> inMST(V, false);
//         int sum = 0;

//         while(!pq.empty()){
//             int node = pq.top().second;
//             int dist = pq.top().first;
//             pq.pop();

//             if(inMST[node] == true)
//                 continue;
            
//             inMST[node] = true;
//             sum += dist;

//             for(auto &nbr: adj[node]){
//                 int v = nbr.first;
//                 int wt = nbr.second;
//                 if(inMST[v] == false){
//                     pq.push({wt, v});
//                 }
//             }
//         }
//         return sum;
//     }

//     int minCostConnectPoints(vector<vector<int>>& points) {
        
//         int V = points.size();
//         vector<vector<P>> adj(V);  //0 node -> {{1, dist1}, {2, dist2}, {3, dist3}...}
//         // 1 node -> {{0, dist1}, {2, dist5},..}, ....& so on. therefore, vector of vector of pair

//         for(int i=0; i<V; i++){
//             for(int j=i+1; j<V; j++){

//                 vector<int> p1 = points[i];
//                 vector<int> p2 = points[j];

//                 int u1 = p1[0];
//                 int v1 = p1[1];
//                 int u2 = p2[0];
//                 int v2 = p2[1];

//                 int dist = abs(u1-u2) + abs(v1-v2);

//                 adj[i].push_back({j, dist});
//                 adj[j].push_back({i, dist});
//             }
//         }

//         return primAlgo(V, adj);
//     }
// };

/*********************************************************************************************/
// 2. Using Kruskal's Algo

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

class Solution{
public:
    int kruskalAlgo(int V, vector<vector<int>>& adj){
        
        DisjointSet ds(V);
        int sum = 0;
        for(auto &it: adj){
            int u = it[0];
            int v = it[1];
            int dist = it[2];

            if(ds.findUPar(u) != ds.findUPar(v)){
                ds.unionBySize(u, v);
                sum += dist;
            }
        }

        return sum;
    }


    int minCostConnectPoints(vector<vector<int>>& points) {

        int V = points.size();

        vector<vector<int>> adj;

        for(int i=0; i<V; i++){
            for(int j=i+1; j<V; j++){

                vector<int> p1 = points[i];
                vector<int> p2 = points[j];

                int u1 = p1[0];
                int v1 = p1[1];
                int u2 = p2[0];
                int v2 = p2[1];

                int dist = abs(u1-u2) + abs(v1-v2);

                adj.push_back({i, j, dist});
            }
        }

        auto comp = [&](vector<int>& v1, vector<int>& v2){
            return v1[2] < v2[2];
        };
        sort(begin(adj), end(adj), comp);

        return kruskalAlgo(V, adj);
    }
};
