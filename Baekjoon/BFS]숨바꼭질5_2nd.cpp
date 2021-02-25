//baekjoon 17071
//숨바꼭질 5

#include <iostream>
#include <tuple>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
using namespace std;

int dp[500001][2]; //subin >0, brother<0
int n, k;

int main()
{
    cin >> n >> k;
    if (n == k)
    {
        cout << 0 << "\n";
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));
    dp[n][0] = 0;
    int brother = k;
    int limit = 0;
    while (!q.empty())
    {
        int cur, t;
        tie(cur, t) = q.front();
        q.pop();
        for (int next : {cur + 1, cur - 1, cur * 2})
        {
            if (next >= 0 && next <= 500000)
            {
                if (dp[next][(t + 1) % 2] == -1)
                {
                    dp[next][(t + 1) % 2] = dp[cur][t % 2] + 1;
                    q.push(make_pair(next, t + 1));
                }
            }
        }
    }
    for (int i = 1;; i++)
    {
        brother += i;
        if (brother > 500000)
            break;
        if (dp[brother][i % 2] <= i)
        {
            cout << i << "\n";
            return 0;
        }
    }

    cout << "-1\n";

    return 0;
}