class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if(nums.size() == 1) return nums;

        sort(nums.begin(),nums.end());
                 vector<int> ans;
                 int j = 1;
        for(int i = nums[0]+1;i<nums[nums.size()-1];i++){
         if(i != nums[j]) ans.push_back(i);
         else j++;



        }
return ans;
    }
};