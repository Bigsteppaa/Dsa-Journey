class Solution {
public:
    int smallestNumber(int n, int t) {
        if(!t) return n;
        if(n<=t) return t;
        
        

        while(true){
                    int mul = 1;
        string s = to_string(n);
        for(auto it : s){
            mul *= (it-'0');  
        }
         if(mul%t == 0) return n;
            n++;
        }
        return n;
        
    }
};