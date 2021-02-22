// 1234 크리스마스 트리
// baekjoon
// top down approach.

#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

long long dp[12][101][101][101];
long long Combination[51][51] = {};
int n, red, blue, green;

long long go(int level, int a, int b, int c)
{
    // a, b, c를 앞에서 확인해줘서 if구문을 대폭 줄였다.
    if (a < 0 || b < 0 || c < 0)
        return 0;
    if (level == 0)
        return 1;
    if (dp[level][a][b][c] != -1)
        return dp[level][a][b][c];
    long long &ret = dp[level][a][b][c];
    ret = 0;
    ret += go(level - 1, a - level, b, c) + go(level - 1, a, b - level, c) + go(level - 1, a, b, c - level);
    if (level % 2 == 0)
    {
        int two = level / 2;
        long long val = Combination[level][two];
        val *= go(level - 1, a - two, b - two, c) + go(level - 1, a - two, b, c - two) + go(level - 1, a, b - two, c - two);
        ret += val;
    }
    if (level % 3 == 0)
    {
        int three = level / 3;
        long long val = Combination[level][three] * Combination[level - three][three];
        val *= go(level - 1, a - three, b - three, c - three);
        ret += val;
    }
    return ret;
}

int main()
{
    Combination[1][0] = 1;
    Combination[1][1] = 1;
    memset(dp, -1, sizeof(dp));
    for (int i = 2; i <= 20; i++)
    {
        Combination[i][0] = 1;
        for (int j = 1; j <= 20; j++)
        {
            Combination[i][j] = Combination[i - 1][j - 1] + Combination[i - 1][j];
        }
    }
    cin >> n >> red >> blue >> green;

    cout << go(n, red, blue, green) << "\n";
    return 0;
}
