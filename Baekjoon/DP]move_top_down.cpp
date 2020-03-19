//baekjoon 11048
//이동하기

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m;
int candy[1001][1001];
int d[1001][1001];

int go(int i , int j){
    if(i == 1 && j == 1) return candy[i][j];
    if(i == 0 || j == 0) return 0;
    if(d[i][j] != -1){
        return d[i][j];
    }
    d[i][j] = max(go(i, j-1), go(i-1, j)) + candy[i][j];
    return d[i][j];
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(d, -1, sizeof(d));
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>candy[i][j];
        }
    }
    cout<<go(n, m)<<"\n";

    return 0;

}