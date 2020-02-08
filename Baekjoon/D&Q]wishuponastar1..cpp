//baekjoon 2448
//별찍기 11
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool board[10000][10000];

void draw(int y, int x, bool star){
    if(!star) return;
    board[y][x] = true;
    board[y+1][x-1] =  true;
    board[y+1][x+1]= true;
    board[y+2][x-2]= true;
    board[y+2][x-1] =true;
    board[y+2][x] =true;
    board[y+2][x+1] =true;
    board[y+2][x+2] =true;
}

void solve(int y, int x, int size, bool star){
    if(size == 3){
        draw(y, x, star);
        return;
    }
    solve(y, x, size/2, star);
    solve(y+size/2, x-size/2, size/2, star);
    solve(y+size/2, x+size/2, size/2, star);
    
    return;
}



int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	solve(0, n-1, n, true);
	for(int i = 0;i<(2*n);i++){
	    for(int j = 0;j<(2*n);j++){
	        if(board[i][j]) cout<<"*";
	        else{
	            cout<<" ";
	        }
	    }	
	    cout<<"\n";
	}
    return 0;
}