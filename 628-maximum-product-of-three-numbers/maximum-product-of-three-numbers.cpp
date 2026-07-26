class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int mx1 = INT_MIN;
        int mx3 = INT_MIN;
         int mx2 = INT_MIN;
         
        
       
        int min1 =  INT_MAX;
        int min2 = INT_MAX;

        for( int i = 0;i<nums.size();i++){


          if(nums[i]>mx1){
               mx3 = mx2;
               mx2 = mx1;
               mx1 = nums[i];

          }
          else if(nums[i]>mx2){
             mx3 = mx2;
               mx2 = nums[i];
            
          }
          else if(nums[i]>mx3) mx3 = nums[i];


          if(nums[i]<min1){
            min2 = min1;
            min1 = nums[i];
          }
          else if(nums[i]<min2){
            min2 = nums[i];
          }





        }


        

        return max(min1*min2*mx1*1LL,mx1*mx2*mx3*1LL);
    }
};