class Solution {


    public: bool isValid(int row,int col,vector<string> &board){
          int duprow = row;
          int dupcol = col;

              while(row>=0 && col>=0){
          if(board[row][col] == 'Q') return false;
              row--; col--;}

            row =  duprow;
            col = dupcol;

              while(row<board.size() && col>=0){
          if(board[row][col] == 'Q') return false;
              row++; col--;}

              row =  duprow;
            col = dupcol;

              while(row>=0 && col>=0){
          if(board[row][col] == 'Q') return false;
               col--;}
             return true;
    }


public: void rec(int col ,vector<vector<string>> &ans,vector<string> &board ){

  if(col == board.size()){
     ans.push_back(board);
     return;
  }

  for(int row = 0;row<board.size();row++){
        if(isValid(row,col,board)){
            board[row][col] = 'Q';
            rec(col+1,ans,board);
            board[row][col] = '.';

        }
   


  }



}



public:
    vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
     vector<string> board(n);
     string s(n,'.');
     for(int i = 0;i<n;i++) board[i] = s;

       rec(0,ans,board);


      return ans;

    }
};