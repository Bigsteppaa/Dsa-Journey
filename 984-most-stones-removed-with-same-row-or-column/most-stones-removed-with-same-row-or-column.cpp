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
    int removeStones(vector<vector<int>>& stones) {


        int mac = 0;
        int mar = 0;
        for(auto it : stones){
            mar = max(mar,it[0]);
            mac = max(mac,it[1]);

        }
        Dsu ds(mac + mar + 2);

        unordered_map<int,int> ustone;

        for(auto it : stones){
              if(ds.ult_p(it[0]) != ds.ult_p(it[1]+mar+1)){
                  ds.uni(it[0],it[1]+mar+1);
                  ustone[it[0]] = 1;
                  ustone[it[1]+mar+1] = 1;

              } }
              int cnt = 0;
                 for(auto it : ustone){
                    if(ds.ult_p(it.first) == it.first) cnt++;
                 }

        
     return stones.size()-cnt;   
    }
};