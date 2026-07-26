class Solution {
public:
    int romanToInt(string s) {
        

        

          unordered_map<char,int> mp;
                  mp.insert({'I',1});
                   mp.insert({'V',5});
                    mp.insert({'X',10});
                   mp.insert({'L',50});
                    mp.insert({'C',100});
                     mp.insert({'D',500});
                       mp.insert({'M',1000});

                 int num = mp[s[s.size()-1]];


               for(int i = s.size()-2;i>=0;i--){

                if(mp[s[i+1]]>mp[s[i]]){
                    num -= mp[s[i]];
                }
                else{
                    num += mp[s[i]];
                }




        }
        return num;
    }
};