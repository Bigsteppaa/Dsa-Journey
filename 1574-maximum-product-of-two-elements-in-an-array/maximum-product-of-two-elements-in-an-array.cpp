class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int mx1 = max(nums[0],nums[1]);
        int mx2 = min(nums[0],nums[1]);
        for(int i = 2;i<nums.size();i++){

 
         
         if(mx1<=nums[i]){ mx2 = mx1;  mx1 = nums[i];}
         else{
            mx2 = max(mx2,nums[i]);
         }

          
        }
        return (mx1-1)*(mx2-1);
    }
};