/********** Using BFS ************/
class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> directions{{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // int n = grid.size();
        // queue<P> q;
        // q.push({1, {0,0}});

        // vector<vector<int>> visited(n, vector<int>(n, 0));
        // visited[0][0] = 1;

        // if(grid[0][0] != 0)
        //     return -1;

        // while(!q.empty()){
        //     auto it = q.front();
        //     int dis = it.first;
        //     int row = it.second.first;
        //     int col = it.second.second;
        //     q.pop();

        //     if(row == n-1 && col == n-1){
        //         return dis;
        //     }

        //     for(auto &dir : directions){
        //         int nr = dir[0] + row;
        //         int nc = dir[1] + col;

        //         if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] == 0 && !visited[nr][nc]){
        //             q.push({dis+1, {nr, nc}});
        //             visited[nr][nc] = 1;
        //         }
        //     }
        // }
        // return -1;


        /****************************************/
        //2. Using Dijkstra' algo in 2D - no need of visited matrix (as dist[][] is enough)

        int n = grid.size();

        if(grid[0][0] != 0)
            return -1;

        priority_queue<P,vector<P>,greater<P>> pq;

        pq.push({1,{0,0}});

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 1;

        while(!pq.empty()){
            int d = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for(auto &dir: directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(x_<0 || x_>=n || y_<0 || y_>=n)
                    continue;
                
                if(grid[x_][y_] == 0 && dist[x][y] + 1 < dist[x_][y_]){
                    dist[x_][y_] = 1 + dist[x][y];
                    pq.push({dist[x_][y_], {x_, y_}});
                }
            }
        }
        return dist[n-1][n-1]==INT_MAX ? -1 : dist[n-1][n-1];
    }
};
