class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    
	    int n = matrix.size();
	    for(int u=0; u<n; u++){
	        for(int v=0; v<n; v++){
	            if(matrix[u][v] == -1)
	                matrix[u][v] = 1e5;
	        }
	    }
	    
	    for(int via=0; via<n; via++){
	        
	        for(int u=0; u<n; u++){
	            for(int v=0; v<n; v++){
	                
	                matrix[u][v] = min(matrix[u][v], matrix[u][via] + matrix[via][v]);
	            }
	        }
	    }


      //Negative cycle: check diagonal element
      // for(int u=0; u<n; u++){
      //   if(matrix[u][u] < 0)
      //       cout<<"Negative cycle detected!"<<endl;
      // }
	    
	    for(int u=0; u<n; u++){
	        for(int v=0; v<n; v++){
	            if(matrix[u][v] == 1e5)
	                matrix[u][v] = -1;
	        }
	    }
	}
};
