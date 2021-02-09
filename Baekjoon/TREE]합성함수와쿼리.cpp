//17435 함성함수와 쿼리
// baekjoon

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

const int MAX = 200001;
int p[MAX][20];
int n, m;

int composite_function(int overlap, int x)
{
    int lg = 1;
    for (lg = 1; (1 << lg) <= overlap; lg++)
        ;
    lg -= 1;
    for (int i = lg; i >= 0; i--)
    {
        if (overlap >= (1 << i))
        {
            x = p[x][i];
            overlap -= (1 << i);
        }
    }
    return x;
}

int composite_function_using_bitmask(int overlap, int x)
{
    for (int i = 0; i < 20; i++)
    {
        if (overlap & (1 << i))
        {
            x = p[x][i];
        }
    }
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> p[i][0];
    }
    for (int i = 1; (1 << i) <= 500001; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            p[j][i] = p[p[j][i - 1]][i - 1];
        }
    }
    int queries;
    cin >> queries;
    for (int i = 0; i < queries; i++)
    {
        int overlap, x;
        cin >> overlap >> x;
        cout << composite_function(overlap, x) << "\n";
    }

    return 0;
}
