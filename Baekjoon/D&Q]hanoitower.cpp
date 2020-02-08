//baekjoon 11729
//하노이 탑 이동
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


void solve(int n, int y, int x){
    int z = 3 - x- y;
    if(n == 0) return;
    solve(n-1,y, z);
    cout<<y+1<<" "<<x+1<<"\n";
    solve(n-1, z, x);
}

int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
    cin>>n;
    cout<<(1<<n)-1<<"\n";
    solve(3, 0, 2);
    // cout<<ans.size()<<"\n";
    
    return 0;
}
