class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());

         
          int i = 0;
        while(i<nums.size() && nums[i]<=0 ) i++;
        if(i>=nums.size()) return 1;
              int k = 1;
        for(int j = i;j<nums.size();j++){
            if(j>0 && nums[j] == nums[j-1]) continue;
              
            if(nums[j] != k) return k;
             k++;
           

        }
        return nums[nums.size()-1]+1 ;
    }
};