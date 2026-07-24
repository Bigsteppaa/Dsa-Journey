class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {

        unordered_set<int> st(nums.begin(),nums.end());
           int cnt = 0;
        for(int it : st){

          if(st.count(it+diff) && st.count(it+2*diff)) cnt ++;

        }
      return cnt;  
    }
};