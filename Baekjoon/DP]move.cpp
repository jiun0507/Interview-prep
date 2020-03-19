//baekjoon 11048
//이동하기
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m;
int candy[1000][1000];
int d[1000][1000];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>candy[i][j];
            d[i][j] = candy[i][j];
        }
    }

    for(int i = 1;i<m;i++){
        d[0][i] += d[0][i-1];
        // cout<<d[0][i]<<" ";
    }
    for(int i = 1;i<n;i++){
        d[i][0] += d[i-1][0];
        // cout<<d[i][0]<<" ";
    }
    for(int i = 1;i<n;i++){
        for(int j = 1;j<m;j++){
            d[i][j] += max(d[i-1][j], d[i][j-1]);
            // cout<<d[i][j]<<" ";
        }
        // cout<<"\n";
    }
    cout<<d[n-1][m-1];
    return 0;

}