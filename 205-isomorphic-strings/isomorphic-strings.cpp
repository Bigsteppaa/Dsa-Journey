class Solution {
public:
    bool isIsomorphic(string s, string t) {
          
          char mp_s[128] = {0};
          char mp_t[128] = {0};

          for(int i = 0;i<s.size();i++){


          if(mp_s[s[i]] != mp_t[t[i]] ) return false;
          mp_s[s[i]] = mp_t[t[i]] = i+1;



          }

            return true;
    }
};