//baekjoon 10422
//괄호
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
long long mod = 1000000007LL;
int num[5001];
long long d[5001];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    int mx = 0;
    for(int i =0 ;i<n;i++){
        cin>>num[i];
        if(mx<num[i]) mx = num[i];
    }
    d[2] = 1;
    d[0] = 1;
    for(int i = 4;i<=mx;i+=2){
        for(int j = 2;j<=i;j+=2){
            d[i] += (d[j-2] * d[i-j])%mod;
            d[i] %= mod;
        }
    }
    for(int i = 0;i<n;i++){
        cout<<d[num[i]]<<"\n";
    }
    
    return 0;

}