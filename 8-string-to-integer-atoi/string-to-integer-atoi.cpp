class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int minus = 0;
        int i = 0;

       
        while (i < n && s[i] == ' ')
            i++;

        if (i == n) return 0;

       
        if (s[i] == '-') {
            minus = 1;
            i++;
        }
        else if (s[i] == '+') {
            i++;
        }

        
        if (i == n || !isdigit(s[i])) return 0;

        
        while (i < n && s[i] == '0')
            i++;

        long long num = 0;

        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');

            if (!minus && num > INT_MAX)
                return INT_MAX;

            if (minus && -num < INT_MIN)
                return INT_MIN;

            i++;
        }

        if (minus)
            num = -num;

        return (int)num;
    }
};