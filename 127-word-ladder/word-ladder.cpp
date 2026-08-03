class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {


   unordered_set<string> st(wordList.begin(),wordList.end());

   queue<pair<string,int>> q;
   q.push({beginWord,1});
   


   while(!q.empty()){
        string word = q.front().first;
        int tran = q.front().second;
        q.pop();
        if(word == endWord) return tran;

        for(int i = 0;i<word.size();i++){
            char orignal = word[i];

         for(char ch = 'a'; ch<= 'z';ch++){
            word[i] = ch;
        if(st.find(word) != st.end()){
            q.push({word,tran+1});
            st.erase(word);
        }

            
         }
         word[i] = orignal;




        }
        




   }







   return 0;     
    }
};