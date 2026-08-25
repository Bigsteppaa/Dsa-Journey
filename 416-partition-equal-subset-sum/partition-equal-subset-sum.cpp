class Solution {
public:
    bool canPartition(vector<int>& nums) {
     int sum = 0;
     for(auto it : nums) sum += it;
     if(sum%2) return false;
     sum = sum/2;

     vector<bool> dp(sum+1,false),curr(sum+1,false);
       dp[0] = true;
       curr[0] = true;
       
         int n = nums.size();
        
        
        
        for(int i = 1;i<n;i++){
            for(int j = 1;j<=sum;j++ ){
                
            bool npick = dp[j];
            bool pick = false;
            if(nums[i]<=j) pick = dp[j-nums[i]];
                
             curr[j] = npick | pick;        
                
            }
            dp = curr;
        }
        
        
        
        
        
        
        return dp[sum];
        




        
    }
};