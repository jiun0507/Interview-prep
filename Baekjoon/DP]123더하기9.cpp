// 16195 1,2,3 더하기 9
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int p[1001][1001];
int n, m;
const int mod = 1000000009;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    p[0][0] = 1;
    for (int i = 1; i < 1001; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            for (int k = 1; k <= 3; k++)
            {
                if (i - k >= 0)
                {
                    p[i][j] += p[i - k][j - 1];
                    p[i][j] %= mod;
                }
            }
        }
    }
    while (t--)
    {
        cin >> n >> m;
        long long ans = 0;
        for (int i = 0; i <= m; i++)
        {
            ans += p[n][i];
            ans %= mod;
        }
        cout << ans << "\n";
    }
    return 0;
}
