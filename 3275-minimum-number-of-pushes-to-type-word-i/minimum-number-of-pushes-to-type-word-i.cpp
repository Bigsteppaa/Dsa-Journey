class Solution {
public:
    int minimumPushes(string word) {

        int freq[26] = {0};

        for(auto it : word){

            freq[it -'a']++;
        }

        int ans = 0;

             int cnt = 0;
             int mul = 1;
             int buc = 0;
        for(int i = 0;i<26;i++){
            if(freq[i]){
                cnt++;
                buc += freq[i];
            }

            if(cnt==8){
                ans += buc*mul;
                mul++;
                cnt = 0;
                buc = 0;

            }
            
        }
        if(cnt) ans += buc*mul;



       return ans; 
    }
};