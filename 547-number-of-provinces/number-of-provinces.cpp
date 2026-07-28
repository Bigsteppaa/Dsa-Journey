class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        

           int n = isConnected.size();
           vector<int> adj[n];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                   
                } }
        }


                vector<int> vis(n,0);
                int ans = 0;
                

                for(int i = 0;i<n;i++){
                if(!vis[i]){
                    queue<int> q;
                q.push(i);
                vis[i] = 1;
                while(!q.empty()){

               int node = q.front(); q.pop();
              
                  for(auto it : adj[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it] = 1;
                       
                    }
                  }
                  



                }

                ans++;}
                }
    return ans;    
    }
};