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

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        struct myCompare{
            bool operator()(vector<int>& a, vector<int>& b){
                if(a[0] == b[0]){
                    return a[1] > b[1];
                }
                return a[0] < b[0];
            }
        };
        sort(intervals.begin(), intervals.end(), myCompare());
       
        vector<vector<int>> ans;
        for(int i =0;i<intervals.size();i++){
            if(i>0 && intervals[i][0] <= ans[ans.size()-1][1]){
                ans[ans.size()-1][1] = max(ans[ans.size()-1][1], intervals[i][1]);
                continue;
            }
            
            ans.push_back(vector<int>{intervals[i][0], intervals[i][1]});
        }
        return ans;
    }
};