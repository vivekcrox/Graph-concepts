// DSU
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
    bool equationsPossible(vector<string>& equations) {
        
        DisjointSet ds(26);

        for(auto &it: equations){
            char op = it[1];
            int x = it[0]-'a';
            int y = it[3]-'a';

            if(op == '=' && ds.findUPar(x) != ds.findUPar(y))
                ds.unionBySize(x, y);
        }

        for(auto &it: equations){
            char op = it[1];
            int x = it[0]-'a';
            int y = it[3]-'a';

            if(op == '!' && ds.findUPar(x) == ds.findUPar(y))
                return false;
        }
        return true;
    }
};
