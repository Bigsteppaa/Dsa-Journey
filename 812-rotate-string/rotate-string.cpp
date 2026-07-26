class Solution {
public:
    bool rotateString(string s, string goal) {


        for(int i = 0;i<s.size();i++){
                 int flag = 1;
                 int k = 0;
            for(int j = 0;j<s.size();j++){

                if(s[(i+j)%s.size()] != goal[k]) flag = 0;
                k++;

            }
            if(flag) return true;

        }
        return false;
    }
};