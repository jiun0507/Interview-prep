//baekjoon 11060
//점프 점프
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int jump[1001];
int d[1001];

int go(int i){
    // if(i == 1 && j == 1) return candy[i][j];
    if(i > n) return -1;
    if(i == n) return 0;
    if(d[i] != -1){
        return d[i];
    }
    for(int j = 1; j<= jump[i]; j++){
        int temp = go(i + j);
        if(temp == -1) continue;
        if(d[i] == -1 || temp < d[i]){
            d[i] = temp + 1;
        }
    }
    
    return d[i];
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(d, -1, sizeof(d));
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>jump[i];
    }
    cout<<go(1)<<"\n";
    // for(int i = 1;i<=n;i++){
    //     cout<<d[i]<<"\n";
    // }
    // because there is a buffer at row 0 and col 0 there is no need to 
    // take care of exception cases. 
    // for(int i = 1;i<=n;i++){
    //     for(int j = 1;j<=m;j++){
    //         d[i][j] = max(d[i-1][j], d[i][j-1]) + candy[i][j];
    //     }
    // }
    // cout<<d[n][m];
    return 0;

}