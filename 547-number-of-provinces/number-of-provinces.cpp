class Solution {
    private: 
    void dfs(int node,vector<vector<int>>& adjm,vector<int>& vis){
         vis[node] = 1;
         for(int i = 0;i<vis.size();i++)
            if(adjm[node][i] == 1 && !vis[i]) 
                                 dfs(i,adjm,vis);

    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> vis(isConnected.size(),0);
        int ans = 0;
        for(int i = 0;i<isConnected.size();i++){
            if(!vis[i]){
                dfs(i,isConnected,vis);
                ans++;
            }

        }
     return ans;   
    }
};