//baekjoon 11048
//이동하기
//baekjoon 13505
//두 수 XOR
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m;
int candy[1001][1001];
int d[1001][1001];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>candy[i][j];
        }
    }
    // because there is a buffer at row 0 and col 0 there is no need to 
    // take care of exception cases. 
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            d[i][j] = max(d[i-1][j], d[i][j-1]) + candy[i][j];
        }
    }
    cout<<d[n][m];
    return 0;

}