class Solution {
  bool isPal(int st,string &s,int end){
   while(st<end){
    if(s[st++] != s[end--]) return false;
   }
   return true;
  }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
          vector<string> path;
          solve(0,s,ans,path);
          return ans;
      
        
    }


  public: void solve(int ind,string &s,vector<vector<string>> &ans,vector<string> &path){
           if(ind>=s.size()){
             ans.push_back(path);
             return;
           }

           for(int i = ind;i<s.size();i++){
            if(isPal(ind,s,i)){
                path.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,ans,path);
                  path.pop_back();

            }

           }

            
        }

};