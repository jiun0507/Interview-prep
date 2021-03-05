// 1947 선물전달
// baekjoon
#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

long long n;
long long dp[1000001];
const long long mod = 1000000000;

long long go(long long people){
    if(people == 1) return 0;
    if(people == 2) return 1;
    if(dp[people]!=-1) return dp[people];
    long long &ans = dp[people];
    ans = ((people-1)*((go(people-2)+go(people-1))%mod)%mod);
    return ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    cout<<go(n)<<"\n";
    return 0;
}
