class Solution {
public:
    string smallestPalindrome(string s) {

        vector<int> freq(26,0);

        for(auto it : s) freq[it -'a']++;

        string l = "";
            char mid = 0;
        for(int i = 0;i<26;i++){

            
                  if(freq[i]%2) mid = i + 'a';
                l.append((freq[i])/2,i+'a');
                
            

        }
        string r = l;
        reverse(r.begin(),r.end());

        
       


       return l + ( mid?string(1,mid):"" ) + r;
    }
};