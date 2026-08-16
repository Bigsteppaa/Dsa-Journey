
class Dsu{

public:
    vector<int> size,parent;
    Dsu(int n){

 size.resize(n,1);
 parent.resize(n);
 for(int i = 0;i<n;i++){
    parent[i] = i;
 }
    }

    public: int ult_p(int node){

        if(node == parent[node]) return node;
        return parent[node] = ult_p(parent[node]);
    }

    public : void uni(int a,int b){
      int ult_a = ult_p(a);
      int ult_b = ult_p(b);

      if(ult_a == ult_b) return;
      
      if(size[ult_a] > size[ult_b]){
        parent[ult_b] = ult_a;
        size[ult_a] += size[ult_b];

      }
      else{
        parent[ult_a] = ult_b;
        size[ult_b] += size[ult_a];

      }



    }



 };
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
         Dsu ds(n);

        unordered_map<string,int> mp;

        for(int i = 0;i<n;i++){

        for(int j = 1;j<accounts[i].size();j++){
            string ac = accounts[i][j];
           if(mp.find(ac) == mp.end()){
            mp[ac] = i;
           }
           else{
               ds.uni(i,mp[ac]);}
        }
        }
       
      vector<vector<string>> mail(n);
       for(auto it : mp){

       string str = it.first;
       int node = ds.ult_p(it.second);
       mail[node].push_back(str);
     
       }


       vector<vector<string>> ans;
       for(int i = 0;i<n;i++){
        if(!mail[i].size()) continue;
        sort(mail[i].begin(),mail[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for(auto it : mail[i]){
             temp.push_back(it);   
        }

      ans.push_back(temp);
       }







    return ans;    
    }
};