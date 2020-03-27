//baekjoon 5557
//1학년
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
long long num[101];
long long d[501][501];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>num[i];
    }
    d[1][num[1]] = 1;
    for(int i = 2;i<n;i++){
        for(int j = 0;j<=20;j++){
            if(j-num[i]>=0 && j - num[i]<=20){
                d[i][j] += d[i-1][j-num[i]];  
                // cout<<d[i][j]<<"\n";
            } 
            if(j+num[i]>=0 && j + num[i]<=20){ 
                d[i][j] += d[i-1][j+num[i]];
                // cout<<d[i][j]<<"\n";
            }
        }
    }
    cout<<d[n-1][num[n]];
    
    return 0;
}
