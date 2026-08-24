class Solution {



public:
    int uniquePaths(int m, int n) {
      vector<int> row(n,0);
      row[0] = 1;
      
      

        for(int i = 0;i<m;i++){
    vector<int> row1(n,0);

            for(int j = 0;j<n;j++){
       

             row1[j] = row[j];
             if(j>0) row1[j] +=row1[j-1];

            }
           
            row = row1;
        }    

    return row.back();
    
        
    }
};