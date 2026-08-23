class Solution {

public: int rob1(vector<int>& nums) {
        
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


public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
      vector<int> temp(nums.size()-1),temp1(nums.size()-1);
         
        for(int i = 0;i<nums.size();i++){
           if(i != 0) temp.push_back(nums[i]);
             if(i != nums.size()-1) temp1.push_back(nums[i]);
        }

        return max(rob1(temp),rob1(temp1));
    }
};