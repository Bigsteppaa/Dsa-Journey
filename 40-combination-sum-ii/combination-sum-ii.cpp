class Solution {

  public:
  void combo(int ind,vector<int>& arr,vector<int>& temp,
  vector<vector<int>>& ans,int target){
    if(target == 0){
        ans.push_back(temp);
        return;
    }
    
    for(int i = ind;i<arr.size();i++){
        if(arr[i]>target) break;
        if(i>ind && arr[i] == arr[i-1]) continue;
        
        
        temp.push_back(arr[i]);
        combo(i+1,arr,temp,ans,target-arr[i]);
       temp.pop_back();
    }





  }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

     vector<vector<int>> ans;
     vector<int> temp;
        sort(candidates.begin(),candidates.end());
     combo(0,candidates,temp,ans,target);
    

     return ans;   
    }
};