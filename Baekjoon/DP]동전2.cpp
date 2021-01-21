//baekjoon 2294
//동전2

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, k;
int coins[101];
int dp[10001];
const int MAX = 20000;

int go(int goal)
{
    int &ret = dp[goal];
    if (ret != -1)
        return ret;
    for (int i = 1; i < goal; i++)
    {
        int left = go(i);
        int right = go(goal - i);
        int ans = left + right;
        if (ret == -1)
        {
            if (left == MAX || right == MAX)
            {
                ret = MAX;
                continue;
            }
        }
        if (ret == -1 || ret > ans)
            ret = ans;
    }
    if (ret == -1)
        return MAX;
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        if (coins[i] <= k)
            dp[coins[i]] = 1;
    }
    int ans = go(k);
    if (ans > 10000)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << "\n";
    }
    return 0;
}