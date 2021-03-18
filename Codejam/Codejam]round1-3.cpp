#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int t;
    cin>>t;
    int ind = 1;
    while(t--){
        cout<<"Case #"<<ind++<<": ";
        int n, m;
        cin>>n>>m;
        int board[n][m];
        vector<map<int, int>> rows(n);
        vector<map<int, int>> cols(m);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>board[i][j];
                rows[i][j] = board[i][j];
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                cols[i][j] = board[j][i];
            }
        }
        queue<pair<int,int>> q;
        long long total = 0;
        while(true){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<m;j++){
                    if(board[i][j]==-1) continue;
                    total += (long long) board[i][j];
                    int cur = board[i][j];
                    auto r_map = rows[i].find(j);
                    auto c_map = cols[j].find(i);
                    int cnt = 0;
                    int sum = 0;
                    if(r_map!=rows[i].begin()){
                        cnt++;
                        r_map--;
                        sum += r_map->second;
                        r_map++;
                    }
                    if(r_map!=--rows[i].end()){
                        cnt++;
                        r_map++;
                        sum += r_map->second;
                        r_map--;
                    }
                    if(c_map!=cols[j].begin()){
                        cnt++;
                        c_map--;
                        sum += c_map->second;
                        c_map++;
                    }
                    if(c_map!=--cols[j].end()){
                        cnt++;
                        c_map++;
                        sum += c_map->second;
                        c_map--;
                    }
                    if(cnt!=0 && sum>cnt*cur){
                        // cout<<i<<" "<<j<<" "<<sum<<" "<<cnt<<"\n";
                        q.push(make_pair(i, j));
                    }
                }
            }
            if(q.empty()){
                break;
            }
            while(!q.empty()){
                auto p = q.front();
                board[p.first][p.second] = -1;
                rows[p.first].erase(p.second);
                cols[p.second].erase(p.first);
                q.pop();
            }
        }
        cout<<total<<"\n";
        rows.clear();
        cols.clear();
    }

    return 0;
}
