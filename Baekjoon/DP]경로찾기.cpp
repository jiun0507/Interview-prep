//baekjoon 
//1513 건배

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m, c;
int board[51][51];
int dp[51][51][51][51]; // y, x, number of playstations visited, last playstation
int mod = 1000007;

int go(int i, int j, int num_play, int last_play){
    if(i>n||j>m) return 0;
    if(i==n&&j==m){
        if(num_play==c) return 1;
        else{
            return 0;
        }
    }
    int &ans = dp[i][j][num_play][last_play];

    if(ans != -1){
        return ans;
    }
    ans = 0;
    if((i<n)&&(board[i+1][j]==0 || board[i+1][j]>last_play)){
        if(board[i+1][j]==0){
            ans += go(i+1, j, num_play, last_play);
            ans %= mod;
        } else{
            ans += go(i+1, j, num_play+1, board[i+1][j]);
            ans %= mod;
        }
    }
    if((j<m)&&(board[i][j+1]==0 || board[i][j+1]>last_play)){
        if(board[i][j+1]==0){
            ans += go(i, j+1, num_play, last_play);
            ans %= mod;
        } else{
            ans += go(i, j+1, num_play+1, board[i][j+1]);
            ans %= mod;
        } 
    }
    
    return ans;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>c;
    for(int i = 0;i<c;i++){
        int y, x;
        cin>>y>>x;
        board[y][x] = i+1;
    }

    memset(dp, -1, sizeof(dp));
    int ind = 0;
    int num = 0;
    if(board[1][1]>0){
        ind = board[1][1];
        num = 1;
    }
    vector<int> ans;
    for(int i = 0;i<=c;i++){
        ans.push_back(go(1, 1, i+num, ind));
    }
    reverse(ans.begin(), ans.end());
    for(auto a:ans){
        cout<<a<<" ";
    }
    cout<<"\n";
    return 0;
}
