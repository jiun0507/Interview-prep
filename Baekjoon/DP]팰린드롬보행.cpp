// 12950 팰린드롬 보행
// baekjoon
#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int n, m;
int dp[21][21]; // s, e
int edges[21][21];
const int mx = 1000000000;
int check[21][21];

int go(int s, int e)
{
    if (s == e)
        return 0;
    if (edges[s][e] != -1)
        return 1;
    if (check[s][e] == 1)
    {
        return dp[s][e];
    }
    check[s][e] = 1;
    int &ret = dp[s][e];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edges[i][s] != -1 && (edges[i][s] == edges[j][e]))
            {
                if (i == j)
                {
                    ret = 2;
                    return ret;
                }
                int temp = 2 + go(i, j);
                if (ret > temp)
                {
                    ret = temp;
                }
            }
        }
    }
    return ret;
}

int main()
{
    memset(edges, -1, sizeof(edges));
    memset(check, -1, sizeof(check));
    fill(&dp[0][0], &dp[20][20] + 1, mx);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        char c;
        cin >> a >> b >> c;
        edges[a][b] = c - 'a';
        edges[b][a] = c - 'a';
    }
    int ans = go(0, 1);
    if (ans == mx)
    {
        cout << "-1\n";
    }
    else
    {
        cout << ans << "\n";
    }

    return 0;
}
