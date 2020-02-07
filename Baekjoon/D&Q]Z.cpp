//baekjoon 1074
//Z
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
int r, c;
void solve(int n, int y, int x){
    if(y == r && x == c){
        cout<<cnt<<"\n";
        return;
    }
    if(r<y || r>= y+n || c<x || c>= x+n){
        cnt += n*n;
        return;
    }
    solve(n/2, y, x);
    solve(n/2, y, x+n/2);  
    solve(n/2, y + n/2, x);
    solve(n/2, y + n/2, x+ n/2);
    
}

int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
    cin>>r>>c;
    solve((1<<n), 0, 0);
    
    return 0;
}