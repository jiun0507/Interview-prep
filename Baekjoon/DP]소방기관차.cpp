//baekjoon 2616
//소방기관차

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m;
int passenger[50001];
int d[50001][4];
int cumulation[50001];

int sum(int i, int j){
    int ans = cumulation[j-1];
    if(i!=0){
        ans -= cumulation[i-1];
    }
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>passenger[i];
        cumulation[i] = passenger[i];
        if(i!=0) cumulation[i] += cumulation[i-1];
        // cout<<passenger[i]<<" ";
    }
    cin>>m;
    // cout<<"\n";
    memset(d, -1, sizeof(d));
    for(int i = 0;i<n;i++) d[i][0] = 0;
    for(int j = 1;j<=3;j++){
        for(int i = m*j;i<=n;i++){
            d[i][j] = d[i-1][j];
            d[i][j] = max(d[i][j], d[i-m][j-1] + sum(i-m, i));
        }
    }

    // for(int j = 0;j<4;j++){
    //     for(int i = 0;i<=n;i++){
    //         cout<<d[i][j]<<" ";
    //     }        
    //     cout<<"\n";
    // }
    cout<<d[n][3];

    return 0;
}
