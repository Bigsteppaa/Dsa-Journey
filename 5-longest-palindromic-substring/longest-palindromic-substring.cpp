class Solution {
public:
    string longestPalindrome(string s) {
       int st = 0;
       
       int mx = 1;
        for(int i = 0;i<s.size();i++){
            int l = i-1;
            int r = i+1;
              
            while(l>=0 && r<s.size()){
                   if(s[l] != s[r]) break;
                   if(r-l+1>mx){
                    mx = r-l+1;
                    st = l;
                   }

                 l--;
                 r++;
            }
             l = i;
             r = i+1;

            while(l>=0 && r<s.size()){
                   if(s[l] != s[r]) break;
                   if(r-l+1>mx){
                    mx = r-l+1;
                    st = l;
                   }

                 l--;
                 r++;
            }



        }
      return s.substr(st,mx);  
    }
};