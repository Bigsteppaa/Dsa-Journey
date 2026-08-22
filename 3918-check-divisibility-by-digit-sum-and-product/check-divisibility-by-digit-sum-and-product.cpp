class Solution {
public:
    bool checkDivisibility(int n) {
    int org = n;

        int sum = 0;
        int mul = 1;

        while(n != 0){
        int rem = n%10;
         sum += rem;
         mul *= rem;
         n /= 10;
        


        }
       return org%(sum+mul) == 0;    
    }
};