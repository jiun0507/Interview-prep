//baekjoon 11040
//행렬곱셈순서

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int r[501], c[501];
int dp[501][501];

int go(int i, int j)
{
    int &ret = dp[i][j];
    if (ret != -1)
        return ret;
    for (int k = i; k < j; k++)
    {
        int temp = go(i, k) + go(k + 1, j) + r[i] * c[k] * c[j];
        if (ret == -1 || ret > temp)
            ret = temp;
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin >> r[i] >> c[i];
        dp[i][i] = 0;
    }
    cout << go(0, n - 1);

    return 0;
}