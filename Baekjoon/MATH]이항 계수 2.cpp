//baekjoon 11051
//이항 계수 2

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m;
const int mod = 10007;
int d[1001][1001];

int go(int a, int b)
{
    if (a == 0 && b == 0)
        return 1;
    if (d[a][b] != -1)
        return d[a][b];

    if (b == 0)
    {
        return 1;
    }
    else if (b == a)
        return 1;
    d[a][b] = (go(a - 1, b - 1) % mod + go(a - 1, b) % 10007) % 10007;
    return d[a][b];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    memset(d, -1, sizeof(d));
    cout << go(n, m) << "\n";
    return 0;
}
