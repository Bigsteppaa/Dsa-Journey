class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
  vector<vector<int>> adj(n,vector<int>(n,1e9));

    for(auto &e : edges){
        adj[e[0]][e[1]] = e[2];
        adj[e[1]][e[0]] = e[2];
    }   
    

      for(int i = 0;i<n;i++){
        adj[i][i] = 0;
      }


      for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
              if(adj[i][k] != 1e9 && adj[k][j] != 1e9){
                adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
              }



            }
        }
      }
  
       int ans = 0;
       int minn = n;
  for(int i = 0;i<n;i++){
               int cnt = 0;
            for(int j = 0;j<n;j++){
                if( i!=j && adj[i][j] <= distanceThreshold) cnt++;


            }
            if(cnt<=minn){ ans = i;
            minn = cnt;}


  } 



 return ans;}
};