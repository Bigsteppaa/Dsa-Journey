class Solution {

 public: void combo(int ind,int k,int target,vector<vector<int>> &ans,vector<int> &ds ){
    if(ds.size()>k) return;
   if(ds.size() == k && target == 0){
    ans.push_back(ds);
    return;
   }

   for(int i = ind;i<=9;i++){
        if(i>target) break;
    ds.push_back(i);
    combo(i+1,k,target-i,ans,ds);
       ds.pop_back();

   }





 }







public:
    vector<vector<int>> combinationSum3(int k, int n) {
           vector<int> ds;
           vector<vector<int>> ans;

        combo(1,k,n,ans,ds);
        return  ans;
        
    }
};