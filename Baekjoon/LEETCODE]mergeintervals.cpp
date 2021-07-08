class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        int begin = 0;
        int end = 0;
        int endvalue = intervals[0][1];
        while(end < intervals.size()){
            if(endvalue >= intervals[end][0]){
                endvalue = max(endvalue, intervals[end][1]);
                end++;
            } else{
                vector<int> next;
                next.push_back(intervals[begin][0]);
                next.push_back(endvalue);
                ret.push_back(next);
                begin = end;
                endvalue = intervals[end][1];
            }
        }
        ret.push_back({intervals[begin][0], endvalue});
        
        return ret;
    }
};