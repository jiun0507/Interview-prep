// 11780 플로이드 2
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int n, m;

int path[101][101];
int d[101][101];
const int inf = 100000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    memset(path, -1, sizeof(path));
    fill(&d[0][0], &d[100][100]+1, inf);

    for(int i =0;i<m;i++){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        int buf;
        cin>>buf;
        if(d[a][b]>buf){
            d[a][b] = buf;
            path[a][b] = a;
        }
    }
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(d[i][j]>d[i][k]+d[k][j]){
                    d[i][j] = d[i][k]+d[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(d[i][j]==inf) d[i][j] = 0;
            else if(i==j) d[i][j] = 0;
            cout<<d[i][j]<<" ";
        }
        cout<<"\n";
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(path[i][j]==-1){
                cout<<0<<"\n";
                continue;
            }
            vector<int> paths;
            int from, to;
            from = i;
            to = j;
            while(from!=to){
                paths.push_back(to);
                to = path[from][to];
                if(from==to){
                    paths.push_back(from);
                }
            }
            reverse(paths.begin(), paths.end());
            cout<<paths.size()<<" ";
            for(auto block:paths) cout<<block+1<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
