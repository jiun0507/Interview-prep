//baekjoon 11058
//크리보드

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[10001];

long long go(int goal)
{
    long long &ret = dp[goal];
    if (ret != -1)
        return ret;
    ret = go(goal - 1) + 1;
    for (int i = 1; i < goal - 2; i++)
    {
        long long ans = go(i) * (goal - i - 2 + 1);
        if (ret < ans)
            ret = ans;
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    dp[0] = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= 3; i++)
        dp[i] = i;
    cout << go(n) << endl;
    return 0;
}