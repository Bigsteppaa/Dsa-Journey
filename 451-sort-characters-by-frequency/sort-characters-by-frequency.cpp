class Solution {
public:
    string frequencySort(string s) {

        unordered_map <char,int> mp;
        for(auto it : s) mp[it]++;

        vector<vector<char>> freq(s.size()+1);

        for(auto [ch,fq] : mp)freq[fq].push_back(ch);



        string ans = "";

        for(int i = s.size();i>=1;i--)
            for(auto it : freq[i]) ans.append(i,it);


        
    


        
return ans;    }
};