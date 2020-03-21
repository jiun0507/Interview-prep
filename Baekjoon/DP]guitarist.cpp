//baekjoon 1495
//기타리스트

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, s, m;
int volumes[101];
int d[101][1001];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>s>>m;
    for(int i = 1 ;i<=n;i++){
        cin>>volumes[i];
    }
    d[0][s] = 1;
    for(int i=1;i<=n;i++){
        for(int j = 0;j<=m;j++){
            if(j+volumes[i]<=m) d[i][j] = d[i-1][j+volumes[i]];
            if(j-volumes[i]>=0) d[i][j] = max(d[i][j], d[i-1][j-volumes[i]]);
        }
    }
    int ans = -1;
    for(int j = 0;j<=m;j++){
        // cout<<d[n][j]<<" ";
        if(d[n][j] == 1) ans = j;
    }
    if(ans == -1) cout<<"-1\n";
    else{
        cout<<ans<<"\n";
    }
    return 0;

}