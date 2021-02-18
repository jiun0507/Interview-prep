// 1328 고층빌딩
// baekjoon
// top down

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

long long p[101][101][101];
int n, l, r;
const long long mod = 1000000007;

long long skyline(int num, int left, int right)
{
    if (right == 0 || left == 0 || num == 0)
        return 0;
    if (p[num][left][right] != -1)
        return p[num][left][right];
    long long ans = skyline(num - 1, left - 1, right) + skyline(num - 1, left, right - 1) + skyline(num - 1, left, right) * (num - 2);
    return p[num][left][right] = ans % mod;
}

int main()
{
    memset(p, -1, sizeof(p));
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> l >> r;
    p[1][1][1] = 1LL;

    cout << skyline(n, l, r) << endl;
    return 0;
}
