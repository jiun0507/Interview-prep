//baekjoon 16938
//캠프준비
//다른 브루트 포스 방식
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int A[15];
int c[15];
int n;
int X, L,R;


int go(int index, int cnt, int sum, int easy, int hard)
    {
    if(index == n){
        if(cnt>=2 && sum>=L && sum <=R && (hard-easy)>=X) return 1;
        return 0;
    }
    int cnt1 = go(index +1, cnt +1, sum +A[index], min(easy, A[index]), max(hard, A[index]));
    int cnt2 = go(index +1, cnt, sum, easy, hard);
    return cnt1+cnt2;
}
int main(void){
    cin>>n>>L>>R>>X;
    for(int i =0 ;i<n;i++){
        cin>>A[i];
    }
    int ans = go(0, 0, 0, INT_MAX, 0);
    cout<<ans<<"\n";
    
}