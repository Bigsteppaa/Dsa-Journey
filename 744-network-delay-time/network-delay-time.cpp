class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

  vector<vector<pair<int,int>>> adj(n+1);
  for(auto &e : times){
    adj[e[0]].push_back({e[1],e[2]});
         
  }
  vector<int> dist(n+1,1e9);

      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>  pq;
         pq.push({0,k});
         dist[0] = 0;
         dist[k] = 0;

         while(!pq.empty()){
            auto it = pq.top();
             int node = it.second;
             int tm = it.first;
                    pq.pop();

         for(auto i : adj[node]){

              int adjj = i.first;
              int wt = i.second;

              if(dist[adjj]>tm+wt) {
                dist[adjj] = tm+wt;
                pq.push({tm+wt,adjj});
              }

         }



         }

         int mx = 0;
       for(auto it : dist){
        if(it == 1e9) return -1;
        mx = max(mx,it);

       }

       return mx; 
    }
};