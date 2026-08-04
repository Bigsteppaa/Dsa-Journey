class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
         if(nums.size() == 1) return nums;
        int minn = INT_MAX;
        int maxx = 0;
         unordered_set<int> st;
         vector<int> ans;
         for(int i = 0;i<nums.size();i++){
              maxx = max(maxx,nums[i]);
              minn = min(minn,nums[i]);
              st.insert(nums[i]); 

         }
             for(int i = minn+1;i<maxx;i++){
                if(!st.count(i)) ans.push_back(i);
             }

        return ans;
    }
};