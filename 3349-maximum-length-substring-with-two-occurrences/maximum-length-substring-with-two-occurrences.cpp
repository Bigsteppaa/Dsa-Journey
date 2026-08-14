class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> hash(26,0);

        int l = 0;
        int r = 0;
        int ans = 1;
        while(r<s.size()){
           hash[s[r]-'a']++;

           while(hash[s[r]-'a']>2){
            hash[s[l]-'a']--;
            l++;

           }
            ans = max(ans,r-l+1);
            r++;



        }
      return ans;  
    }
};