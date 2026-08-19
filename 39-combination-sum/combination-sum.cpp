class Solution {
public: void combo(int ind,vector<int>& candidates,vector<int>& temp,vector<vector<int>>& ans,int k){
      if( k == 0) {
        ans.push_back(temp);
        return;}
      

      for(int i = ind;i<candidates.size();i++){
         if(candidates[i]>k) break;

         temp.push_back(candidates[i]);
         combo(i,candidates,temp,ans,k-candidates[i]);

         temp.pop_back();
      }
            
    

}


public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

         vector<vector<int>> ans;
      vector<int> temp;
         sort(candidates.begin(),candidates.end());
        combo(0,candidates,temp,ans,target);
       
        return ans;
    }
};