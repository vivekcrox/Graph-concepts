//Dijkstra's algo on 2D
class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> directions{{-1,0},{0,1},{1,0},{0,-1}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        auto isSafe = [&](int x, int y){
            return x>=0 && x<n && y>=0 && y<m;
        };

        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0, {0,0}});

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        while(!pq.empty()){
            int cur_effort = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == n-1 && y == m-1)
                return cur_effort;  //iske baad badi val hi milegi as stored in minHeap

            for(auto &dir: directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(isSafe(x_, y_)){
                    int maxDiff = max(cur_effort, abs(heights[x][y] - heights[x_][y_]));

                    if(dist[x_][y_] > maxDiff){
                        dist[x_][y_] = maxDiff;
                        pq.push({dist[x_][y_], {x_, y_}});
                    }
                }
            }
        }
        return -1;
    }
};
