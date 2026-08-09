class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
     vector<vector<pair<int,int>>> adj(n);

     for(auto &e : flights){
        adj[e[0]].push_back({e[1],e[2]});
     }

     vector<int> dist(n,1e9);
     dist[src] = 0;
     queue<pair<int,pair<int,int>>> q;
     q.push({0,{0,src}});

      while(!q.empty()){
            auto it = q.front();
            q.pop();
            int steps = it.first;
            if(steps>k) continue;
            int ds = it.second.first;
            int node = it.second.second;

           for(auto it : adj[node]){
                 int w = it.second;
                 int adj = it.first;

                 if(dist[adj]>ds+w && steps<=k){
                    dist[adj] = ds + w;
                    q.push({steps+1,{ds+w,adj}});
                 }

               
               }
           }



           

      

       if(dist[dst] == 1e9) return -1;


return dist[dst];
    }
};