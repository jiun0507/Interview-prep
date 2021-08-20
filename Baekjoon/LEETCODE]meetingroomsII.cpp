class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        queue<pair<int,int>> q;
        struct myComp{
            bool operator()(vector<int>& a, vector<int>&b){
                if(a[0] == b[0]){
                    return a[1]>b[1];
                }
                return a[0] < b[0];
            }  
        };
        sort(intervals.begin(), intervals.end(), myComp());
        for(int i = 0;i<intervals.size();i++){
            q.push(make_pair(intervals[i][0], intervals[i][1]));
        }
        int rooms = 0;

        while(true){
            queue<pair<int,int>> newq;
            int prev_end = -1; 
            while(!q.empty()){
                auto cur = q.front(); q.pop();
                if(prev_end > cur.first){
                    newq.push(cur);
                }
                else{
                    prev_end = cur.second;
                }
            }      
            q = newq;
            rooms++;
            if(q.empty()) break;
        }
        return rooms;

    }
};