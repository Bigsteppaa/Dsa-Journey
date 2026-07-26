class Solution {
public:
    int largestInteger(int n, int s) {

        if(s > n*9) return -1;
        if(s == 0) return 0;
        int cnt = 0;
        int num = 0;

        while(s != 0){
               s--;
               cnt++;

            if(cnt == 9){
                num = num*10 + cnt;
                n--;
                cnt = 0;
                
            }   
        }

        if(cnt){ num = num*10 + cnt;
        n--;}
        while(n){
            num = num*10;
                n--;
        }


    return num;
    }
};