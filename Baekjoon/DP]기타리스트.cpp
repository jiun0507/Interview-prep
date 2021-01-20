// baekjoon 1495
// 기타리스트
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, s, m;
int v[101];
int dp[101][1001] = {0};

void go(int index, int volume)
{
    if (index > n)
        return;
    if (dp[index][volume])
        return;
    if (volume + v[index + 1] <= m)
    {
        go(index + 1, volume + v[index + 1]);
        dp[index + 1][volume + v[index + 1]] = 1;
    }
    if (volume - v[index + 1] >= 0)
    {
        go(index + 1, volume - v[index + 1]);
        dp[index + 1][volume - v[index + 1]] = 1;
    }
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    go(0, s);
    int ans = -1;
    for (int i = 0; i <= m; i++)
    {
        if (dp[n][i] == 1)
            ans = i;
    }
    cout << ans << endl;
    return 0;
}