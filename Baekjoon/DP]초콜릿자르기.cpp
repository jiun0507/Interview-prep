//baekjoon 2163
//초콜릿 자르기

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m;
int d[301][301];

int go(int i, int j)
{
    if (i == 0 || j == 0)
        return 0;
    if (i == 1 && j == 1)
    {
        return 0;
    }
    int &ans = d[i][j];
    if (ans != -1)
    {
        return ans;
    }
    for (int k = 1; k < i; k++)
    {
        int temp = 1 + go(k, j) + go(i - k, j);
        if (ans == -1 || temp < ans)
            ans = temp;
    }
    for (int k = 1; k < j; k++)
    {
        int temp = 1 + go(i, k) + go(i, j - k);
        if (ans == -1 || temp < ans)
            ans = temp;
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(d, -1, sizeof(d));
    cin >> n >> m;
    cout << go(n, m) << "\n";

    return 0;
}
