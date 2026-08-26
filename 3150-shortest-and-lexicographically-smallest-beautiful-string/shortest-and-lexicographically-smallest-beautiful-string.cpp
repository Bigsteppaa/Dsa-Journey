class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {


        int l = 0;
        int r = 0;
        int one = 0;

       

           int size = INT_MAX;
           int  ind = -1;
       while(r<s.size()){
        if(s[r] == '1') one++;
        
         while(one == k){
            if(r-l+1<size){
                size = r-l+1;
                ind = l;
            }
            else if(size == r-l+1 && s.substr(ind,size)>s.substr(l,size)){
                ind = l;

            }

            if(s[l] == '1') one--;
             l++;

         }


         
         r++;
       }


         if(ind == -1) return "";

        return s.substr(ind,size);
    }
};