class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();
        if (n == 1) return 1;

        int ans = n;
        int i = 1;

        while (i < n) {

            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }

            int up = 0;
            while (i < n && ratings[i] > ratings[i - 1]) {
                up++;
                ans += up;
                i++;
            }

            int down = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                down++;
                ans += down;
                i++;
            }

            ans -= min(up, down);
        }

        return ans;
    }
};