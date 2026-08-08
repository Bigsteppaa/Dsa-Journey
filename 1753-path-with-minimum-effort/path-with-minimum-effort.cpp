class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

   vector<vector<int>> diff(n,vector<int>(m,1e9));

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    

    pq.push({0,{0,0}});
     
    diff[0][0] = 0;

    int drow[] = {-1,0,+1,0};
    int dcol[] = {0,-1,0,+1};

    while(!pq.empty()){
         auto it = pq.top();
           pq.pop();
          int r = it.second.first;
          int c = it.second.second;
          int dif = it.first;

          for(int i = 0;i<4;i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m   ){
                
              int ndif = max(dif,abs(heights[r][c]-heights[nr][nc]));
              if(ndif<diff[nr][nc]){
                  diff[nr][nc] = ndif;
                
                   pq.push( {diff[nr][nc],{nr,nc}});
                   
              }
            }
          }


    } 


      

   return diff[n-1][m-1];
        
    }
};