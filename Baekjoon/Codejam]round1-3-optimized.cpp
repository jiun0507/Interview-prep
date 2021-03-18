// incomplete
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
long long board[100001];
long long dp[100001];

int main()
{
    int t;
    cin>>t;
    int ind = 1;
    while(t--){
        cout<<"Case #"<<ind++<<": ";
        int n, m;
        cin>>n>>m;
        memset(dp, -1, sizeof(dp));
        vector<map<int, long long>> rows(n);
        vector<map<int, long long>> cols(m);
        queue<pair<int,int>> q;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>board[i*n+j];
                rows[i][j] = board[i*n+j];
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                cols[i][j] = board[j+i*n];
            }
        }
        queue<pair<int,int>> erase_q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                long long cur = board[i*n+j];
                int cnt = 0;
                long long sum = 0;
                if(i<n-1){
                    sum += board[(i+1)*n+j]; cnt++;
                }
                if(j<m-1){
                    sum += board[i*n+j+1]; cnt++;
                }
                if(i>0){
                    sum += board[(i-1)*n+j]; cnt++;
                }
                if(j>0){
                    sum += board[i*n+j-1];
                    cnt++;
                }
                // cout<<i<<" "<<j<<" "<<cur<<" "<<cnt<<" "<<sum<<'\n';
                if(cnt != 0 && sum > cur*cnt){
                    // cout<<"yes\n";
                    dp[i*n+j] = 1;
                    q.push(make_pair(i, j));
                    erase_q.push(make_pair(i, j));
                }
            }
        }

        long long mx = 0;
        while(!q.empty()){
            auto p = q.front(); q.pop();
            // cout<<p.first<<" "<<p.second<<"\n";
            long long cur_time = dp[p.first * n + p.second];
            int ny[4] = {-1, -1, -1, -1};
            int nx[4] = {-1, -1, -1, -1};
            if(mx<cur_time+1){
                mx = cur_time+1;
                while(!erase_q.empty()){
                    auto e = erase_q.front(); erase_q.pop();
                    rows[e.first].erase(e.second);
                    cols[e.second].erase(e.first);
                }
            }
            for(int i = 0;i<4;i++){
                int y = p.first;
                int x = p.second;
                while(true){
                    y+=dy[i];
                    x+=dx[i];
                    if(y>=0&&y<n&&x>=0&&x<m){
                        if(dp[y*n+x]==-1){
                            ny[i] = y;
                            nx[i] = x;
                            break;
                        }
                    } else{
                        break;
                    }
                }
            }

            for(int i = 0;i<4;i++){
                int y = ny[i];
                int x = nx[i];
                if(y==-1||x==-1) continue;
                auto r_map = rows[y].find(x);
                auto c_map = cols[x].find(y);
                long long cnt = 0;
                long long sum = 0;
                if(r_map!=rows[y].begin()){
                    cnt++;
                    r_map--;
                    sum += r_map->second;
                    r_map++;
                }
                if(r_map!=--rows[y].end()){
                    cnt++;
                    r_map++;
                    sum += r_map->second;
                    r_map--;
                }
                if(c_map!=cols[x].begin()){
                    cnt++;
                    c_map--;
                    sum += c_map->second;
                    c_map++;
                }
                if(c_map!=--cols[x].end()){
                    cnt++;
                    c_map++;
                    sum += c_map->second;
                    c_map--;
                }
                // cout<<y<<" "<<x<<" "<<sum<<" "<<cnt<<"\n";
                if(cnt!=0 && sum>cnt*board[y*n+x]){
                    // cout<<y<<" "<<x<<" "<<sum<<" "<<cnt<<"\n";
                    q.push(make_pair(y, x));
                    dp[y*n+x] = cur_time + 1;
                    erase_q.push(make_pair(y, x));
                }
            }
        }
        long long total = 0;
        if(mx==0) mx=1;
        for(int i =0;i<n;i++){

            for(int j = 0;j<m;j++){
                if(dp[i*n+j]==-1) dp[i*n+j] = mx;
                // cout<<dp[i*n+j]<<" ";
                total += dp[i*n+j] * board[i*n+j];
            }
            // cout<<"\n";
        }
        cout<<total<<"\n";
    }

    return 0;
}
