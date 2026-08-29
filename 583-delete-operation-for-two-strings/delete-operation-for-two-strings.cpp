class Solution {
public:
    int minDistance(string word1, string word2) {
        
        
        
  int m = word1.size();
  int n = word2.size();
   
  vector<int> prev(word2.size()+1,0),curr(word2.size()+1,0);
   


     for(int ind1 = 1;ind1<=m;ind1++){
        for(int ind2 = 1;ind2<=n;ind2++){

if(word1[ind1-1] == word2[ind2-1]) curr[ind2] = 1 + prev[ind2-1];
   else curr[ind2] = max(prev[ind2],curr[ind2-1]);

        }

        prev = curr;
     }

    

        
           
        return (n-prev[n]) + (m-prev[n]);

        
        
    }
};