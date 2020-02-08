//baekjoon 1780
//종이의 개수
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n;
int board[3000][3000];
int cnt[3] = {0};
bool same(int y, int x, int m){
    int val = board[y][x];
    for(int i = y;i<y+m;i++){
        for(int j = x;j<x+m;j++){
            if(val != board[i][j]) return false;
        }
    }
    return true;
}
void solve(int y, int x, int m){
    if(same(y, x, m)){
        cnt[board[y][x]+1] +=1;
        return;
    }
    int divi = m/3;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            solve(y + i*divi, x + j*divi, divi);
        }
    }
    
}

int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    cin>>n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>board[i][j];
        }
    }
    solve(0, 0, n);
    for(int i =0 ;i<3;i++){
        cout<<cnt[i]<<"\n";
    }
    
    return 0;
}