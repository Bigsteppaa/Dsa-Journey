class Solution {
public:
    string frequencySort(string s) {

        unordered_map <char,int> mp;
        for(auto it : s) mp[it]++;

        vector<pair<char,int>> freq;

        for(auto [ch,fq] : mp)freq.push_back({ch,fq});

        auto cmp = [&](pair<char,int>&a,pair<char,int>&b){
            return a.second>b.second;
        };
        sort(freq.begin(),freq.end(),cmp);

        string ans = "";
            for(auto [ch,fq] : freq) ans.append(fq,ch);


        
return ans;    }
};