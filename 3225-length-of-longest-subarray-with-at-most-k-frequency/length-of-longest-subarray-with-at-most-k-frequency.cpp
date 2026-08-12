class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
           unordered_map<int,int> mp;


        int l = 0;
        int r = 0;
        int ans = 1;
         while(r<nums.size()){
               
                
             if(mp[nums[r]]<=k){
                  mp[nums[r]]++;
                  ans = max(ans,r-l+1);
                 r++;


             }
             
                   while( r < nums.size() && mp[nums[r]]>=k){
                    mp[nums[l]]--;
                    l++;
                   }
             
         }
         

            

         
        return ans;
    }
};