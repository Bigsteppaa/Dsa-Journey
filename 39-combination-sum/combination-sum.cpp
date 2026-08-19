class Solution {
public: void combo(int ind,vector<int>& candidates,vector<int>& temp,vector<vector<int>>& ans,int k,int sum){
      if(sum>k) return;
      if(ind>=candidates.size()){
        if(sum == k) ans.push_back(temp);
        return;
      }
            
      temp.push_back(candidates[ind]);
      combo(ind,candidates,temp,ans,k,sum+candidates[ind]);
      
       temp.pop_back();
      combo(ind+1,candidates,temp,ans,k,sum);
     
   

}


public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

         vector<vector<int>> ans;
      vector<int> temp;
        combo(0,candidates,temp,ans,target,0);
       
        return ans;
    }
};