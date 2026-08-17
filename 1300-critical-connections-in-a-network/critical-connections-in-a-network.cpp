
class Solution {
public: int time = 1;

void dfs(int node,int parent,vector<vector<int>> &adj,vector<int> &vis, vector<int> &tin,vector<int> &low,vector<vector<int>> &ans){

  vis[node] = 1;
  low[node] = tin[node] = time;
  time++;

  for(auto it : adj[node]){
    if(it == parent) continue;
   
   if(!vis[it]){
       dfs(it,node,adj,vis,tin,low,ans);
       low[node] = min(low[node],low[it]);

       if(low[it]>tin[node]) ans.push_back({it,node}); 
     
   }
   else{
    low[node] = min(low[node],low[it]);

   }



  } 







}




public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

         vector<vector<int>> adj(n);
        for(auto &e :connections){
                 adj[e[0]].push_back(e[1]);
                   adj[e[1]].push_back(e[0]);
        }
         vector<int> vis(n,0);
        vector<int> tin(n);
         vector<int> low(n);
         vector<vector<int>> ans;

        dfs(0,-1,adj,vis,tin,low,ans);

     return ans;
        
    }
};