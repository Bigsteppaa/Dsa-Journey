class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

  vector<vector<int>> dp(str1.size()+1,vector<int>(str2.size()+1,0));
     int n = str1.size();
     int m = str2.size();


     for(int ind1 = 1;ind1<=n;ind1++){
        for(int ind2 = 1;ind2<=m;ind2++){

if(str1[ind1-1] == str2[ind2-1]) dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
   else dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);

        }
     }

     
    

     int len = n+m-dp[n][m];

     string ans(len, '$');


     len--;
    int i = n;
     int j = m;

     while(i>0 && j>0 ){

        if(str1[i-1] == str2[j-1]){
            ans[len] = str1[i-1];
             len--;
             i--;
             j--;
        } 
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                ans[len] = str1[i-1];
                i--;
                len--;

            }
            else{
                ans[len] = str2[j-1];
                j--;
                len--;

            }
          
        }


     }


     while(i>0) {
        ans[len] = str1[i-1];
        i--;
        len--;

     }
     while(j>0) {
        ans[len] = str2[j-1];
        j--;
        len--;
        
     }



      return ans;  
    }
};