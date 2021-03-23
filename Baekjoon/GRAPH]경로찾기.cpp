// 11403 경로찾기
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int n;

int edges[101][101];
int d[101][101];
const int inf = 100000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    fill(&d[0][0], &d[100][100]+1, inf);

    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            int buf;
            cin>>buf;
            if(buf==1){
                d[i][j] = 1;
            }
        }
    }
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(d[i][j]>d[i][k]+d[k][j]){
                    d[i][j] = d[i][k]+d[k][j];
                }
            }
        }
    }
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(d[i][j]==inf) d[i][j] = 0;
            else{
                d[i][j] = 1;
            }
            cout<<d[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
