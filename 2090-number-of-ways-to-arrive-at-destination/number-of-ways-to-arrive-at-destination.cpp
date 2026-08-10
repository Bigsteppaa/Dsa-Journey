class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
 
     vector<vector<pair<int,int>>> adj(n);
     for(auto &e : roads){
        adj[e[0]].push_back({e[1],e[2]}); 
        adj[e[1]].push_back({e[0],e[2]}); 
     }   
    vector<long long> dist(n,1e18);
    vector<int> ways(n,0);

    priority_queue<pair<long long,int>,vector<pair<long long ,int>>,greater<pair<long long,int>>> pq;
 
       pq.push({0,0});
       dist[0] = 0;
       ways[0] = 1;
       int mod = (int)(1e9+7);

       while(!pq.empty()){
       
              long long  node = pq.top().second;
              long long time = pq.top().first;
              pq.pop();

              if(time>dist[node]) continue;


              for(auto it : adj[node] ){
                  int ad = it.first;
                  int nt = it.second;

                  if(dist[ad]>time+nt){
                    dist[ad] = time + nt;
                    pq.push({time+nt,ad});
                    ways[ad] = ways[node];

                  }
                  else if(dist[ad] == time+nt){
                    ways[ad] = (ways[node] + ways[ad])%mod;
                  }
                  


              }
               


       }


       return ways[n-1]%mod;   
    }
};