class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        for(auto &e : prerequisites){
            adj[e[1]].push_back(e[0]);
              indegree[e[0]]++;

        }
         for(int i = 0;i<numCourses;i++){
            if(!indegree[i]) q.push(i);
         }

         vector<int> ans;

         while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(!indegree[it]) q.push(it);
            }

         }
        
                 
       if(ans.size()==numCourses) return ans;

      return {};
        
    }
};