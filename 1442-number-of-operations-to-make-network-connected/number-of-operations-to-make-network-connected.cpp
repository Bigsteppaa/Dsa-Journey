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
    int makeConnected(int n, vector<vector<int>>& connections) {

        Dsu ds(n);

        int cab = 0;
        

        for(auto &e : connections){
           if(ds.ult_p(e[0]) != ds.ult_p(e[1])){
            ds.uni(e[0],e[1]);
            
           }
           else{
                  cab++;
           }

        }
       
        int uc = 0;

      for(int i = 0;i<n;i++){
       if(ds.ult_p(i) == i) uc++;
        
      }

     return uc-1<=cab?uc-1 : -1;
        
    }
};