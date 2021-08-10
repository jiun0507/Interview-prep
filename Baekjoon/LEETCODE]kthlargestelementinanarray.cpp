class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        return nums[k-1];
    }
};class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> lands;
        int dy[4] = {1, -1, 0, 0};
        int dx[4] = {0, 0, 1, -1};
        for(int i = 0;i<n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == '1'){
                    islands++;
                    lands.push(make_pair(i, j));
                    grid[i][j] = '0';
                    while(!lands.empty()){
                        auto cur = lands.front();
                        lands.pop();
                        int y = cur.first;
                        int x = cur.second;
                        for(int k = 0;k<4;k++){
                            int ny = y+dy[k];
                            int nx = x+dx[k];
                            if(ny>=0 && ny<n && nx>=0 && nx<m &&grid[ny][nx] == '1'){
                                grid[ny][nx] ='0';
                                lands.push(make_pair(ny, nx));
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};