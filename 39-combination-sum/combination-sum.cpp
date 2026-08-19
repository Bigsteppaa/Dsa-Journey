class Solution {
public: void combo(int ind,vector<int>& candidates,vector<int>& temp,set<vector<int>>& ans,int k,int sum){
      if(sum>k) return;
      if(ind>=candidates.size()){
        if(sum == k) ans.insert(temp);
        return;
      }
            sum += candidates[ind];
      temp.push_back(candidates[ind]);
      combo(ind,candidates,temp,ans,k,sum);
      combo(ind+1,candidates,temp,ans,k,sum);
      sum -= candidates[ind];
       temp.pop_back();
      combo(ind+1,candidates,temp,ans,k,sum);

}


public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        set<vector<int>> ans;
      vector<int> temp;
        combo(0,candidates,temp,ans,target,0);
        vector<vector<int>> vec(ans.begin(),ans.end());
        return vec;
    }
};