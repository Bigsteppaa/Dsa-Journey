class Solution {

 private:
    bool dfs(int node,vector<vector<int>>& graph,vector<int>& color,int cl){
         
                color[node] = cl;
             for(auto it : graph[node]){
              if(color[it] == -1){
                if(!dfs(it,graph,color,!cl)) return false;}
              else if(color[it] == cl) return false;

             }
             
          return true;
    }

public: 
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> color(n,-1);

        for(int i = 0;i<n;i++){
          if(color[i] == -1){
            color[i] = 0;
             if(!dfs(i,graph,color,0)) return false;

          }
        }


      return true;
    }
};