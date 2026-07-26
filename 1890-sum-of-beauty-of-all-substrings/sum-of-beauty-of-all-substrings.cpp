class Solution {
public:
    int beautySum(string s) {
        
           
         int res = 0;
        for(int i = 0;i<s.size();i++){
            vector<int> freq(26,0);
            
          for(int j = i;j<s.size();j++){
             
                      freq[s[j]-'a']++;
              int mx = 0;
int mn = INT_MAX;

for(int k=0;k<26;k++){
    if(freq[k]){
        mx = max(mx,freq[k]);
        mn = min(mn,freq[k]);
    }
          }
          res += mx - mn;
          }



        }
        return res;
    }
};