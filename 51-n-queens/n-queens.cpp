class Solution {


    


public: void rec(int col ,vector<vector<string>> &ans,vector<string> &board,vector<int> &leftrow,vector<int> &lowdig,vector<int> &updig ){

  if(col == board.size()){
     ans.push_back(board);
     return;
  }

  for(int row = 0;row<board.size();row++){
        if( leftrow[row] != 1 && lowdig[row+col] != 1
        && updig[board.size()-1+col-row] != 1){
            board[row][col] = 'Q';
            leftrow[row]  = 1;
            lowdig[row+col] = 1;
           updig[board.size()-1+col-row] = 1;


            rec(col+1,ans,board,leftrow,lowdig,updig);
            board[row][col] = '.';
            leftrow[row]  = 0;
            lowdig[row+col] = 0;
           updig[board.size()-1+col-row] = 0;


        }
   


  }



}



public:
    vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
     vector<string> board(n);
     string s(n,'.');
     for(int i = 0;i<n;i++) board[i] = s;
       vector<int> leftrow(n,0),lowdig(2*n-1,0),updig(2*n-1,0);
       rec(0,ans,board,leftrow,lowdig,updig);


      return ans;

    }
};