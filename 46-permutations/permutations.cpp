class Solution {
public: void permu(int ind,vector<int>& nums,vector<vector<int>> &ans,vector<int>& hash,vector<int>& ds){

  if(ds.size() == nums.size()){
    ans.push_back(ds);
    return;
  }
     
   for(int i = 0;i<nums.size();i++){

    if(!hash[i]){
               hash[i] = !hash[i];
               ds.push_back(nums[i]);
              permu(i+1,nums,ans,hash,ds);
              hash[i] = !hash[i];
              ds.pop_back();

    }


   }





}


public:
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> ans;
         vector<int> ds;
         vector<int> hash(nums.size(),0);
        permu(0,nums,ans,hash,ds);
        return ans;
        
    }
};