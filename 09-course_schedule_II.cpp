// Using DFS : cycle detection + Topological sort
// Can also done by BFS (kahn's algo)
class Solution {
public:
    bool hasCycle = false;
    void dfs(unordered_map<int,vector<int>>& adj, int u, vector<bool>& visited, stack<int>& st, vector<bool>& inRecursion){

        visited[u] = true;
        inRecursion[u] = true;

        for(auto &v: adj[u]){
            if(!visited[v])
                dfs(adj, v, visited, st, inRecursion);
            
            else if(inRecursion[v] == true)
                hasCycle = true;
        }

        st.push(u);
        inRecursion[u] = false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = numCourses;
        unordered_map<int,vector<int>> adj;
        for(auto &it: prerequisites){
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
        }

        stack<int> st;
        vector<bool> visited(n, false);
        vector<bool> inRecursion(n, false);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(adj, i, visited, st, inRecursion);
            }
        }

        if(hasCycle == true)
            return {};
        
        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};
