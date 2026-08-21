class Solution {
  
  public: void solve(int n,int open,int close,string &s,vector<string> &ans){

 if(open > n || close > n) return;

    if(open == n && close == n){
    ans.push_back(s);
    return;} 

   if(s.size() != 0 && open>close){
           s.push_back(')');       
           solve(n,open,close+1,s,ans);
           s.pop_back();       
   }
          s.push_back('(');
          solve(n,open+1,close,s,ans);
           s.pop_back();
  } 




public:
    vector<string> generateParenthesis(int n) {
            string s;
           vector<string> ans; 
        solve(n,0,0,s,ans);
        return ans;
        
    }
};