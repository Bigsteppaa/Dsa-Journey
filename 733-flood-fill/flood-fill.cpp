class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

      
       queue<pair<int,int>> q;
      q.push({sr,sc});
      int org = image[sr][sc];
      if(org == color) return image;
      image[sr][sc] = color;
               


       int drow[] = {-1,0,+1,0};
       int dcol[] = {0,-1,0,+1};
      

       while(!q.empty()){

          int r = q.front().first;
           int c = q.front().second;
            
             q.pop();
            
             for(int i = 0;i<4;i++){
                 int nr = r + drow[i];
                 int nc = c + dcol[i];
                 if(nr>= 0 && nr<n && nc>= 0 && nc<m && image[nr][nc] == org){
                    q.push({nr,nc});
                    image[nr][nc] = color;
                    

                 }

             }




       }
       
     return image;
        
    }
};