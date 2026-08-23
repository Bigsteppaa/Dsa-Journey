class Solution {

public:
    int rob(vector<int>& nums) {
        
                int prev2 = nums[0];
                 int prev1 = 0; 
            for(int i = 1;i<nums.size();i++){

             int pick = nums[i] + prev1;     
                int not_pick =  + prev2;
                prev1 = prev2;
          prev2  = max(pick,not_pick);

            }

        return prev2;
        
    }
};