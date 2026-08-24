class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        if(obstacleGrid[0][0]) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> row(n,0);
          row[0] = 1;
       
        for(int i = 0;i<m;i++){
            vector<int> row1(n,0);
            for(int j = 0;j<n;j++){

                if(obstacleGrid[i][j]) continue;
            
              row1[j] =  row[j];

              if(j>0) row1[j]  += row1[j-1];



            }
            row = row1;
        }    

    return row[n-1];
        
    }
};