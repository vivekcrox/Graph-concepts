class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>> > adj;
        for(auto &it: times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        // Dijkstra's algo
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
        q.push({k, 0});
        dist[k] = 0;

        while(!q.empty()){
            int node = q.top().first;
            int dis = q.top().second;
            q.pop();


            for(auto &it : adj[node]){
                int v = it.first;
                int wt = it.second;

                if(dis + wt < dist[v]){
                    dist[v] = dis + wt;
                    q.push({v, dist[v]});
                }
            }
        }

        for(int i=1; i<=n; i++){
            if(dist[i] == INT_MAX)
                return -1;
        }

        // take max from the dist vector as our ans
        int ans = *max_element(dist.begin()+1, dist.end());

        return ans;
    }
};
