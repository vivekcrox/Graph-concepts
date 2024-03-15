class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	// Given adjacency list adj as input parameters . Here adj[i] contains vectors of size 2, where the first integer 
	// in that vector denotes the end of the edge and the second integer denotes the edge weight.
	typedef pair<int,int> P;
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        priority_queue<P,vector<P>,greater<P>> pq;  //can also maintain parent[]
        vector<bool> inMST(V, false);
        
        pq.push({0, 0});
        int sum = 0;
        
        while(!pq.empty()){
            auto P = pq.top();
            pq.pop();
            
            int node = P.second;
            int wt = P.first;
            
            if(inMST[node] == true)
                continue;
            
            inMST[node] = true;
            sum += wt;
            
            for(auto &nbr: adj[node]){
                int v = nbr[0];
                int w = nbr[1];
                
                if(inMST[v] == false)
                    pq.push({w, v});
            }
        }
        return sum;
    }
};
