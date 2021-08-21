class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        struct myComp{
            bool operator()(pair<int,int>& a, pair<int,int> &b){
                return (a.first*a.first) + (a.second*a.second)<(b.first*b.first) + (b.second*b.second);
            }  
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, myComp> min_heap;
        for(int i = 0;i<points.size();i++){
            min_heap.push(make_pair(points[i][0], points[i][1]));
            if(min_heap.size() > k) min_heap.pop();
        }
        vector<vector<int>> ans;
        while(!min_heap.empty()){
            ans.push_back(vector<int>{min_heap.top().first, min_heap.top().second});
            min_heap.pop();
        }
        return ans;
    }
};