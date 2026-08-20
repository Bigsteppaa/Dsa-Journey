class Solution {
    public: void solve(int ind,string &s,vector<string> &ans,int n){

   if(s.size() == n){
      ans.push_back(s);
      return;
   }
      if(s.size() == 0 || s.back() != '0'){
      s.push_back('0');
      solve(ind+1,s,ans,n);
       s.pop_back();
      }
      s.push_back('1');
      solve(ind+1,s,ans,n);
      s.pop_back();

    

    }
public:
    vector<string> validStrings(int n) {
 vector<string> ans;
 string s = "";
 solve(0,s,ans,n);
 return ans;
        
        
        
    }
};