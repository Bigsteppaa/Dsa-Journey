class Solution {
public:
    string longestPalindrome(string s) {
        int mx = 1;
        int st = 0;
        int end = 0;

        for(int i = 0;i<s.size();i++){
                
            for(int j = i;j<s.size();j++){
            if(palin(s,i,j)){
                if(j-i+1>mx){
                    mx = j-i+1;
                    st = i;
                    end = j;
                }

            }
            }
           
         }
       return s.substr(st,end-st+1); }


    bool palin(string &s,int l , int r){
      
       while(l<r){
        if(s[l] != s[r]) return false;
         l++;r--;
       }
        return true;
    }
};