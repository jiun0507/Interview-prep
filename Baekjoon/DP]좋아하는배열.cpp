//12911 좋아하는 배열
//baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

long long sum[11];
long long dp[11][100001];

vector<int> divisors[100001];
const long long mod = 1000000007LL;
int n, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;

    for (int i = 1; i <= k; i++)
    {
        for (int j = i * 2; j <= k; j += i)
        {
            divisors[j].push_back(i);
        }
    }
    for (int j = 1; j <= k; j++)
    {
        dp[1][j] = 1;
    }
    sum[1] = k;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = sum[i - 1];
            for (auto &divider : divisors[j])
            {
                dp[i][j] -= dp[i - 1][divider];
                dp[i][j] %= mod;
                dp[i][j] += mod;
                dp[i][j] %= mod;
            }
            sum[i] += dp[i][j];
            sum[i] %= mod;
        }
    }
    cout << sum[n] << endl;
    return 0;
}
