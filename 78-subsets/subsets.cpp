class Solution {

public: 
void subset(int ind,vector<int>& nums,vector<vector<int>>& ans,vector<int>& ds){

   ans.push_back(ds);

  for(int i = ind;i<nums.size();i++){

    ds.push_back(nums[i]);
    subset(i+1,nums,ans,ds);
       ds.pop_back();

  }



}

public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> ds;
        vector<vector<int>> ans;
        

      subset(0,nums,ans,ds);
        return ans;
    }
};