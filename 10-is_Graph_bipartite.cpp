class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>& adj, int u, int curColor, vector<int>& color){

        color[u] = curColor;

        for(auto &v: adj[u]){
            if(color[v] == color[u])
                return false;
            else if(color[v] == -1 && dfs(adj, v, 1-color[u], color) == false)
                return false;

        }
        return true;
    }

    bool bfs(unordered_map<int,vector<int>>& adj, int u, int curColor, vector<int>& color){

        queue<int> q;
        q.push(u);

        color[u] = curColor;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto &v: adj[u]){
                if(color[v] == -1){
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if(color[v] == color[u])
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        unordered_map<int,vector<int>> adj;

        for(int i=0; i<n; i++){
            for(auto &it : graph[i]){
                adj[i].push_back(it);
            }
        }

        vector<int> color(n, -1);
        int curColor = 0;
        for(int i=0; i<n; i++){
            // if(color[i] == -1 && dfs(adj, i, curColor, color) == false){
            //     return false;
            // }

            if(color[i] == -1 && bfs(adj, i, curColor, color) == false)
                return false;
        }
        return true;
    }
};
