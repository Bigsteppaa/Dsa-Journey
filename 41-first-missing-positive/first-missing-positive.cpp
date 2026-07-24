class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
          long long mx = -1;
           unordered_map<int,int> mp;
        for(auto it : nums) { if(it>mx) mx = it;
        mp[it] = 1;
       
        }
        if(mx<1) return 1;

        


        for(int i = 1;i<=mx+1;i++){
            if(!mp[i]) return i;

        }



      return 1;  
    }
};