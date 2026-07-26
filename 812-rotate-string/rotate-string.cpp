class Solution {
public:
    bool rotateString(string s, string goal) {


        for(int i = 0;i<s.size();i++){
                 int flag = 1;
            for(int j = 0;j<s.size();j++){

                if(s[(i+j)%s.size()] != goal[j]) flag = 0;
                

            }
            if(flag) return true;

        }
        return false;
    }
};