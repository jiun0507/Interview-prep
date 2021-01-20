//baekjoon 11066
//파일 합치기
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> file;
vector<int> sum;
int dp[501][501];

int go(int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int range = sum[j];
    if (i - 1 >= 0)
        range -= sum[i - 1];
    int &ret = dp[i][j];
    for (int k = i; k < j; k++)
    {
        int temp = go(i, k) + go(k + 1, j) + range;
        if (ret > temp || ret == -1)
            ret = temp;
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        file.clear();
        sum.clear();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int buf;
            cin >> buf;
            file.push_back(buf);
            sum.push_back(buf);
            if (i > 0)
            {
                sum[i] += sum[i - 1];
            }
        }
        cout << go(0, n - 1) << "\n";
    }

    return 0;
}