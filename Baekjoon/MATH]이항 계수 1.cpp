//baekjoon 11050
//이항 계수 1

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m;

int go(int a, int b)
{
    if (a == 0 && b == 0)
        return 1;
    int ans = 0;
    if (b == 0)
    {
        return go(a - 1, b);
    }
    else if (b == a)
        return go(a - 1, b - 1);
    return go(a - 1, b - 1) + go(a - 1, b);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    cout << go(n, m) << "\n";
    return 0;
}
