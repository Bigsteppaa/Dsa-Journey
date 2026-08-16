 
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

       int sizee(int n){
        return size[n];
       }



     };




class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        Dsu ds(n*n+1);


           
            int drow[] = {-1,0,+1,0};
           int dcol[] = {0,-1,0,+1};
        for(int k = 0;k<grid.size();k++){
            for(int j = 0;j<grid.size();j++){

                if(grid[k][j]){
                   
                
                  for(int i = 0;i<4;i++){
                      int nr =  k + drow[i];
                      int nc =  j + dcol[i];
                      if(nr>=0 && nr<n && nc<n && nc >= 0 && grid[nr][nc]){
                        int num =  nr*n+nc;
                         int curr = k*n+j;
                         
                        if(ds.ult_p(curr) != ds.ult_p(num)){
                            ds.uni(curr,num);
                            
                        }     
           }


          }
                }
            }
         }

           int size = ds.sizee(ds.ult_p(0));

          for(int k = 0;k<grid.size();k++){
            for(int j = 0;j<grid.size();j++){

                if(!grid[k][j]){
                   
                  int tempsize = 1;
                  unordered_set<int> st;
                  for(int i = 0;i<4;i++){
                      int nr =  k + drow[i];
                      int nc =  j + dcol[i];
                      if(nr>=0 && nr<n && nc<n && nc >= 0 && grid[nr][nc]){
                        int num =  ds.ult_p(nr*n+nc);
                        if(st.find(num) == st.end()){
                            tempsize+= ds.sizee(num);
                            st.insert(num); 
                        }              
           }


          }
          size = max(size,tempsize);
                }
            }
         }












    return size;    
    }
};