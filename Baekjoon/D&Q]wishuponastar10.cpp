//baekjoon 2447
//별찍기 10
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool board[50000][50000];

void solve(int y, int x, int size, bool star){
    if(size == 1){
        board[y][x] = star;
        return;
    }
    solve(y, x, size/3, star);
    solve(y, x+size/3, size/3, star);
    solve(y, x+size*2/3, size/3, star);
    solve(y+size/3, x, size/3, star);
    solve(y+size/3, x+size/3, size/3, false);
    solve(y+size/3, x+size*2/3, size/3, star);
    solve(y+size*2/3, x, size/3, star);
    solve(y+size*2/3, x+size/3, size/3, star);
    solve(y+size*2/3, x+size*2/3, size/3, star);
}



int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	solve(0, 0, n, true);
	for(int i = 0;i<n;i++){
	    for(int j = 0;j<n;j++){
	        if(board[i][j]) cout<<"*";
	        else{
	            cout<<" ";
	        }
	    }	
	    cout<<"\n";
	}
    return 0;
}