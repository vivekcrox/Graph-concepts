class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    typedef pair<int,int> P;
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V, INT_MAX);
        
        priority_queue<P,vector<P>,greater<P>> pq;  //minHeap
        
        pq.push({0, S});
        dist[S] = 0;
        
        while(!pq.empty()){
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            for(auto &it: adj[u]){
                int v = it[0];
                int wt = it[1];
                if(d + wt < dist[v]){
                    dist[v] = d + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
        
    }
};

int main(){
    
    int t;
    cin>>t;
    
    while(t--){
        int V, E;
        cin>>V>>E;
        
        vector<vector<int>> adj[V
        int i = 0;
        while(i++ < E){
            int u, v, w;
            cin>>u>>v>>w;
            
            vector<int> t1, t2;
            
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        int S;
        cin>>S;
        
        Solution obj;
        
        vector<int> ans = obj.dijkstra(V, adj, S);
        
        for(int i=0; i<V; i++){
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}


/*******************************/
//2. Using set
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    typedef pair<int,int> P;
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V, INT_MAX);
        
        set<P> st;
        
        st.insert({0, S});
        dist[S] = 0;
        
        while(!st.empty()){
            auto &it = *st.begin();
            int u = it.second;
            int d = it.first;
            st.erase(it);
            
            for(auto &it: adj[u]){
                int v = it[0];
                int wt = it[1];
                if(d + wt < dist[v]){
                    
                    if(dist[v] != INT_MAX){
                        st.erase({dist[v], v});
                    }
                    dist[v] = d + wt;
                    st.insert({dist[v], v});
                }
            }
        }
        return dist;
        
    }
};
