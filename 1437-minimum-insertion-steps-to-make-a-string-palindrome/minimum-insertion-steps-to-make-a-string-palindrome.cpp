class Solution {
public:
    int minInsertions(string s) {
        string s1 = s;
        reverse(s1.begin(),s1.end());

  int n = s1.size();
   
  vector<int> prev(s1.size()+1,0),curr(s1.size()+1,0);
   


     for(int ind1 = 1;ind1<=n;ind1++){
        for(int ind2 = 1;ind2<=n;ind2++){

if(s[ind1-1] == s1[ind2-1]) curr[ind2] = 1 + prev[ind2-1];
   else curr[ind2] = max(prev[ind2],curr[ind2-1]);

        }

        prev = curr;
     }

    

        
           
        return n-prev[n];

        
        
    }
};