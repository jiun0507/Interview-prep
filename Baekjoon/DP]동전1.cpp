//baekjoon 2293
//동전1

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, k;
int coins[101];
int dp[10001] = {0};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    dp[0] = 1;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < k; i++)
        {
            if (dp[i] != 0)
            {
                if (i + coins[j] <= k)
                {
                    dp[i + coins[j]] += dp[i];
                }
            }
        }
    }
    cout << dp[k] << endl;

    return 0;
}