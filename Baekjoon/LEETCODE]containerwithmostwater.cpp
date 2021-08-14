class Solution {
public:
    bool comp(pair<int,int> &a, pair<int,int> &b){
        return a.first> b.second;
    }
    int maxArea(vector<int>& height) {
        vector<pair<int,int>> meaningful_walls;
        int n = height.size();
        meaningful_walls.push_back(make_pair(height[0], 0));
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(auto &a: meaningful_walls){
                if(ans < min(height[i], a.first) * (i - a.second)){
                    ans = min(height[i], a.first) * (i - a.second);
                }
            }
            auto it = lower_bound(meaningful_walls.begin(), meaningful_walls.end(), make_pair(height[i], 0));
            if(it==meaningful_walls.end()){
                meaningful_walls.push_back(make_pair(height[i], i));
            }            
        }

        return ans;
    }
};