class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cm);

        int cnt = 1;
       int ls = intervals[0][1];
        for(int i = 1;i<intervals.size();i++){

         if(ls<=intervals[i][0]){

            cnt++;
            ls = intervals[i][1];
         }



        }



return intervals.size()-cnt;
        
    }


    static bool cm(const vector<int>& a, const vector<int>& b){

         return a[1]<b[1];

    }
};