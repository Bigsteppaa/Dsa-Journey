class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
         int n = nums.size();
        int sum  = 0;
       for(auto it : nums) sum += it;
       
       if((sum - target)<0 || (sum-target)%2) return false;
       sum = (sum-target)/2;
       
       vector<int> dp(sum+1,0),curr(sum+1,0);
       
       if(nums[0] == 0) dp[0] = 2;
       else dp[0] = 1;
       
       if(nums[0] <= sum && nums[0] != 0) dp[nums[0]] = 1;
       
       for(int i = 1;i<n;i++){
           
           for(int j = 0;j<=sum;j++){
                int npick  = dp[j];
          int pick = 0;
       
       if(nums[i]<=j) pick = dp[j-nums[i]];
        
               
               
               
               curr[j] = pick + npick;
               
               
               
           }
           
           dp = curr;
           
       }
       
       
       
        return dp[sum];
        
    }
};