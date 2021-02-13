// 4811 알약
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

long long p[31][31]; // undivided, divided
// p[i][j] = p[i-1][j+1] + p[i][j-1]
// p[0][i] = 1 => 남은게 반쪽 알밖에 없으면 1가지 방법밖에 없다.

long long topdown(int f, int h)
{
    if (p[f][h] != -1)
        return p[f][h];
    if (f == 0)
        return 1;
    if (h == 0)
    {
        return p[f][h] = topdown(f - 1, h + 1);
    }
    return p[f][h] = topdown(f - 1, h + 1) + topdown(f, h - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i <= 30; i++)
    {
        p[0][i] = 1;
    }
    for (int i = 1; i <= 30; i++)
    {
        for (int j = 0; j <= 30; j++)
        {
            p[i][j] = p[i - 1][j + 1];
            if (j != 0)
            {
                p[i][j] += p[i][j - 1];
            }
        }
    }
    int query;
    while (true)
    {
        cin >> query;
        if (query == 0)
            break;
        cout << p[query][0] << "\n";
    }

    return 0;
}
