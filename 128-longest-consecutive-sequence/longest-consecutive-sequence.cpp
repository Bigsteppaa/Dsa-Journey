class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        if(nums.size() == 0) return 0;
    int count = 1;
    int mx = 1;
    for(int i = 1;i<nums.size();i++){
       if(nums[i] == nums[i-1]) continue;

        if(nums[i]-1 == nums[i-1]){
               count++;
               mx = max(count,mx);

               }
               else count = 1;
    }


     return mx;   
    }
};