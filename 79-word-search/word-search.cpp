class Solution {
 public : bool solve(int row,int col,int ind,vector<vector<char>>& board, string &s){
     char ch = board[row][col] ;
   board[row][col] = '0';
   if(ind == s.size()-1) return true;
     

      int drow[] = {-1,0,+1,0};
      int dcol[] = {0,+1,0,-1};
    
               
              for(int k = 0;k<4;k++){
                int nr = row+drow[k];
                int nc = col+dcol[k];
                if(nr>=0 && nc>=0 && nc<board[0].size() && nr<board.size() && ind<s.size()-1  && board[nr][nc] != '0' &&  board[nr][nc] == s[ind+1]) 
                if(solve(nr,nc,ind+1,board,s)) return true;

              }
      
                 
            board[row][col] = ch;

return  false;

 }



public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0;i<board.size();i++){
    for(int j = 0;j<board[0].size();j++){
        if(board[i][j] == word[0])
         if(solve(i,j,0,board,word)) return true;
    }
    }
    return false;}
};