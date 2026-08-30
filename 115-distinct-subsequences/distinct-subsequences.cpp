class Solution {
public:
    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        const long long LIM = INT_MAX;

        vector<long long> dp(m + 1, 0),curr(m + 1, 0);

           dp[0] = 1;
           curr[0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                if(s[i-1] == t[j-1]) {
                    curr[j] = min(
                        LIM,
                        dp[j-1] + dp[j]
                    );
                }
                else {
                    curr[j] = dp[j];
                }
            }
            dp = curr;
        }

        return dp[m];
    }
};