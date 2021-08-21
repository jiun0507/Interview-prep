class Solution {
public:
    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};
    int cutOffTree(vector<vector<int>>& forest) {
        int n = forest.size();
        int m = forest[0].size();
        priority_queue<int, vector<int>, greater<int>> trees;
        unordered_map<int, int> treeNum;
        pair<int,int> walks[n][m];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(forest[i][j]>1) trees.push(forest[i][j]);
                walks[i][j] = make_pair(-1, -1);
            }
        }
        int index = 0;
        while(!trees.empty()){
            treeNum[trees.top()] = index++;
            trees.pop();
        }
        queue<tuple<int,int, int>> q;
        
        
        if(treeNum.count(forest[0][0])!=0) cout<<treeNum[forest[0][0]]<<"\n";
        
        
        if(forest[0][0]==1 || (treeNum.count(forest[0][0])!=0 && treeNum[forest[0][0]] > 0)){
            q.push(make_tuple(0, 0, 0));
            walks[0][0] = make_pair(0, 0);
        } else if(forest[0][0]>1){
            q.push(make_tuple(0, 0, treeNum[forest[0][0]]+1));
            walks[0][0] = make_pair(0, treeNum[forest[0][0]]+1);
        }
        
        int max_cut = 0;
        while(!q.empty()){
            auto c = q.front(); q.pop();
            int y = get<0>(c); int x = get<1>(c); int cuts = get<2>(c);
            if(max_cut>cuts) continue;
            else{
                max_cut = cuts;
            }
            if(cuts==treeNum.size()) return walks[y][x].first;
            for(int dir = 0;dir<4;dir++){
                int ny = y + dy[dir]; int nx = x + dx[dir];
                if(ny>=0 && ny < n && nx>=0 && nx < m && forest[ny][nx]!=0){
                    if(forest[ny][nx]>1){
                        if(treeNum[forest[ny][nx]]==cuts){
                            if(walks[ny][nx].first==-1||(walks[ny][nx].second!=-1 && walks[ny][nx].second<cuts+1)){
                                q.push(make_tuple(ny, nx, cuts+1));
                                walks[ny][nx] = make_pair(walks[y][x].first + 1, cuts+1);
                            }
                        } else{
                            if(walks[ny][nx].first==-1||(walks[ny][nx].second!=-1 && walks[ny][nx].second<cuts)){
                                q.push(make_tuple(ny, nx, cuts));
                                walks[ny][nx] = make_pair(walks[y][x].first + 1, cuts);
                            }
                        }
                    }
                    if(forest[ny][nx] == 1){
                        if(walks[ny][nx].first == -1 || (walks[ny][nx].second!=-1 && walks[ny][nx].second<cuts)){
                            q.push(make_tuple(ny, nx, cuts));
                            walks[ny][nx] = make_pair(walks[y][x].first + 1, cuts);
                        }  
                    }
                }
            }
        }
        
        return -1;
        
    }
};