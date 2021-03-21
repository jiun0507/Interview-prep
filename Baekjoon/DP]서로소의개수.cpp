// 1750 서로소의 개수
// baekjoon
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[101][100001];
long long mod = 10000003;
long long numbers[101];


long long gcd(long long x, long long y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}
int main()
{
    cin >> n;
    long long mx = 0;
    for(int i = 0;i<n;i++){
        cin>>numbers[i];
        dp[i][numbers[i]] = 1;
        if(mx<numbers[i]) mx = numbers[i];
    }
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<=mx;j++){
            if(dp[i][j]>0){
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= mod;
                long long lcd = gcd(j, numbers[i+1]);
                dp[i+1][lcd] = dp[i+1][lcd]+dp[i][j];
                dp[i+1][lcd] %= mod;
            }
        }
    }
    cout<<dp[n-1][1]<<"\n";
    return 0;
}
