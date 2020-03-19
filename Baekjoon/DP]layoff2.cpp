//baekjoon 15486
//퇴사 2
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int pay[1500001];
int date[1500001];
int d[1500001];


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // memset(d, 0, sizeof(d));
    cin>>n;
    for(int i = 0 ;i<n;i++){
        cin>>date[i]>>pay[i];
    }
    for(int i = 0; i <n;i++){
        if(i != 0  && d[i] < d[i-1]) d[i] = d[i-1];
        if(i + date[i] > n+1) continue;
        if(d[i+date[i]] < pay[i] + d[i]){
            d[i+date[i]] = pay[i] + d[i];
        }
            
        
    }
    int ans = 0;
    for(int i = 0;i<=n;i++){
        if(ans<d[i]) ans = d[i];
    }
    cout<<ans<<"\n";

    return 0;

}