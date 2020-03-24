//baekjoon 1890
//점프
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int board[101][101];
long long d[101][101];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>board[i][j];
            // cout<<board[i][j]<<" ";
        }
        // cout<<"\n";
    }
    d[0][0] = 1;
    
    for(int i = 0;i<n;i++){
        for(int j = 0; j<n;j++){
            if(board[i][j] == 0) continue;
            int newi = i + board[i][j];
            int newj = j + board[i][j];
            if(newi<n) d[newi][j] += d[i][j];
            if(newj<n) d[i][newj] += d[i][j];
        }
    }
    // for(int i = 0;i<n;i++){
    //     for(int j = 0;j<n;j++){
    //         cout<<d[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<d[n-1][n-1]<<"\n";
}
