class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi = 1;
        int minn = INT_MAX;
        for(auto it : nums) {maxi = max(maxi,it);
        minn = min(minn,it);
        }
        

        
          return gcd(minn,maxi);
    }
};