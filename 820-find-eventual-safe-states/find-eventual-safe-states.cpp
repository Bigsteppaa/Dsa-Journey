class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

     vector<vector<int>> adj(graph.size());

        vector<int> indeg(graph.size(),0);

       for(int i = 0;i<graph.size();i++){
         for(auto it : graph[i]){
             adj[it].push_back(i);
                indeg[i]++;
         }
           }

           queue<int> q;
            for(int i = 0;i<graph.size();i++){
                if(!indeg[i]) q.push(i);
            }

            vector<int> ans;

            while(!q.empty()){
               int node =  q.front();
               q.pop();
               ans.push_back(node);
               for(auto it : adj[node]){
                        indeg[it]--;
                        if(!indeg[it]) q.push(it);
               }

            }

           sort(ans.begin(),ans.end());

           return ans;
        
    }
};