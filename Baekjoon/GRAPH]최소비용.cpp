// 1916 최소비용 구하기
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int n, m;

long long d[1001];
long long edges[1001][1001];
int check[1001];

int main()
{
    memset(d, -1, sizeof(d));
    memset(edges, -1, sizeof(edges));
    memset(check, -1, sizeof(check));
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int from, to;
        long long dist;
        cin >> from >> to >> dist;
        edges[from][to] = dist;
        edges[to][from] = dist;
    }
    int start, end;
    cin >> start >> end;
    d[start] = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        int m = 100000000;
        for (int j = 1; j <= n; j++)
        {
            if (d[j] != 1 && check[j] == -1 && d[j] < m)
            {
                m = d[j];
                x = j;
            }
        }
        cout << x << " ";
        for (int k = 1; k <= n; k++)
        {
            if (edges[x][k] != -1)
            {
                if (d[k] == -1 || (d[k] != -1 && d[k] > m + d[x]))
                {
                    d[k] = m + d[x];
                }
            }
        }
        check[x] = 1;
    }
    cout << d[end] << "\n";
    return 0;
}
