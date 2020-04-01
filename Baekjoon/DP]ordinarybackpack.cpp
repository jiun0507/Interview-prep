//baekjoon 12865
//평범한 배낭
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, k;
int weights[101], values[101];
int d[101][100001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> weights[i] >> values[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            d[i][j] = d[i - 1][j];
            if (j - weights[i] >= 0)
            {
                d[i][j] = max(d[i][j], d[i - 1][j - weights[i]] + values[i]);
            }
        }
    }

    cout << d[n][k] << "\n";

    return 0;
}