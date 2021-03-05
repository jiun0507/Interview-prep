// 15558 점프 게임
// baekjoon
#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int t, a, b, c;
int dp[201][4001];
const int mod = 1000000;
int cnt[201];

int go(int i, int k)
{
    if (k == 0)
        return 1;
    if (i > 200)
        return 0;
    if (dp[i][k] != -1)
        return dp[i][k];
    int &ans = dp[i][k];
    ans = go(i + 1, k);
    for (int j = 1; j <= cnt[i]; j++)
    {
        if (k >= j)
        {
            ans += go(i + 1, k - j);
            ans %= mod;
        }
    }
    return ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> t >> a >> b >> c;
    for (int i = 0; i < a; i++)
    {
        int num;
        cin >> num;
        cnt[num]++;
    }
    int ret = 0;
    for (int i = b; i <= c; i++)
    {
        ret += go(1, i);
        ret %= mod;
    }
    cout << ret << "\n";
    return 0;
}
