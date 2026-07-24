class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
       
        int ans = nums[0]+nums[1]+nums[2];
    

        for(int i = 0;i<nums.size();i++){
            int l = i+1; int r = nums.size()-1;
                   int sum = 0;
            while(l<r){

                 sum = nums[i]+nums[r]+nums[l];
                if(abs(sum-target)<abs(ans-target)) ans = sum;
               if(sum>target) r--;
               else if(sum<target) l++;
               else return target;
               
            }

        }
      return ans;   
    }
};